//
// Created by umar on 28/12/20.
//

#include <cstring>
#include <iostream>
#include <sstream>
#include "peer.h"
#include "../messageprocesser.h"


int Peer::Peer::getMPort() const {
    return m_port;
}

void Peer::Peer::setMPort(int mPort) {
    m_port = mPort;
}

const std::string &Peer::Peer::getMPeerName() const {
    return m_peerName;
}

void Peer::Peer::setMPeerName(const std::string &mPeerName) {
    m_peerName = mPeerName;
}

const std::string &Peer::Peer::getMIp() const {
    return m_ip;
}

void Peer::Peer::setMIp(const std::string &mIp) {
    m_ip = mIp;
}

const std::unique_ptr<PeerMessages> &Peer::Peer::getMPeerMessages() const {
    return m_peerMessages;
}

Peer::Peer::Peer(const SocketResource socket) : m_socket{socket} {

    struct sockaddr_in address;
    std::memset(&address, 0, sizeof address);
    socklen_t len = sizeof(address);
    int ret = ::getpeername(socket.resource(), (struct sockaddr *) &address, &len);
    if (ret == -1) {
        //TODO ::THROW ERROR HERE
    }
    m_port = ntohs(address.sin_port);
    m_ip = ::inet_ntoa(address.sin_addr);
    m_peerName = m_ip + std::to_string(m_port);
    m_connected = true;
    m_messageCount = 0;
}

Peer::Peer::~Peer() {
    std::cout << "Peer Destructor called \n";
    m_socket.close();
}

std::vector<std::string> Peer::Peer::read(int length) {
    static std::vector<char> tempRecvBuf(2 * 1000000);
    tempRecvBuf.clear();
    int recv = ::recv(m_socket.resource(), &tempRecvBuf[0], length, MSG_DONTWAIT);
    if (recv == -1) {
#if !defined(_WIN32)
        if (errno == EAGAIN) {
            //it means no message arrived :: OK FINE
            return {};
        } else {
            //TODO:: After Debugging, It is decided that remove case should be here
            std::cout << "Peer with ip = {" << m_ip << "} and port = {" << m_port <<"} is disconnected\n";
            m_connected = false;
            return {};
        }
#else
        if (WSAGetLastError() == WSAECONNRESET) {
//            this->m_master->events()->onPeerDisconnect()->trigger(this);
//            this->m_master->peers()->remove(this);
            return {};
        } else {
            return {};
        }
#endif
    }
    if (recv == 0) {
        m_connected = false;
        return {};
    }
    m_recvBuf += std::string{tempRecvBuf.begin(), tempRecvBuf.begin() + recv};
    // Check if delimiter char exists
    size_t pos = m_recvBuf.find_first_of('\n');
    if (pos == std::string::npos) {
        return {};
    }
    // else delimiter exists, return everything till delimiter
    std::istringstream iss{m_recvBuf};
    std::string peerMsg;
    std::vector<std::string> ret;
    ret.reserve(2);
    while (std::getline(iss, peerMsg)) {
        ret.emplace_back(peerMsg);
    }
    // remove last
    if (ret.size() > 1) {
        ret.pop_back();
        m_recvBuf = peerMsg;
    }
    if (!ret.empty()) {
        for (const auto &itr : ret) {
            std::cout << "recieved Message = " << itr << std::endl;
        }
    }
    return ret;
}

int Peer::Peer::send(const std::string &message) {
    if (message.find('\n') != std::string::npos) {
//        throw PeerException("Invalid message delimiter");
    }
    std::string msgToSend = message + "\n";
#ifdef _WIN32
    /*write can be problematic on windows, using send() here */
    int ret = ::send(m_socket.resource(), msgToSend.c_str(), msgToSend.size(), 0);
#else
    int ret = ::write(m_socket.resource(), msgToSend.c_str(), msgToSend.size());
#endif
    if (ret == -1) {
//        throw PeerException(
//                std::string{"Failed to write to peer "} + m_name + " " + std::strerror(errno) + "\n");
    }
    return ret;
}

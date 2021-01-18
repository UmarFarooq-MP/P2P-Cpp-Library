//
// Created by umar on 28/12/20.
//

#include <cstring>
#include <iostream>
#include "peer.h"


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
}

Peer::Peer::~Peer() {
    std::cout << "Peer Destructor called \n";
    m_socket.close();
}

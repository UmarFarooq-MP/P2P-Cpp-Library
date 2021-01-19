//
// Created by umar on 29/12/20.
//

#include <cstring>
#include <iostream>
#include "peersmanager.h"

void PeersManager::startServer(const std::string &ip, const int port) {

    SocketResource::init();
    m_socket = std::move(SocketResource::create());
    sockaddr_in address;
    std::memset(&address, 0, sizeof address);
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
#ifdef _WIN32
    auto addr = ::inet_addr(ip.c_str());
        if (addr == INADDR_NONE)
            throw P2PSocketException("inet_addr failure: returned INADDR_NONE");
        if (addr == INADDR_ANY)
            throw P2PSocketException("inet_addr failure: returned INADDR_ANY");
        address.sin_addr.s_addr = addr;
#else
    if (::inet_pton(AF_INET, ip.c_str(), &address.sin_addr) <= 0) {/**throw error**/}
#endif
    if (::bind(m_socket->resource(), (struct sockaddr *) &address, sizeof(address)) == -1) {/**throw error**/}
    if (::listen(m_socket->resource(), 10) < 0) {/**throw error**/}
}

void PeersManager::listen(const int remaining) {
    m_socket->setNonBlockingMode();
    for (int i = remaining; i > 0; --i) {
        accept();
    }
    m_socket->setBlockMode();
}

bool PeersManager::connect(const std::string &ip, const int port, const int timeout) {
    if (port < 0x3E8 || port > 0xFFFF) {
//        std::cout << "Invalid remote peer port\n";
        return false;
    }
    auto socket = std::move(SocketResource::create());

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
#ifdef _WIN32
    auto ipAddr = ::inet_addr(remotePeerAddr.c_str());
    if (ipAddr == INADDR_NONE)
        return false;
    if (ipAddr == INADDR_ANY)
        return false;
    addr.sin_addr.s_addr = ipAddr;
#else
    if (::inet_pton(AF_INET, ip.c_str(), &addr.sin_addr) <= 0) {
//        std::cout << "Peers: Invalid IPv4 host address\n";
        return false;
    }
#endif
    if (timeout == 0) {
        if (::connect(socket->resource(), (struct sockaddr *) &addr, sizeof(addr)) != NO_ERROR) {
//            std::cout << "Peer connection to " << remotePeerAddr << " on port " << port << " failed \n";
            return false;
        }
        std::unique_ptr<Peer::Peer> peer = std::make_unique<Peer::Peer>(SocketResource(*socket));
        m_connectedPeer.emplace_back(std::move(peer));
        return true;
    }

    // with timeout
    socket->setNonBlockingMode();
    bool connected = false;
    int maxAttempts = timeout * 100;
    int attempts = 0;
    while (true) {
        if (attempts >= maxAttempts) {
            break;
        }

        ++attempts;
        connected = ::connect(socket->resource(), (struct sockaddr *) &addr, sizeof(addr)) == NO_ERROR;
        if (!connected) {
            if (errno != EINPROGRESS && errno != EALREADY) {
//                std::cout << "Socket connection to " << remotePeerAddr << ":" << port
//                          << " failed, (timeout :" << timeout << ")\n";
            }
            usleep(10000);
        } else {
            std::unique_ptr<Peer::Peer> peer = std::make_unique<Peer::Peer>(
                    SocketResource(*socket));
            m_connectedPeer.emplace_back(std::move(peer));
            return true;
        }
    }
    socket->setBlockMode();
    if (!connected) {
//        std::cout << "Socket connection to " << remotePeerAddr << ":" << port << " timed out\n";
        return false;
    }
    return 0;
}

bool PeersManager::accept() {
    sockaddr_in addr;
#ifdef _WIN32
    int len = sizeof(addr);
#else
    socklen_t len = sizeof(addr);
#endif
    Socket peerSocket = ::accept(m_socket->resource(), (struct sockaddr *) &addr, &len);
    if (peerSocket == INVALID_SOCKET)
        return false;
    std::unique_ptr<Peer::Peer> peer = std::make_unique<Peer::Peer>(SocketResource(peerSocket));
    std::cout << "peer connected with ip = " << peer->getMIp() << " port = " << addr.sin_port << std::endl;
    m_connectedPeer.push_back(std::move(peer));
    return true;
}

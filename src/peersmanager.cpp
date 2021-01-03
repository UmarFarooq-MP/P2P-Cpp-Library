//
// Created by umar on 29/12/20.
//

#include <cstring>
#include "peersmanager.h"

void PeersManager::createServer(const std::string &ip, const int port) {
    SocketResource::init();
    m_socket = SocketResource::create();

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
    if (::bind(m_socket.resource(), (struct sockaddr *) &address, sizeof(address)) == -1) {/**throw error**/}
    if (::listen(m_socket.resource(), 5) < 0) {/**throw error**/}
    sleep(12);
}

void PeersManager::listen() {

}

void PeersManager::connect() {

}

//
// Created by umar on 28/12/20.
//

#include "peer.h"

Peer::Peer::Peer(const std::string &name, const std::string &ip, const int port) :
        m_port(port), m_ip(ip), m_peerName(ip + name) {}

void Peer::Peer::setName(const std::string &name) {
    m_peerName = name;
}

void Peer::Peer::setIP(const std::string &ip) {
    m_ip = ip;
}

void Peer::Peer::setPort(const int port) {
    m_port = port;
}

std::string Peer::Peer::getName() {
    return m_peerName;
}

std::string Peer::Peer::getIP() {
    return m_ip;
}

int Peer::Peer::getPort() {
    return m_port;
}

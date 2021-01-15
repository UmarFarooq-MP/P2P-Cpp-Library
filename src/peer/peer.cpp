//
// Created by umar on 28/12/20.
//

#include "peer.h"

Peer::Peer::Peer(const std::string &name, const std::string &ip, const int port) :
        m_port(port), m_ip(ip), m_peerName(ip + name), m_peerMessages(std::make_unique<PeerMessages>()) {}

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


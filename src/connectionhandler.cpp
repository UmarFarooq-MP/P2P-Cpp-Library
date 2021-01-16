//
// Created by umar on 29/12/20.
//

#include "connectionhandler.h"

bool ConnectionHandler::createServer(const std::string &ip, const int port) {
    return false;
}

void ConnectionHandler::listen() {

}

void ConnectionHandler::connect(const std::string &ip, const int port) {

}

const SocketResource &ConnectionHandler::getMSocket() const {
    return m_socket;
}

void ConnectionHandler::setMSocket(const SocketResource &mSocket) {
    m_socket = mSocket;
}

const PeersManager &ConnectionHandler::getMPeers() const {
    return m_peers;
}


Peer::Peer *ConnectionHandler::getPeer() const {
    return peer;
}

void ConnectionHandler::setPeer(Peer::Peer *peer) {
    ConnectionHandler::peer = peer;
}

//
// Created by umar on 29/12/20.
//

#ifndef P2P_CPP_CONNECTIONHANDLER_H
#define P2P_CPP_CONNECTIONHANDLER_H

#include "socketresource.h"
#include "peersmanager.h"
#include "peer/peer.h"

class ConnectionHandler {
    SocketResource m_socket;
public:
    const SocketResource &getMSocket() const;

    void setMSocket(const SocketResource &mSocket);

    const PeersManager &getMPeers() const;

    void setMPeers(const PeersManager &mPeers);

    Peer::Peer *getPeer() const;

    void setPeer(Peer::Peer *peer);

private:
    PeersManager m_peers;
    Peer::Peer *peer;
public:
    bool createServer(const std::string &ip, const int port);
    void listen();
    void connect(const std::string &ip, const int port);
};


#endif //P2P_CPP_CONNECTIONHANDLER_H

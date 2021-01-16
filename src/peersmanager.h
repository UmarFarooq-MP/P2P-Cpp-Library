//
// Created by umar on 29/12/20.
//

#ifndef P2P_CPP_PEERSMANAGER_H
#define P2P_CPP_PEERSMANAGER_H

#include "peer/peer.h"
#include <unordered_map>
#include "socketresource.h"


class PeersManager {
    /** Master Socket is socket where a peer will listen **/
    std::unique_ptr<SocketResource> m_socket;
    /** If a new Peer arrives create an instance and add in connectedPeers **/
    std::vector<std::unique_ptr<Peer::Peer>> connectedPeer;

public:
    void createServer(const std::string &ip, const int port);

    void listen();

    bool connect(const std::string &ip,const int port);

    bool accept();
};


#endif //P2P_CPP_PEERSMANAGER_H

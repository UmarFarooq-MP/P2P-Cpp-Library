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
    SocketResource m_masterSocket;
    /** If a new Peer arrives create an instance and add in connectedPeers **/
    Peer::Peer *m_peer;
    std::unordered_map<std::string, Peer::Peer> connectedPeers;
public:

};


#endif //P2P_CPP_PEERSMANAGER_H

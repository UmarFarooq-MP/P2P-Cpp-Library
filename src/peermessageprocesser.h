//
// Created by umar on 19/1/21.
//

#ifndef P2P_CPP_PEERMESSAGEPROCESSER_H
#define P2P_CPP_PEERMESSAGEPROCESSER_H
#include <vector>
#include "peer/peer.h"

class PeerMessageProcesser {
    std::vector<std::unique_ptr<Peer::Peer>>::iterator m_connectedPeersIterator;
    PeerMessageProcesser(std::vector<std::unique_ptr<Peer::Peer>> &connectedPeers);
public:
    static PeerMessageProcesser *instance;
    PeerMessageProcesser *getInstance(std::vector<std::unique_ptr<Peer::Peer>> &connectedPeers);
    void updateMessages();
};


#endif //P2P_CPP_PEERMESSAGEPROCESSER_H

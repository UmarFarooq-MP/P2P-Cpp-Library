//
// Created by umar on 19/1/21.
//

#include "peermessageprocesser.h"

PeerMessageProcesser *PeerMessageProcesser::instance = nullptr;

PeerMessageProcesser::PeerMessageProcesser(std::vector<std::unique_ptr<Peer::Peer>> &connectedPeers) {
    m_connectedPeersIterator = connectedPeers.begin();
}

PeerMessageProcesser *PeerMessageProcesser::getInstance(std::vector<std::unique_ptr<Peer::Peer>> &connectedPeers) {
    if (instance == nullptr) {
        instance = new PeerMessageProcesser(connectedPeers);
        return instance;
    }
    return instance;
}

void PeerMessageProcesser::updateMessages() {
    //
}

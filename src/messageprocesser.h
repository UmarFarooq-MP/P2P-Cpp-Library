//
// Created by umar on 19/1/21.
//

#ifndef P2P_CPP_MESSAGEPROCESSER_H
#define P2P_CPP_MESSAGEPROCESSER_H

#include <vector>
#include <algorithm>

#include "peer/peer.h"
#include "mutexlock.h"

namespace MessageProcesser {
    static bool removePeerFromConnected(std::vector<std::unique_ptr<Peer::Peer>> &connectedPeers) {
        while (!MutexLock::getInstance().tryLock()) {
            sleep(2);
        }
        connectedPeers.erase(std::remove_if(
                connectedPeers.begin(), connectedPeers.end(),
                [&connectedPeers](std::unique_ptr<Peer::Peer> &obj) {
                    return !obj->m_connected;
                }), connectedPeers.end());
        MutexLock::getInstance().releaseLock();
        return true;
    }

};


#endif //P2P_CPP_MESSAGEPROCESSER_H

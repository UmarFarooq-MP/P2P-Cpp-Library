//
// Created by umar on 15/1/21.
//

#include "peermessages.h"

PeerMessages::PeerMessages() {
    m_broadcastMessage = std::make_unique<BroadcastMessage>();
    m_localMessages = std::make_unique<LocalMessages>();
}

//
// Created by umar on 15/1/21.
//

#ifndef P2P_CPP_PEERMESSAGES_H
#define P2P_CPP_PEERMESSAGES_H

#include <memory>

#include "broadcastmessage.h"
#include "loclamessages.h"

class PeerMessages {
    std::unique_ptr<BroadcastMessage> m_broadcastMessage;
    std::unique_ptr<LocalMessages> m_localMessages;
public:
    PeerMessages();
};


#endif //P2P_CPP_PEERMESSAGES_H

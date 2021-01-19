//
// Created by umar on 15/1/21.
//

#include "peermessages.h"

void PeerMessages::setMessage(const std::string &message, MESSAGEPRIORITY messagepriority) {
    switch (messagepriority) {
        case MESSAGEPRIORITY::FORGE:
            m_messages.emplace_back(std::to_string(MESSAGEPRIORITY::FORGE) + message);
            break;
        case MESSAGEPRIORITY::TRANSACTION:
            m_messages.emplace_back(std::to_string(MESSAGEPRIORITY::TRANSACTION) + message);
            break;
        default:
            break;
    }
}

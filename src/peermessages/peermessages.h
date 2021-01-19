//
// Created by umar on 15/1/21.
//

#ifndef P2P_CPP_PEERMESSAGES_H
#define P2P_CPP_PEERMESSAGES_H

#include <string>
#include <vector>

enum MESSAGEPRIORITY {
    FORGE,
    TRANSACTION
};

class PeerMessages {
    std::vector<std::string> m_messages;
public:
    PeerMessages() = default;
    void setMessage(const std::string &message, MESSAGEPRIORITY);
};

#endif //P2P_CPP_PEERMESSAGES_H

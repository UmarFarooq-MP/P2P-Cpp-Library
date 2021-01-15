//
// Created by umar on 28/12/20.
//

#ifndef P2P_CPP_PEER_H
#define P2P_CPP_PEER_H

#include <string>
#include "../peermessages/peermessages.h"

namespace Peer {
    class Peer {
        std::string m_peerName;
        std::string m_ip;
        int m_port;
        PeerMessages *m_peerMessages;
    public:
        Peer() = default;

        Peer(PeerMessages *peerMessages, const std::string &name, const std::string &ip, const int port);

        void setName(const std::string &name);

        void setIP(const std::string &ip);

        void setPort(const int port);

        std::string getName();

        std::string getIP();

        int getPort();
    };
}
#endif //P2P_CPP_PEER_H

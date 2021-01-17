//
// Created by umar on 28/12/20.
//

#ifndef P2P_CPP_PEER_H
#define P2P_CPP_PEER_H

#include <memory>
#include <string>
#include "../peermessages/peermessages.h"
#include "../socketresource.h"


namespace Peer {
    class Peer {
        int m_port;
        std::string m_peerName;
        std::string m_ip;
        std::unique_ptr<PeerMessages> m_peerMessages;
    public:

        Peer (const SocketResource socket);

        int getMPort() const;

        void setMPort(int mPort);

        const std::string &getMPeerName() const;

        void setMPeerName(const std::string &mPeerName);

        const std::string &getMIp() const;

        void setMIp(const std::string &mIp);

        const std::unique_ptr<PeerMessages> &getMPeerMessages() const;


    public:
        Peer() = default;

        Peer(const std::string &name, const std::string &ip, const int port);

        void setName(const std::string &name);

        void setIP(const std::string &ip);

        void setPort(const int port);

        std::string getName();

        std::string getIP();

        int getPort();
    };
}
#endif //P2P_CPP_PEER_H

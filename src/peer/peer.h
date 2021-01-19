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
        int m_messageCount;
        std::string m_peerName;
        std::string m_ip;
        std::unique_ptr<PeerMessages> m_peerMessages;
        std::string m_recvBuf;
        SocketResource m_socket;
    public:
        bool m_connected;

        Peer (const SocketResource socket);

        ~Peer();

        int getMPort() const;

        void setMPort(int mPort);

        const std::string &getMPeerName() const;

        void setMPeerName(const std::string &mPeerName);

        const std::string &getMIp() const;

        void setMIp(const std::string &mIp);

        const std::unique_ptr<PeerMessages> &getMPeerMessages() const;

        std::vector<std::string> read(int length);

        int send(const std::string &message);

    };
}
#endif //P2P_CPP_PEER_H

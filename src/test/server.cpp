//
// Created by umar on 17/1/21.
//

#include <iostream>
#include "../peersmanager.h"

int main() {
    PeersManager server;
    server.startServer("127.0.0.1", 8082);
    while (true) {
        server.listen(1);
        std::cout << "size = " << server.m_connectedPeer.size() << std::endl;
        for (const auto &itr:server.m_connectedPeer) {
            itr->read(1024);
            if (itr->m_connected) {
                itr->send("Test Message");
            }
        }
        std::cout << "sleeping \n";
        sleep(5);
    }
}
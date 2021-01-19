//
// Created by umar on 17/1/21.
//

#include <iostream>
#include "../peersmanager.h"
#include "../mutexlock.h"
#include "../messageprocesser.h"
int main() {
    PeersManager server;
    server.startServer("127.0.0.1", 8080);
    while (true) {
        MessageProcesser::removePeerFromConnected(server.m_connectedPeer);
        if (MutexLock::getInstance().tryLock()) {
            MutexLock::getInstance().acquireLock();
            server.listen(1);
            std::cout << "size = " << server.m_connectedPeer.size() << std::endl;
            for (const auto &itr:server.m_connectedPeer) {
                itr->read(1024);
                if (itr->m_connected) {
                    itr->send("Test Message");
                }
            }
            MutexLock::getInstance().releaseLock();
        }
        std::cout << "sleeping \n";
        sleep(5);
    }
}
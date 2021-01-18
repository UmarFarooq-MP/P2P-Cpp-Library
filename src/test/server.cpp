//
// Created by umar on 17/1/21.
//

#include <iostream>
#include "../peersmanager.h"

int main( ) {
    PeersManager server;
    server.startServer("127.0.0.1",8082);
    while (true) {
        std::cout << "Server Listening \n";
        server.listen(1);
        sleep(10);
    }
}
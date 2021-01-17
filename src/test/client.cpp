//
// Created by umar on 17/1/21.
//

#include <iostream>
#include "../peersmanager.h"

int main( ) {
    PeersManager client;
    if(client.connect("127.0.0.1",8080,0)) {
        std::cout << "Peer Connected \n";
    }
}
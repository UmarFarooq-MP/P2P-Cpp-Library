#include <iostream>
#include "socketresource.h"
#include "peersmanager.h"
int main() {

    PeersManager obj;
    obj.createServer("",8080);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

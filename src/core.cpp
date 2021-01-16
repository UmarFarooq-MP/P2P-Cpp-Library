#include <iostream>
#include "socketresource.h"
#include "peersmanager.h"
int main() {

    PeersManager obj;
    obj.connect("192.168.100.10",8080,0);
    sleep(20);
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

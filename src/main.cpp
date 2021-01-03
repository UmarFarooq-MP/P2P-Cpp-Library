#include <iostream>
#include "socketresource.h"

int main() {
    SocketResource obj;
    auto socket = obj.create();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}

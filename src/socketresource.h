//
// Created by umar on 29/12/20.
//

#ifndef P2P_CPP_SOCKETRESOURCE_H
#define P2P_CPP_SOCKETRESOURCE_H

#include <memory>

#ifdef _WIN32
/* See http://stackoverflow.com/questions/12765743/getaddrinfo-on-win32 */
#    ifndef _WIN32_WINNT
#        define _WIN32_WINNT 0x0501 /* Windows XP. */
#    endif
#    include <Ws2tcpip.h>
#    include <winsock2.h>

#    ifdef _MSC_VER
#        pragma comment(lib, "Ws2_32.lib")
#    endif

#    define SHUT_RDWR SD_BOTH
#else
/* Assume that any non-Windows platform uses POSIX-style sockets instead. */
#    include <arpa/inet.h>
#    include <fcntl.h>
#    include <netinet/in.h>
#    include <netinet/tcp.h>
#    include <sys/socket.h>
#    include <unistd.h>

#    define NO_ERROR 0
#    define INVALID_SOCKET -1
#    define SOCKET_ERROR -1
#endif

// MSG_DONTWAIT is not available on some platforms, if it doesn't exist define it as 0
#if !defined(MSG_DONTWAIT)
#    define MSG_DONTWAIT 0
#endif

using Socket = decltype(socket(0, 0, 0));

class SocketResource {
    Socket m_socket;
    int socketFd;
public:
    SocketResource(Socket sockFd = -1);

    static int cleanUp(void);

    bool close();

    bool setNonBlockingMode();

    bool setBlockMode();

    static std::unique_ptr<SocketResource> create();

    Socket resource() const;

    bool SetSocketNoDelay();

    /** This method should be called only once that is why static **/
    static int init();

    void operator=(const SocketResource &object);

};


#endif //P2P_CPP_SOCKETRESOURCE_H

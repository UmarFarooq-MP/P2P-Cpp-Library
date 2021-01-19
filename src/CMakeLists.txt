add_executable(server test/server.cpp peer/peer.h peer/peer.cpp
        peersmanager.h peersmanager.cpp
        socketresource.h socketresource.cpp
        events/events.h events/events.cpp
        peermessages/peermessages.h peermessages/peermessages.cpp
        messageprocesser.h
        messageparser.h messageparser.cpp
        mutexlock.h mutexlock.cpp
        )

add_executable(client test/client.cpp peer/peer.h peer/peer.cpp
        peersmanager.h peersmanager.cpp
        socketresource.h socketresource.cpp
        events/events.h events/events.cpp
        peermessages/peermessages.h peermessages/peermessages.cpp
        messageprocesser.h
        messageparser.h messageparser.cpp
        mutexlock.h mutexlock.cpp
        )
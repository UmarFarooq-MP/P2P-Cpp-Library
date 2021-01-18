add_executable(server test/server.cpp peer/peer.h peer/peer.cpp
        peersmanager.h peersmanager.cpp
        socketresource.h socketresource.cpp
        connectionhandler.h connectionhandler.cpp
        events/events.h events/events.cpp
        peermessages/peermessages.h peermessages/peermessages.cpp
        peermessageprocesser.h peermessageprocesser.cpp
        )

add_executable(client test/client.cpp peer/peer.h peer/peer.cpp
        peersmanager.h peersmanager.cpp
        socketresource.h socketresource.cpp
        connectionhandler.h connectionhandler.cpp
        events/events.h events/events.cpp
        peermessages/peermessages.h peermessages/peermessages.cpp
        peermessageprocesser.h peermessageprocesser.cpp
        )
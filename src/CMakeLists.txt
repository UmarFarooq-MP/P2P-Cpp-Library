add_executable(main main.cpp peer/peer.h peer/peer.cpp
        peersmanager.h peersmanager.cpp
        socketresource.h socketresource.cpp
        connectionhandler.h connectionhandler.cpp
        events/events.h events/events.cpp
        peermessages/peermessages.h peermessages/peermessages.cpp
        peermessages/broadcastmessage.h peermessages/broadcastmessage.cpp
        peermessages/loclamessages.h peermessages/loclamessages.cpp
        )
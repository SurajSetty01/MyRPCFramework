#pragma once
#include <Poco/Net/TCPServerConnectionFactory.h>
#include "server_handler.h"

class ServerHandlerFactory : public Poco::Net::TCPServerConnectionFactory {
public:
    Poco::Net::TCPServerConnection* createConnection(const Poco::Net::StreamSocket& socket) override {
        return new ServerHandler(socket);
    }
};

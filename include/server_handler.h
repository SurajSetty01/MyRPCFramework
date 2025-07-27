#pragma once

#include <Poco/Net/TCPServerConnection.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/JSON/Object.h>

class ServerHandler : public Poco::Net::TCPServerConnection {
public:
    ServerHandler(const Poco::Net::StreamSocket& socket);

    void run() override;

private:
    int add(int a, int b);
};

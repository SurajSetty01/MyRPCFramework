#include "server_handler.h"
#include "server_factory.h"

#include <Poco/Net/TCPServer.h>
#include <Poco/Net/ServerSocket.h>
#include <iostream>

int main() {
    try {
        Poco::Net::ServerSocket serverSocket(9999);
        Poco::Net::TCPServer server(new ServerHandlerFactory(), serverSocket);

        std::cout << "Server running on port 9999...\n";
        server.start();

        std::string dummy;
        std::getline(std::cin, dummy);

        server.stop();
    } catch (Poco::Exception& ex) {
        std::cerr << "Failed to start server: " << ex.displayText() << std::endl;
    }

    return 0;
}

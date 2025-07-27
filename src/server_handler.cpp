#include "server_handler.h"
#include "message.h"
#include <Poco/JSON/Parser.h>
#include <iostream>

using namespace Poco::Net;
using namespace Poco::JSON;
using namespace Poco::Dynamic;

ServerHandler::ServerHandler(const StreamSocket& socket)
    : TCPServerConnection(socket) {}

int ServerHandler::add(int a, int b) {
    return a + b;
}

void ServerHandler::run() {
    try {
        StreamSocket& ss = socket();
        char buffer[1024];
        std::string jsonRequest;
        int n = ss.receiveBytes(buffer, sizeof(buffer));

        while (n > 0) {
            jsonRequest.append(buffer, n);
            if (jsonRequest.find('\n') != std::string::npos) break;
            n = ss.receiveBytes(buffer, sizeof(buffer));
        }

        auto req = Message::parse(jsonRequest);
        std::string method = req->getValue<std::string>("method");
        auto params = req->getArray("params");
        int id = req->getValue<int>("id");

        std::string response;
        if (method == "add" && params->size() == 2) {
            int a = params->getElement<int>(0);
            int b = params->getElement<int>(1);
            int result = add(a, b);
            response = Message::createResponse(result, id);
        } else {
            response = Message::createError("Unknown method or wrong params", id);
        }

        response += "\n"; // newline-terminated
        ss.sendBytes(response.data(), (int)response.size());
    } catch (Poco::Exception& ex) {
        std::cerr << "Server error: " << ex.displayText() << std::endl;
    }
}

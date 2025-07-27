#include "message.h"
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/JSON/Parser.h>
#include <iostream>

using namespace Poco::Net;
using namespace Poco::JSON;

int main() {
    try {
        SocketAddress serverAddr("127.0.0.1:9999");
        StreamSocket socket(serverAddr);

        //JSON request: add(4, 6)
        std::string request = Message::createRequest("add", {4, 6}, 1);
        request += "\n";  
        // Send the request
        socket.sendBytes(request.data(), (int)request.size());

        // Receive the response
        std::string response;
        char buffer[1024];
        int received = socket.receiveBytes(buffer, sizeof(buffer));
        response.append(buffer, received);

        // Parse and display the result
        Object::Ptr resObj = Message::parse(response);
        if (resObj->has("result")) {
            int result = resObj->getValue<int>("result");
            std::cout << "Result from server: " << result << std::endl;
        } else if (resObj->has("error")) {
            std::string err = resObj->getValue<std::string>("error");
            std::cerr << "Server Error: " << err << std::endl;
        }
    } catch (Poco::Exception& ex) {
        std::cerr << "Client error: " << ex.displayText() << std::endl;
    }

    return 0;
}

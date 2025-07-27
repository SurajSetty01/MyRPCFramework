#include "message.h"
#include <iostream>

int main() {
    // Request
    std::string req = Message::createRequest("add", {3, 5}, 1);
    std::cout << "Request JSON:\n" << req << "\n\n";

    // Parse the request
    auto parsedReq = Message::parse(req);
    std::cout << "Parsed method: " << parsedReq->getValue<std::string>("method") << "\n";
    
    auto params = parsedReq->getArray("params");
    std::cout << "Params: ";
    for (size_t i = 0; i < params->size(); ++i)
        std::cout << params->getElement<int>(i) << " ";
    std::cout << "\n\n";

    // Response
    std::string res = Message::createResponse(8, 1);
    std::cout << "Response JSON:\n" << res << "\n";

    // Error
    std::string err = Message::createError("Invalid method", 1);
    std::cout << "Error JSON:\n" << err << "\n";

    return 0;
}

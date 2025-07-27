#pragma once

#include <string>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>

class Message {
public:
    static std::string createRequest(const std::string& method, const std::vector<int>& params, int id);
    static std::string createResponse(int result, int id);
    static std::string createError(const std::string& errorMsg, int id);

    static Poco::JSON::Object::Ptr parse(const std::string& jsonStr);
};

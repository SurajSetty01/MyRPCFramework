#include "message.h"
#include <Poco/JSON/Array.h>
#include <sstream>

using namespace Poco::JSON;
using namespace Poco;

std::string Message::createRequest(const std::string& method, const std::vector<int>& params, int id) {
    Object::Ptr obj = new Object;
    obj->set("jsonrpc", "2.0");
    obj->set("method", method);

    Array::Ptr paramArray = new Array;
    for (int val : params) {
        paramArray->add(val);
    }
    obj->set("params", paramArray);
    obj->set("id", id);

    std::ostringstream oss;
    obj->stringify(oss, 0);  
    return oss.str();
}

std::string Message::createResponse(int result, int id) {
    Object::Ptr obj = new Object;
    obj->set("jsonrpc", "2.0");
    obj->set("result", result);
    obj->set("id", id);

    std::ostringstream oss;
    obj->stringify(oss, 0);
    return oss.str();
}

std::string Message::createError(const std::string& errorMsg, int id) {
    Object::Ptr obj = new Object;
    obj->set("jsonrpc", "2.0");
    obj->set("error", errorMsg);
    obj->set("id", id);

    std::ostringstream oss;
    obj->stringify(oss, 0);
    return oss.str();
}

Object::Ptr Message::parse(const std::string& jsonStr) {
    Parser parser;
    Dynamic::Var result = parser.parse(jsonStr);
    return result.extract<Object::Ptr>();
}

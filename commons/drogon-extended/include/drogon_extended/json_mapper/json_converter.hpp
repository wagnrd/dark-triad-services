#ifndef DARK_TRIAD_LOGIN_SERVICE_JSON_CONVERTER_HPP
#define DARK_TRIAD_LOGIN_SERVICE_JSON_CONVERTER_HPP

#include <memory>
#include <json/value.h>

class JsonConverter {
public:
    static Json::Value& check(const std::shared_ptr<Json::Value>& jsonPtr, const std::string& key);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_JSON_CONVERTER_HPP

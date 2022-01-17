#ifndef DARK_TRIAD_LOGIN_SERVICE_JSON_CONVERTER_HPP
#define DARK_TRIAD_LOGIN_SERVICE_JSON_CONVERTER_HPP

#include <memory>
#include <json/value.h>

class JsonConverter {
public:
    static const Json::Value& check_root(const std::shared_ptr<Json::Value>& jsonPtr);
    static const Json::Value& check(const std::shared_ptr<Json::Value>& jsonPtr, const std::string& key);
    static const Json::Value& check(const Json::Value& json, const std::string& key);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_JSON_CONVERTER_HPP

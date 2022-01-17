#include <stdexcept>

#include <drogon_extended/json_mapper/json_converter.hpp>

const Json::Value& JsonConverter::check_root(const std::shared_ptr<Json::Value>& jsonPtr)
{
    if (jsonPtr == nullptr || jsonPtr->empty())
        throw std::invalid_argument("No json data found");

    return *jsonPtr;
}

const Json::Value& JsonConverter::check(const std::shared_ptr<Json::Value>& jsonPtr, const std::string& key)
{
    const auto& json = JsonConverter::check_root(jsonPtr);
    return JsonConverter::check(json, key);
}

const Json::Value& JsonConverter::check(const Json::Value& json, const std::string& key)
{
    auto& valueJson = json[key];

    if (valueJson.empty())
        throw std::invalid_argument("Mandatory field '" + key + "' is missing from json");

    return valueJson;
}

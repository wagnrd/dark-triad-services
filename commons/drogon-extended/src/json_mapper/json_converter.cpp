#include <drogon_extended/json_mapper/json_converter.hpp>

Json::Value& JsonConverter::check(const std::shared_ptr<Json::Value>& jsonPtr, const std::string& key)
{
    if (jsonPtr == nullptr || jsonPtr->empty())
        throw std::invalid_argument("Mandatory field '" + key + "' is missing from json");

    auto& valueJson = (*jsonPtr)[key];

    if (valueJson.empty())
        throw std::invalid_argument("Mandatory field '" + key + "' is missing from json");

    return valueJson;
}

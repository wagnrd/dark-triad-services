#include <drogon_extended/json_mapper/json_model.hpp>

JsonModel::JsonModel(std::shared_ptr<Json::Value> jsonPtr)
{
    if (jsonPtr == nullptr || jsonPtr->empty())
        throw std::invalid_argument("No json data provided");

    this->jsonPtr = jsonPtr;
}

Json::Value& JsonModel::check(const std::string& key)
{
    auto& valueJson = (*jsonPtr)[key];

    if (valueJson.empty())
        throw std::invalid_argument("Mandatory field '" + key + "' is missing from json");

    return valueJson;
}

Json::Value JsonModel::json()
{
    return Json::Value();
}


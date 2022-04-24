#include "include/factory/statistic_factory.hpp"

std::shared_ptr<Json::Value> StatisticFactory::to_json(const Statistic& statistic)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["createdTimestamp"] = static_cast<Json::Value::UInt64>(statistic.createdTimestamp);
    (*json)["lastUsedTimestamp"] = static_cast<Json::Value::UInt64>(statistic.lastUsedTimestamp);

    return json;
}
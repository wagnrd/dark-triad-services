#include "include/factory/statistic_factory.hpp"

std::shared_ptr<Json::Value> StatisticFactory::to_json(const Statistic& statistic)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["createdTimestamp"] = statistic.createdTimestamp;
    (*json)["lastUsedTimestamp"] = statistic.lastUsedTimestamp;

    return json;
}
#include <chrono>
#include <iomanip>

#include "include/configuration/redis_config.hpp"

RedisConfig::RedisConfig(const Json::Value& json) : ConfigModel(json)
{
    ipAddress = get_json_var("ipAddress").asString();
    port = get_json_var("port").asInt();
    password = get_env_var("REDIS_PASSWORD");
}

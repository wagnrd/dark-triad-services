#include <chrono>
#include <iomanip>
#include "include/configuration/oidc_config.hpp"

AppConfig::AppConfig(const Json::Value& json) : ConfigModel(json)
{
    version = get_json_var("version").asString();
    commitHash = get_env_var("COMMIT_HASH", "local");
    startupTime = register_custom_value("startupTime", currentTimeAsString());
}

std::string AppConfig::currentTimeAsString()
{
    auto now = std::chrono::system_clock::now();
    auto nowInTimeT = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss << std::put_time(std::localtime(&nowInTimeT), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

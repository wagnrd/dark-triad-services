#include <thread>
#include "include/configuration/web_server_config.hpp"

WebServerConfig::WebServerConfig(const Json::Value& json) : ConfigModel(json)
{
    port = std::stoi(get_env_var("PORT", "8080"));
    apiKey = get_env_var("API_KEY", "");

    auto threadCount = std::thread::hardware_concurrency() * 2;
    concurrency = std::stoi(register_custom_value("concurrency", std::to_string(threadCount)));
}

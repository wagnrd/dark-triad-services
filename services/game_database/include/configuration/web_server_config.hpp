#ifndef DATABASE_API_WEB_SERVER_CONFIG_HPP
#define DATABASE_API_WEB_SERVER_CONFIG_HPP

#include <drogon_extended/configuration/config_model.hpp>

class BaseConfig;

class WebServerConfig: public ConfigModel<BaseConfig> {
public:
    uint16_t port{};
    std::string apiKey;
    size_t concurrency;

    explicit WebServerConfig(const Json::Value& json);
};

#endif //DATABASE_API_WEB_SERVER_CONFIG_HPP

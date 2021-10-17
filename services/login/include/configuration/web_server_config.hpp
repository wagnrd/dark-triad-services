#ifndef DARK_TRIAD_LOGIN_SERVICE_WEB_SERVER_CONFIG_HPP
#define DARK_TRIAD_LOGIN_SERVICE_WEB_SERVER_CONFIG_HPP

#include <drogon_extended/configuration/config_model.hpp>

class BaseConfig;

class WebServerConfig: public ConfigModel<BaseConfig> {
public:
    uint16_t port{};
    size_t concurrency{};

    explicit WebServerConfig(const Json::Value& json);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_WEB_SERVER_CONFIG_HPP

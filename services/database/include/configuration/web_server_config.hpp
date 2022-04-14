#ifndef DARK_TRIAD_SERVICES_WEB_SERVER_CONFIG_HPP
#define DARK_TRIAD_SERVICES_WEB_SERVER_CONFIG_HPP

#include <drogon_extended/configuration/config_model.hpp>

class BaseConfig;

class WebServerConfig: public ConfigModel<BaseConfig> {
public:
    uint16_t port{};
    std::string apiKey;
    size_t concurrency;

    explicit WebServerConfig(const Json::Value& json);
};

#endif //DARK_TRIAD_SERVICES_WEB_SERVER_CONFIG_HPP

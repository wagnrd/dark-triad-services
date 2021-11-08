#ifndef DARK_TRIAD_LOGIN_SERVICE_BASE_CONFIG_HPP
#define DARK_TRIAD_LOGIN_SERVICE_BASE_CONFIG_HPP

#include "app_config.hpp"
#include "web_server_config.hpp"
#include "oidc_config.hpp"
#include "redis_config.hpp"

class BaseConfig: public ConfigModel<BaseConfig> {
public:
    std::shared_ptr<AppConfig> app;
    std::shared_ptr<WebServerConfig> webServer;
    std::shared_ptr<OidcConfig> oidc;
    std::shared_ptr<RedisConfig> redis;

    explicit BaseConfig(const Json::Value& json);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_BASE_CONFIG_HPP

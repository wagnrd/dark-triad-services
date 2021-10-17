#ifndef DARK_TRIAD_LOGIN_SERVICE_BASE_CONFIG_HPP
#define DARK_TRIAD_LOGIN_SERVICE_BASE_CONFIG_HPP

#include "oidc_config.hpp"
#include "web_server_config.hpp"
#include "app_config.hpp"

class BaseConfig: public ConfigModel<BaseConfig> {
public:
    std::shared_ptr<AppConfig> app;
    std::shared_ptr<WebServerConfig> webServer;
    std::shared_ptr<OidcConfig> oidc;

    explicit BaseConfig(const Json::Value& json);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_BASE_CONFIG_HPP

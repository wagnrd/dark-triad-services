#ifndef DARK_TRIAD_LOGIN_SERVICE_OIDC_CONFIG_HPP
#define DARK_TRIAD_LOGIN_SERVICE_OIDC_CONFIG_HPP

#include <drogon_extended/configuration/config_model.hpp>

class BaseConfig;

class OidcConfig: public ConfigModel<BaseConfig> {
public:
    std::string baseUrl;
    std::string clientId;
    std::string clientSecret;
    std::string audience;

    explicit OidcConfig(const Json::Value& json);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_OIDC_CONFIG_HPP

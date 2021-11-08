#ifndef DARK_TRIAD_LOGIN_SERVICE_REDIS_CONFIG_HPP
#define DARK_TRIAD_LOGIN_SERVICE_REDIS_CONFIG_HPP

#include <drogon_extended/configuration/config_model.hpp>

class BaseConfig;

class RedisConfig: public ConfigModel<BaseConfig> {
public:
    std::string ipAddress;
    std::uint16_t port;
    std::string password;

    explicit RedisConfig(const Json::Value& json);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_REDIS_CONFIG_HPP

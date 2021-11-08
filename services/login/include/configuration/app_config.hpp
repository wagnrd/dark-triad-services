#ifndef DARK_TRIAD_LOGIN_SERVICE_APP_CONFIG_HPP
#define DARK_TRIAD_LOGIN_SERVICE_APP_CONFIG_HPP

#include <drogon_extended/configuration/config_model.hpp>

class BaseConfig;

class AppConfig: public ConfigModel<BaseConfig> {
public:
    std::string version;
    std::string commitHash;
    std::string startupTime;

    explicit AppConfig(const Json::Value& json);

private:
    static std::string currentTimeAsString();
};

#endif //DARK_TRIAD_LOGIN_SERVICE_APP_CONFIG_HPP

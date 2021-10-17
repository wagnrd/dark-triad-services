#ifndef DATABASE_API_APP_CONFIG_HPP
#define DATABASE_API_APP_CONFIG_HPP

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

#endif //DATABASE_API_APP_CONFIG_HPP

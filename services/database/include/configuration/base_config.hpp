#ifndef DARK_TRIAD_SERVICES_BASE_CONFIG_HPP
#define DARK_TRIAD_SERVICES_BASE_CONFIG_HPP

#include "app_config.hpp"
#include "web_server_config.hpp"
#include "postgres_config.hpp"

class BaseConfig: public ConfigModel<BaseConfig> {
public:
    std::shared_ptr<AppConfig> app;
    std::shared_ptr<WebServerConfig> webServer;
    std::shared_ptr<PostgresConfig> postgres;

    explicit BaseConfig(const Json::Value& json);
};

#endif //DARK_TRIAD_SERVICES_BASE_CONFIG_HPP

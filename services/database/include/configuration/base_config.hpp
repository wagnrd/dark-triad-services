#ifndef DATABASE_API_BASE_CONFIG_HPP
#define DATABASE_API_BASE_CONFIG_HPP

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

#endif //DATABASE_API_BASE_CONFIG_HPP

#ifndef DATABASE_API_POSTGRES_CONFIG_HPP
#define DATABASE_API_POSTGRES_CONFIG_HPP

#include <drogon_extended/configuration/config_model.hpp>

class BaseConfig;

class PostgresConfig: public ConfigModel<BaseConfig> {
public:
    std::string host;
    uint16_t port{};
    std::string databaseName;
    std::string username;
    std::string password;

    explicit PostgresConfig(const Json::Value& json);

private:
    void configure_prod(const Json::Value& json);
    void configure_local(const Json::Value& json);
};

#endif //DATABASE_API_POSTGRES_CONFIG_HPP

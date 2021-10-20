#include <json/value.h>
#include <drogon_extended/configuration/config_model.hpp>
#include <drogon_extended/configuration/deployment_stage.hpp>

#include "include/configuration/postgres_config.hpp"

PostgresConfig::PostgresConfig(const Json::Value& json) : ConfigModel(json)
{
    if (getDeploymentStage() == DeploymentStage::LOCAL)
        configure_local(json);
    else
        configure_prod(json);
}

void PostgresConfig::configure_prod(const Json::Value& json)
{
    username = get_env_var("POSTGRES_USERNAME");
    password = get_env_var("POSTGRES_PASSWORD");
    host = get_json_var("host").asString();
    port = get_json_var("port").asInt();
    databaseName = get_json_var("databaseName").asString();
}

void PostgresConfig::configure_local(const Json::Value& json)
{
    host = "localhost";
    port = 5432;
    username = "postgres";
    password = "postgres";
    databaseName = "postgres";
}

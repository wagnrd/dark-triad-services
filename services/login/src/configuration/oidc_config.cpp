#include "include/configuration/oidc_config.hpp"

OidcConfig::OidcConfig(const Json::Value& json) : ConfigModel(json)
{
    baseUrl = get_json_var("baseUrl").asString();
    clientId = get_env_var("OIDC_CLIENT_ID");
    clientSecret = get_env_var("OIDC_CLIENT_SECRET");
    audience = get_json_var("audience").asString();
}
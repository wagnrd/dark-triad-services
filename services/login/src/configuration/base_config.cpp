#include "include/configuration/base_config.hpp"

BaseConfig::BaseConfig(const Json::Value& json) : ConfigModel(json)
{
    app = get_json_obj_var<AppConfig>("app");
    webServer = register_custom_object<WebServerConfig>("webServer");
    oidc = get_json_obj_var<OidcConfig>("oidc");
    redis = get_json_obj_var<RedisConfig>("redis");
}

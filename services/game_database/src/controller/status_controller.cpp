#include <drogon_extended/configuration/configuration.hpp>

#include <include/configuration/base_config.hpp>
#include "include/controller/status_controller.hpp"

void status::details(const drogon::HttpRequestPtr& request,
                     std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    auto config = Configuration<BaseConfig>::get();

    Json::Value json;
    json["version"] = config->app->version;
    json["commitHash"] = config->app->commitHash;
    json["startupTime"] = config->app->startupTime;

    callback(drogon::HttpResponse::newHttpJsonResponse(json));
}

#include <drogon_extended/configuration/configuration.hpp>

#include <include/configuration/base_config.hpp>
#include "include/controller/public_api/status_controller.hpp"

void public_api::status::details(const drogon::HttpRequestPtr& request,
                                 std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    Json::Value json;
    json["version"] = config->app->version;
    json["commitHash"] = config->app->commitHash;
    json["startupTime"] = config->app->startupTime;

    callback(drogon::HttpResponse::newHttpJsonResponse(json));
}

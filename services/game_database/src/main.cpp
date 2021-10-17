#include <drogon/drogon.h>
#include <drogon_extended/configuration/config_model.hpp>

#include <include/configuration/base_config.hpp>

int main()
{
    auto config = Configuration<BaseConfig>::get();

    drogon::app().addListener("0.0.0.0", config->webServer->port)
                 .setThreadNum(config->webServer->concurrency)
                 .createDbClient(
                         "postgresql",
                         config->postgres->host,
                         config->postgres->port,
                         config->postgres->databaseName,
                         config->postgres->username,
                         config->postgres->password
                 )
                 .registerPostHandlingAdvice(
                         [](const drogon::HttpRequestPtr& request, const drogon::HttpResponsePtr& response) {
                             response->addHeader("Access-Control-Allow-Origin", "*");
                         }
                 )
                 .enableRelaunchOnError()
                 .run();
}

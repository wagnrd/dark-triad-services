#include <drogon/drogon.h>

#include <include/configuration/base_config.hpp>

int main()
{
    auto config = Configuration<BaseConfig>::get();

    drogon::app().addListener("0.0.0.0", config->webServer->port)
                 .registerPostHandlingAdvice(
                         [](const drogon::HttpRequestPtr& request, const drogon::HttpResponsePtr& response) {
                             response->addHeader("Access-Control-Allow-Origin", "*");
                         }
                 )
                 .createRedisClient(
                         config->redis->ipAddress,
                         config->redis->port,
                         "default",
                         config->redis->password
                 )
                 .setThreadNum(config->webServer->concurrency)
                 .enableRelaunchOnError()
                 .run();
}

#include <random>

#include <drogon_extended/configuration/configuration.hpp>
#include <drogon_extended/exception_mapper/exception_mapper_macros.hpp>
#include <drogon_extended/json_mapper/json_converter.hpp>

#include <include/controller/login_controller.hpp>
#include <include/controller/factory/challenge_session_factory.hpp>
#include <include/controller/factory/challenge_response_session_factory.hpp>
#include <include/controller/factory/credentials_factory.hpp>

login::login()
{
    std::srand(std::time(nullptr)); // NOLINT(cert-msc51-cpp)
}

void login::challenge(const drogon::HttpRequestPtr& request,
                      std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    try
    {
        auto requestJson = request->jsonObject();
        auto clientNonce = JsonConverter::check(requestJson, "nonce").asInt();

        auto challengeSession = loginService->get_challenge_session(clientNonce);

        auto responseJson = ChallengeSessionFactory::to_json(challengeSession);
        auto response = drogon::HttpResponse::newHttpJsonResponse(*responseJson);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(loginExceptionMapper)
    }
}

void login::get_token(const drogon::HttpRequestPtr& request,
                      std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    try
    {
        auto jsonPtr = request->jsonObject();
        auto challengeResponseSession = ChallengeResponseSessionFactory::from_json(jsonPtr);
        auto credentials = CredentialsFactory::from_json(jsonPtr);

        auto oidcIdToken = loginService->get_token(challengeResponseSession, credentials);

        Json::Value responseJson;
        responseJson["id_token"] = oidcIdToken.idToken;
        responseJson["token_type"] = oidcIdToken.tokenType;

        auto response = drogon::HttpResponse::newHttpJsonResponse(responseJson);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(loginExceptionMapper)
    }
}



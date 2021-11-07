#include <fmt/format.h>
#include <drogon/drogon.h>

#include <drogon/HttpTypes.h>
#include <include/client/factory/oidc_id_token_factory.hpp>
#include <include/client/exceptions/unauthorized_exception.hpp>
#include "include/client/auth0_client.hpp"

OidcIdToken Auth0Client::get_token(const Credentials& credentials)
{
    auto oidcClient = create_client();

    auto request = create_request(credentials);
    auto[result, response] = oidcClient->sendRequest(request, 30);

    verify_response(result, response);

    return OidcIdTokenFactory::from_json(response->jsonObject());
}

void Auth0Client::verify_response(drogon::ReqResult result, drogon::HttpResponsePtr response) const
{
    if (result == drogon::ReqResult::Ok && response->statusCode() == drogon::k200OK)
        return;

    if (result != drogon::ReqResult::Ok)
    {
        auto resultStr = result_to_string(result);
        throw std::runtime_error("Request was not successful: " + resultStr);
    }

    if (response->statusCode() == drogon::k401Unauthorized || response->statusCode() == drogon::k403Forbidden)
    {
        auto responseBody = std::string(response->body());
        throw UnauthorizedException();
    }
    else
    {
        auto responseBody = std::string(response->body());
        throw std::runtime_error("The OIDC server did not respond correctly: " + responseBody);
    }
}

std::string Auth0Client::result_to_string(drogon::ReqResult requestResult) const
{
    switch (requestResult)
    {
        case drogon::ReqResult::Ok:
            return "Ok";
        case drogon::ReqResult::BadResponse:
            return "BadResponse";
        case drogon::ReqResult::BadServerAddress:
            return "BadServerAddress";
        case drogon::ReqResult::NetworkFailure:
            return "NetworkFailure";
        case drogon::ReqResult::InvalidCertificate:
            return "InvalidCertificate";
        case drogon::ReqResult::HandshakeError:
            return "HandshakeError";
        case drogon::ReqResult::Timeout:
            return "Timeout";
    }

    return "";
}

drogon::HttpRequestPtr Auth0Client::create_request(const Credentials& credentials) const
{
    auto body = fmt::format(
            "grant_type=password&username={}&password={}&audience={}&scope=openid email profile&client_id={}&client_secret={}",
            credentials.email,
            credentials.password,
            config->oidc->audience,
            config->oidc->clientId,
            config->oidc->clientSecret
    );

    auto request = drogon::HttpRequest::newHttpFormPostRequest();
    request->setBody(body);
    request->setPath("/oauth/token");

    LOG_DEBUG << "Request body: " << body;
    return request;
}

drogon::HttpClientPtr Auth0Client::create_client()
{
    return drogon::HttpClient::newHttpClient(config->oidc->baseUrl);
}


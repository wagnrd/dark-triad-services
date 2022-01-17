#include "include/drogon_extended/security/api_key_guard.hpp"
#include "drogon_extended/security/exceptions/unauthorized_exception.hpp"

#include <utility>

ApiKeyGuard::ApiKeyGuard(std::string apiKey) : apiKey(std::move(apiKey))
{}

void ApiKeyGuard::check(const drogon::HttpRequestPtr& request)
{
    auto authorization = request->getHeader("Authorization");

    if (authorization != apiKey)
        throw UnauthorizedException("Provided authorization is invalid: '" + authorization + "'");
}

#include "trantor/utils/Logger.h"

#include "include/drogon_extended/security/exceptions/unauthorized_exception.hpp"
#include "include/drogon_extended/security/jwt_token_guard.hpp"

JwtTokenGuard::JwtTokenGuard(std::string publicKey) : publicKey(std::move(publicKey))
{}

jwt::decoded_jwt<jwt::picojson_traits> JwtTokenGuard::check(const drogon::HttpRequestPtr& request)
{
    auto authorization = request->getHeader("Authorization");
    auto tokenType = authorization.substr(0, 6);

    if (tokenType != "Bearer")
        throw UnauthorizedException("Provided jwtToken type is invalid: '" + tokenType + "'");

    try
    {
        auto jwtToken = authorization.substr(7);
        auto decodedJwtToken = jwt::decode(jwtToken);

        auto verifier = jwt::verify().allow_algorithm(jwt::algorithm::rs256{publicKey});

        std::error_code error;
        verifier.verify(decodedJwtToken, error);

        if (error.value() != static_cast<int>(jwt::error::token_verification_error::ok))
        {
            LOG_DEBUG << error.message();
            throw std::exception();
        }

        return decodedJwtToken;
    }
    catch (const std::exception& e)
    {
        throw UnauthorizedException("Provided authorization is invalid: '" + authorization + "'");
    }
}

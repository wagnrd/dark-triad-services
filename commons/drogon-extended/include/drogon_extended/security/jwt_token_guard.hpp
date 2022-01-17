#ifndef DARK_TRIAD_SERVICES_JWT_TOKEN_GUARD_HPP
#define DARK_TRIAD_SERVICES_JWT_TOKEN_GUARD_HPP

#include "drogon/HttpRequest.h"

class JwtTokenGuard {

    std::string publicKey;

public:
    explicit JwtTokenGuard(std::string publicKey);

    jwt::decoded_jwt<jwt::picojson_traits> check(const drogon::HttpRequestPtr& request);
};

#endif //DARK_TRIAD_SERVICES_JWT_TOKEN_GUARD_HPP

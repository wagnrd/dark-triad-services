#ifndef DROGON_EXTENDED_SECURITY_HPP
#define DROGON_EXTENDED_SECURITY_HPP

#include <jwt-cpp/jwt.h>
#include <drogon/HttpResponse.h>
#include <drogon/HttpRequest.h>

#define API_KEY(apiKey) isUnauthorized = authorization != (apiKey);

#define JWT_TOKEN(publicKey)                                                                    \
    auto tokenType = authorization.substr(0, 6);                                                \
                                                                                                \
    if (tokenType != "Bearer")                                                                  \
    {                                                                                           \
        LOG_DEBUG << "Token type '" << tokenType << "' is not Bearer!";                         \
                                                                                                \
        auto response = ExceptionMapper::build_exception_response(                              \
                                drogon::HttpStatusCode::k401Unauthorized,                       \
                                "Authorization failed",                                         \
                                "Provided token type is invalid: '" + tokenType + "'"           \
        );                                                                                      \
        callback(response);                                                                     \
        return;                                                                                 \
    }                                                                                           \
                                                                                                \
    auto jwtToken = authorization.substr(7);                                                    \
    auto decodedJwtToken = jwt::decode(jwtToken);                                               \
                                                                                                \
    auto verifier = jwt::verify()                                                               \
            .allow_algorithm(jwt::algorithm::rs256{publicKey});                                 \
                                                                                                \
    std::error_code error;                                                                      \
    verifier.verify(decodedJwtToken, error);                                                    \
                                                                                                \
    if (error.value() != static_cast<int>(jwt::error::token_verification_error::ok))            \
    {                                                                                           \
        LOG_DEBUG << error.message();                                                           \
        isUnauthorized = true;                                                                  \
    }                                                                                           \
    else                                                                                        \
    {                                                                                           \
        isUnauthorized = false;                                                                 \
    }

#define SECURITY_GUARD(authorizationConfig)                                                     \
    auto authorization = request->getHeader("Authorization");                                   \
    LOG_DEBUG << "Authorization: " << authorization;                                            \
                                                                                                \
    bool isUnauthorized = true;                                                                 \
    authorizationConfig                                                                         \
                                                                                                \
    if (isUnauthorized)                                                                         \
    {                                                                                           \
        auto response = ExceptionMapper::build_exception_response(                              \
                                drogon::HttpStatusCode::k401Unauthorized,                       \
                                "Authorization failed",                                         \
                                "Provided authorization is invalid: '" + authorization + "'"    \
        );                                                                                      \
                                                                                                \
        callback(response);                                                                     \
        return;                                                                                 \
    }

#define ASSERT_JWT_CONSTRAINT(jwtConstraint, expectedValue)                                          \
    auto actualValue = decodedJwtToken.get_payload_claim("email")                                    \
                                      .as_string();                                                  \
    LOG_DEBUG << "Actual value:   " << actualValue << " - "                                          \
              << "Expected value: " << expectedValue;                                                \
                                                                                                     \
    if (actualValue != expectedValue)                                                                \
    {                                                                                                \
        auto response = ExceptionMapper::build_exception_response(                                   \
                                drogon::HttpStatusCode::k403Forbidden,                               \
                                "JWT constraint violation",                                          \
                                "Provided JWT token constraint for '" + std::string(jwtConstraint) + \
                                "'  with value '" + actualValue + "' did not match with '" +         \
                                std::string(expectedValue) + "'"                                     \
        );                                                                                           \
                                                                                                     \
        callback(response);                                                                          \
        return;                                                                                      \
    }

#endif //DROGON_EXTENDED_SECURITY_HPP

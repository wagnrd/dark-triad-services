#ifndef DARK_TRIAD_LOGIN_SERVICE_OIDC_ID_TOKEN_HPP
#define DARK_TRIAD_LOGIN_SERVICE_OIDC_ID_TOKEN_HPP

#include <utility>
#include <string>

class OidcIdToken {
public:
    std::string idToken;
    std::string tokenType;

    OidcIdToken(std::string idToken, std::string tokenType)
            : idToken(std::move(idToken)), tokenType(std::move(tokenType))
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_OIDC_ID_TOKEN_HPP

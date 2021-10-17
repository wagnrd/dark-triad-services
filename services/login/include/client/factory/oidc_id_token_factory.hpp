#ifndef DARK_TRIAD_LOGIN_SERVICE_OIDC_ID_TOKEN_FACTORY_HPP
#define DARK_TRIAD_LOGIN_SERVICE_OIDC_ID_TOKEN_FACTORY_HPP

#include <memory>
#include <json/value.h>

#include <include/client/model/oidc_id_token.hpp>

class OidcIdTokenFactory {
public:
    static OidcIdToken from_json(const std::shared_ptr<Json::Value>& jsonPtr);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_OIDC_ID_TOKEN_FACTORY_HPP

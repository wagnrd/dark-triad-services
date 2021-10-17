#ifndef DARK_TRIAD_LOGIN_SERVICE_DUMMY_OIDC_CLIENT_HPP
#define DARK_TRIAD_LOGIN_SERVICE_DUMMY_OIDC_CLIENT_HPP

#include <drogon_extended/service/service.hpp>

#include "include/client/model/oidc_id_token.hpp"
#include "include/service/login/model/credentials.hpp"
#include "oidc_client.hpp"

class DummyOidcClient: public OidcClient<DummyOidcClient> {
public:
    OidcIdToken get_token(const Credentials& credentials) override;
};

#endif //DARK_TRIAD_LOGIN_SERVICE_DUMMY_OIDC_CLIENT_HPP

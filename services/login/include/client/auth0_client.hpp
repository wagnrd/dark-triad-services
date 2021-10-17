#ifndef DARK_TRIAD_LOGIN_SERVICE_AUTH0_CLIENT_HPP
#define DARK_TRIAD_LOGIN_SERVICE_AUTH0_CLIENT_HPP

#include <memory>
#include <drogon/HttpClient.h>
#include <drogon_extended/service/service.hpp>

#include "include/configuration/base_config.hpp"
#include "include/client/model/oidc_id_token.hpp"
#include "include/service/login/model/credentials.hpp"
#include "oidc_client.hpp"

class Auth0Client: public OidcClient<Auth0Client> {

    std::shared_ptr<BaseConfig> config = Configuration<BaseConfig>::get();

public:
    OidcIdToken get_token(const Credentials& credentials) override;

private:
    drogon::HttpClientPtr create_client();
    drogon::HttpRequestPtr create_request(const Credentials& credentials) const;
    std::string result_to_string(drogon::ReqResult requestResult) const;
    void verify_response(drogon::ReqResult result, drogon::HttpResponsePtr response) const;
};

#endif //DARK_TRIAD_LOGIN_SERVICE_AUTH0_CLIENT_HPP

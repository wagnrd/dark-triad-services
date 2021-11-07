#ifndef DARK_TRIAD_LOGIN_SERVICE_LOGIN_SERVICE_HPP
#define DARK_TRIAD_LOGIN_SERVICE_LOGIN_SERVICE_HPP

#include <drogon_extended/service/service.hpp>

#include <include/service/login/model/challenge_session.hpp>
#include <include/service/login/model/challenge_response_session.hpp>
#include <include/service/login/model/credentials.hpp>
#include <include/client/model/oidc_id_token.hpp>
#include <include/client/auth0_client.hpp>
#include <include/client/dummy_oidc_client.hpp>
#include <include/database/sessions_db.hpp>

class LoginService: public Service<LoginService> {

    //DummyOidcClient* oidcClient = DummyOidcClient::get();
    Auth0Client* oidcClient = Auth0Client::get();
    SessionsDB* sessionsDB = SessionsDB::get();

public:
    ChallengeSession get_challenge_session(int clientNonce);
    OidcIdToken get_token(const ChallengeResponseSession& session, const Credentials& credentials);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_LOGIN_SERVICE_HPP

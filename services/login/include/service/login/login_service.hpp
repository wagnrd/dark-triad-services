#ifndef DARK_TRIAD_LOGIN_SERVICE_LOGIN_SERVICE_HPP
#define DARK_TRIAD_LOGIN_SERVICE_LOGIN_SERVICE_HPP

#include <mutex>
#include <unordered_map>
#include <atomic>

#include <drogon_extended/service/service.hpp>

#include <include/service/login/model/challenge_session.hpp>
#include <include/service/login/model/challenge_response_session.hpp>
#include <include/service/login/model/credentials.hpp>
#include <include/client/model/oidc_id_token.hpp>
#include <include/client/auth0_client.hpp>
#include <include/client/dummy_oidc_client.hpp>

class LoginService: public Service<LoginService> {

    std::mutex sessionsMutex;
    std::unordered_map<int, int> sessions; // map: session id -> server nonce
    std::atomic_int32_t currentSessionId = 0;

    //DummyOidcClient* oidcClient = DummyOidcClient::get();
    Auth0Client* oidcClient = Auth0Client::get();

public:
    ChallengeSession get_challenge_session(int clientNonce);
    OidcIdToken get_token(const ChallengeResponseSession& session, const Credentials& credentials);

private:
    int next_session_id();

    int safely_find_server_nonce(int sessionId);
    void safely_delete_session(int sessionId);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_LOGIN_SERVICE_HPP

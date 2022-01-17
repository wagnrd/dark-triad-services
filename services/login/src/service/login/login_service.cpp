#include <trantor/utils/Logger.h>

#include <include/service/login/exception/invalid_challenge_response_exception.hpp>
#include "include/service/login/login_service.hpp"

ChallengeSession LoginService::get_challenge_session(int clientNonce)
{
    LOG_DEBUG << "Creating session for clientNonce: " << clientNonce;
    auto session = sessionsDB->createSession(clientNonce);
    LOG_DEBUG << "Created session: " << session.id;

    return session;
}

drogon::Task<OidcIdToken> LoginService::get_token(const ChallengeResponseSession& session,
                                                  const Credentials& credentials)
{
    LOG_DEBUG << "Looking up session: " << session.id;
    auto serverNonce = co_await sessionsDB->findServerNonceBySessionId(session.id);
    LOG_DEBUG << "Found session '" << session.id << "' with serverNonce: " << serverNonce;

    LOG_DEBUG << "Deleting session: " << session.id;
    sessionsDB->deleteSessionBySessionId(session.id);
    LOG_DEBUG << "Deleted session: " << session.id;

    if (serverNonce != session.response)
        throw InvalidChallengeResponseException(session);

    LOG_DEBUG << "Fetching id token for user: " << credentials.email;
    auto oidcIdToken = oidcClient->get_token(credentials);
    LOG_DEBUG << "Fetched id token for user: " << credentials.email;

    co_return oidcIdToken;
}

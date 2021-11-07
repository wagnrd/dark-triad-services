#include <trantor/utils/Logger.h>

#include <include/service/login/exception/invalid_session_exception.hpp>
#include <include/service/login/exception/invalid_challenge_response_exception.hpp>
#include "include/service/login/login_service.hpp"

ChallengeSession LoginService::get_challenge_session(int clientNonce)
{
    auto sessionId = next_session_id();

    LOG_DEBUG << "Created session: " << sessionId;

    return ChallengeSession(sessionId, challenge);
}

OidcIdToken LoginService::get_token(const ChallengeResponseSession& session, const Credentials& credentials)
{
    LOG_DEBUG << "Looking up session: " << session.id;
    auto serverNonce = safely_find_server_nonce(session.id);
    safely_delete_session(session.id);

    if (serverNonce != session.response)
        throw InvalidChallengeResponseException(session);

    return oidcClient->get_token(credentials);
}

int LoginService::safely_find_server_nonce(int sessionId)
{
    std::unique_lock<std::mutex> lock(sessionsMutex);

    auto sessionIt = sessions.find(sessionId);

    if (sessionIt == sessions.end())
        throw SessionNotFoundException(sessionId);

    return sessionIt->second;
}

void LoginService::safely_delete_session(int sessionId)
{
    std::unique_lock<std::mutex> lock(sessionsMutex);

    sessions.erase(sessionId);
}

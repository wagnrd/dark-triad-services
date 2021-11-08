#include <drogon/utils/Utilities.h>
#include <include/service/login/exception/invalid_session_exception.hpp>

#include "include/database/sessions_db.hpp"

ChallengeSession SessionsDB::createSession(int clientNonce)
{
    std::unique_lock<std::mutex> lock(sessionsMutex);

    auto sessionId = drogon::utils::getUuid();
    auto serverNonce = std::rand(); // NOLINT(cert-msc50-cpp)
    auto challenge = clientNonce + serverNonce;

    sessions[sessionId] = serverNonce;

    return {sessionId, challenge};
}

int SessionsDB::findServerNonceBySessionId(const std::string& sessionId)
{
    std::unique_lock<std::mutex> lock(sessionsMutex);

    auto sessionIt = sessions.find(sessionId);

    if (sessionIt == sessions.end())
        throw SessionNotFoundException(sessionId);

    return sessionIt->second;
}

void SessionsDB::deleteSessionBySessionId(const std::string& sessionId)
{
    std::unique_lock<std::mutex> lock(sessionsMutex);

    sessions.erase(sessionId);
}

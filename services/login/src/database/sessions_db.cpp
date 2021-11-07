#include <drogon/utils/Utilities.h>

#include "include/database/sessions_db.hpp"

ChallengeSession SessionsDB::createSession(int clientNonce)
{
    std::unique_lock<std::mutex> lock(sessionsMutex);

    auto sessionId = drogon::utils::getUuid();
    auto serverNonce = std::rand(); // NOLINT(cert-msc50-cpp)
    auto challenge = clientNonce + serverNonce;

    sessions[sessionId] = serverNonce;

    return ChallengeSession(sessionId, challenge);
}

int SessionsDB::findServerNonceBySessionId(const std::string& sessionId)
{
    return 0;
}

void SessionsDB::deleteSessionBySessionId(const std::string& sessionId)
{
}

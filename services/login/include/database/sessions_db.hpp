#ifndef DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP
#define DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP

#include <string>
#include <mutex>
#include <unordered_map>

#include <drogon_extended/service/service.hpp>

#include <include/service/login/model/challenge_session.hpp>

class SessionsDB: public Service<SessionsDB> {

    std::mutex sessionsMutex;
    std::unordered_map<std::string, int> sessions; // map: session id -> server nonce

public:
    ChallengeSession createSession(int clientNonce);
    int findServerNonceBySessionId(const std::string& sessionId);
    void deleteSessionBySessionId(const std::string& sessionId);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP

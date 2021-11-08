#ifndef DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP
#define DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP

#include <string>
#include <mutex>
#include <unordered_map>

#include <drogon/drogon.h>
#include <drogon_extended/service/service.hpp>

#include <include/service/login/model/challenge_session.hpp>

class SessionsDB: public Service<SessionsDB> {

    std::shared_ptr<drogon::nosql::RedisClient> redis = drogon::app().getRedisClient();

public:
    ChallengeSession createSession(int clientNonce);
    int findServerNonceBySessionId(const std::string& sessionId);
    void deleteSessionBySessionId(const std::string& sessionId);

private:
    std::optional<std::string> execRedisCommandSync(const std::string& command);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP

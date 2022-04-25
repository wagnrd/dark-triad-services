#ifndef DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP
#define DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP

#include <drogon/drogon.h>
#include <drogon_extended/service/service.hpp>

#include <include/service/login/model/challenge_session.hpp>

class SessionsDB: public Service<SessionsDB> {

    std::shared_ptr<drogon::nosql::RedisClient> redis = drogon::app().getRedisClient();

public:
    ChallengeSession createSession(int32_t clientNonce);
    drogon::Task<int> findServerNonceBySessionId(const std::string& sessionId);
    void deleteSessionBySessionId(const std::string& sessionId);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_SESSIONS_DB_HPP
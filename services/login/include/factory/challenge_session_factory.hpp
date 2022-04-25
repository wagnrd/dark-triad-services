#ifndef DARK_TRIAD_LOGIN_SERVICE_RESPONSE_CHALLENGE_SESSION_FACTORY_HPP
#define DARK_TRIAD_LOGIN_SERVICE_RESPONSE_CHALLENGE_SESSION_FACTORY_HPP

#include <json/value.h>

#include "../service/login/model/challenge_session.hpp"

class ChallengeSessionFactory {
public:
    static std::shared_ptr<Json::Value> to_json(const ChallengeSession& challengeSession);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_RESPONSE_CHALLENGE_SESSION_FACTORY_HPP
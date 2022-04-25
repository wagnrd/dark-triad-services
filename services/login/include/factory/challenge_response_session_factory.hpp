#ifndef DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_FACTORY_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_FACTORY_HPP

#include <json/value.h>

#include "../service/login/model/challenge_response_session.hpp"

class ChallengeResponseSessionFactory {
public:
    static ChallengeResponseSession from_json(const std::shared_ptr<Json::Value>& jsonPtr);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_FACTORY_HPP
#ifndef DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_HPP

#include <utility>

class ChallengeResponseSession {
public:
    std::string id;
    int64_t response;

    ChallengeResponseSession(std::string id, int64_t response) : id(std::move(id)), response(response)
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_HPP
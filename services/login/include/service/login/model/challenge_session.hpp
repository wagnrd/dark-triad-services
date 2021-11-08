#ifndef DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP

#include <utility>

class ChallengeSession {
public:
    std::string id;
    int challenge;

    ChallengeSession(std::string id, int challenge) : id(std::move(id)), challenge(challenge)
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP

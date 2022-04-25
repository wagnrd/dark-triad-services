#ifndef DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP

class ChallengeSession {
public:
    std::string id;
    int64_t challenge;

    ChallengeSession(std::string id, int64_t challenge) : id(std::move(id)), challenge(challenge)
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP
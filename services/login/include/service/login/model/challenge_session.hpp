#ifndef DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP

class ChallengeSession {
public:
    int id;
    int challenge;

    ChallengeSession(int id, int challenge) : id(id), challenge(challenge)
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_SESSION_HPP

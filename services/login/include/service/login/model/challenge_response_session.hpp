#ifndef DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_HPP

class ChallengeResponseSession {
public:
    int id;
    int response;

    ChallengeResponseSession(int id, int response) : id(id), response(response)
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CHALLENGE_RESPONSE_SESSION_HPP

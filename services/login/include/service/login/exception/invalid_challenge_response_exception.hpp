#ifndef DARK_TRIAD_LOGIN_SERVICE_INVALID_CHALLENGE_RESPONSE_EXCEPTION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_INVALID_CHALLENGE_RESPONSE_EXCEPTION_HPP

#include <stdexcept>

#include <include/service/login/model/challenge_response_session.hpp>

class InvalidChallengeResponseException: public std::runtime_error {
public:
    explicit InvalidChallengeResponseException(const ChallengeResponseSession& session)
            : runtime_error(
            "Challenge response '" + std::to_string(session.response) + "' for session id '" + session.id
            + "' is invalid!"
    )
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_INVALID_CHALLENGE_RESPONSE_EXCEPTION_HPP

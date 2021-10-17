#ifndef DARK_TRIAD_LOGIN_SERVICE_INVALID_SESSION_EXCEPTION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_INVALID_SESSION_EXCEPTION_HPP

#include <stdexcept>

class SessionNotFoundException: public std::runtime_error {
public:
    explicit SessionNotFoundException(int sessionId)
            : std::runtime_error("Session id '" + std::to_string(sessionId) + "' is invalid!")
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_INVALID_SESSION_EXCEPTION_HPP

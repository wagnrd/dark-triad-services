#ifndef DARK_TRIAD_LOGIN_SERVICE_INVALID_SESSION_EXCEPTION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_INVALID_SESSION_EXCEPTION_HPP

#include <stdexcept>

class SessionNotFoundException: public std::runtime_error {
public:
    explicit SessionNotFoundException(const std::string& sessionId)
            : std::runtime_error("Session id '" + sessionId + "' is invalid!")
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_INVALID_SESSION_EXCEPTION_HPP

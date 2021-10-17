#ifndef DARK_TRIAD_LOGIN_SERVICE_UNAUTHORIZED_EXCEPTION_HPP
#define DARK_TRIAD_LOGIN_SERVICE_UNAUTHORIZED_EXCEPTION_HPP

#include <stdexcept>

class UnauthorizedException: public std::runtime_error {
public:
    UnauthorizedException() : runtime_error("E-Mail or password is incorrect")
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_UNAUTHORIZED_EXCEPTION_HPP

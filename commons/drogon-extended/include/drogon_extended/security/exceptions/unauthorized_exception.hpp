#ifndef DARK_TRIAD_SERVICES_UNAUTHORIZED_EXCEPTION_HPP
#define DARK_TRIAD_SERVICES_UNAUTHORIZED_EXCEPTION_HPP

#include <stdexcept>

class UnauthorizedException: public std::runtime_error {
public:
    explicit UnauthorizedException(const std::string& message) : runtime_error(message)
    {}
};

#endif //DARK_TRIAD_SERVICES_UNAUTHORIZED_EXCEPTION_HPP

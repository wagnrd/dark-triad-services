#ifndef DARK_TRIAD_SERVICES_INVALID_ENV_VAR_EXCEPTION_HPP
#define DARK_TRIAD_SERVICES_INVALID_ENV_VAR_EXCEPTION_HPP

#include <stdexcept>

class InvalidEnvVarException : public std::runtime_error {

    std::string envVarName;

public:
    explicit InvalidEnvVarException(std::string envVarName);
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};

#endif //DARK_TRIAD_SERVICES_INVALID_ENV_VAR_EXCEPTION_HPP

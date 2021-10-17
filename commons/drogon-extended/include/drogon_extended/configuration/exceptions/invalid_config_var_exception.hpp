#ifndef DATABASE_API_INVALID_CONFIG_VAR_EXCEPTION_HPP
#define DATABASE_API_INVALID_CONFIG_VAR_EXCEPTION_HPP

#include <stdexcept>

class InvalidConfigVarException: public std::runtime_error {

    std::string configVarName;

public:
    explicit InvalidConfigVarException(std::string configVarName);
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};

#endif //DATABASE_API_INVALID_CONFIG_VAR_EXCEPTION_HPP

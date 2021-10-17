#ifndef DATABASE_API_INVALID_CONFIG_OBJ_EXCEPTION_HPP
#define DATABASE_API_INVALID_CONFIG_OBJ_EXCEPTION_HPP

#include <stdexcept>

class InvalidConfigObjException: public std::runtime_error {

    std::string configVarName;

public:
    explicit InvalidConfigObjException(std::string configObjName, std::exception& e);
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override;
};

#endif //DATABASE_API_INVALID_CONFIG_OBJ_EXCEPTION_HPP

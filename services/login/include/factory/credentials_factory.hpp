#ifndef DARK_TRIAD_LOGIN_SERVICE_CREDENTIALS_FACTORY_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CREDENTIALS_FACTORY_HPP

#include "../service/login/model/credentials.hpp"
#include <json/value.h>

class CredentialsFactory {
public:
    static Credentials from_json(const std::shared_ptr<Json::Value>& jsonPtr);
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CREDENTIALS_FACTORY_HPP
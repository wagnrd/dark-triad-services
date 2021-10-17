#ifndef DARK_TRIAD_LOGIN_SERVICE_CREDENTIALS_HPP
#define DARK_TRIAD_LOGIN_SERVICE_CREDENTIALS_HPP

#include <string>
#include <utility>

class Credentials {
public:
    std::string email;
    std::string password;

    Credentials(std::string email, std::string password) : email(std::move(email)), password(std::move(password))
    {}
};

#endif //DARK_TRIAD_LOGIN_SERVICE_CREDENTIALS_HPP

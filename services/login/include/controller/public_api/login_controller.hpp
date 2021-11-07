#ifndef DATABASE_SERVICE_STATUS_HPP
#define DATABASE_SERVICE_STATUS_HPP

#include <drogon/HttpController.h>
#include "../exception_mapper/login_exception_mapper.hpp"
#include "../../service/login/login_service.hpp"

namespace public_api
{
    class login: public drogon::HttpController<login> {

        LoginExceptionMapper loginExceptionMapper;
        LoginService* loginService = LoginService::get();

    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(login::challenge, "/challenge", drogon::Post);
            METHOD_ADD(login::get_token, "/token", drogon::Post);
        METHOD_LIST_END

        login();

        void challenge(const drogon::HttpRequestPtr& request,
                       std::function<void(const drogon::HttpResponsePtr&)>&& callback);

        void get_token(const drogon::HttpRequestPtr& request,
                       std::function<void(const drogon::HttpResponsePtr&)>&& callback);
    };
}

#endif //DATABASE_SERVICE_STATUS_HPP

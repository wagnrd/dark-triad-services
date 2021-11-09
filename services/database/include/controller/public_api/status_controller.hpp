#ifndef DARK_TRIAD_LOGIN_SERVICE_LOGIN_HPP
#define DARK_TRIAD_LOGIN_SERVICE_LOGIN_HPP

#include <drogon/HttpController.h>

namespace public_api
{
    class status: public drogon::HttpController<status> {

        std::shared_ptr<BaseConfig> config = Configuration<BaseConfig>::get();

    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(status::details, "/details", drogon::Get);
        METHOD_LIST_END

        void details(const drogon::HttpRequestPtr& request,
                     std::function<void(const drogon::HttpResponsePtr&)>&& callback);
    };
}

#endif //DARK_TRIAD_LOGIN_SERVICE_LOGIN_HPP

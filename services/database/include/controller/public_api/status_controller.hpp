#ifndef DATABASE_SERVICE_STATUS_HPP
#define DATABASE_SERVICE_STATUS_HPP

#include <drogon/HttpController.h>

namespace public_api
{
    class status: public drogon::HttpController<status> {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(status::details, "/details", drogon::Get);
        METHOD_LIST_END

        void details(const drogon::HttpRequestPtr& request,
                     std::function<void(const drogon::HttpResponsePtr&)>&& callback);
    };
}

#endif //DATABASE_SERVICE_STATUS_HPP

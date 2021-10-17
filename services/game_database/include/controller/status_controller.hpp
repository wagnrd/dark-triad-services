#ifndef DATABASE_API_HEALTH_HPP
#define DATABASE_API_HEALTH_HPP

#include <drogon/HttpController.h>

class status: public drogon::HttpController<status> {
public:
    METHOD_LIST_BEGIN
        METHOD_ADD(status::details, "/details", drogon::Get);
    METHOD_LIST_END

    void details(const drogon::HttpRequestPtr& request,
                 std::function<void(const drogon::HttpResponsePtr&)>&& callback);
};

#endif //DATABASE_API_HEALTH_HPP

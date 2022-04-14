#ifndef DARK_TRIAD_SERVICES_EXCEPTION_MAPPER_HPP
#define DARK_TRIAD_SERVICES_EXCEPTION_MAPPER_HPP

#include <functional>

#include <drogon/drogon.h>

class ExceptionMapper {
public:
    virtual void handle_exceptions(std::function<void()>&& controllerImplementation,
                                   std::function<void(const drogon::HttpResponsePtr&)>& callback) = 0;

    static std::shared_ptr<drogon::HttpResponse> build_exception_response(drogon::HttpStatusCode statusCode,
                                                                          const std::string& error,
                                                                          const std::string& description);
};

#endif //DARK_TRIAD_SERVICES_EXCEPTION_MAPPER_HPP

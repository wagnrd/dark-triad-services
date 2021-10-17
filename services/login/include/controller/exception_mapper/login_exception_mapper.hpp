#ifndef DARK_TRIAD_LOGIN_SERVICE_LOGIN_EXCEPTION_MAPPER_HPP
#define DARK_TRIAD_LOGIN_SERVICE_LOGIN_EXCEPTION_MAPPER_HPP

#include <drogon_extended/exception_mapper/exception_mapper.hpp>

class LoginExceptionMapper: public ExceptionMapper {
public:
    void handle_exceptions(std::function<void()>&& controllerImplementation,
                           std::function<void(const drogon::HttpResponsePtr&)>& callback) override;
};

#endif //DARK_TRIAD_LOGIN_SERVICE_LOGIN_EXCEPTION_MAPPER_HPP

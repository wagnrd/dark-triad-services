#ifndef DARK_TRIAD_SERVICES_GLOBAL_EXCEPTION_MAPPER_HPP
#define DARK_TRIAD_SERVICES_GLOBAL_EXCEPTION_MAPPER_HPP

#include <functional>
#include <drogon/drogon.h>

#include "exception_mapper.hpp"

class GlobalExceptionMapper: public ExceptionMapper {

public:
    static void handle_global_exceptions(std::function<void()>&& controllerImplementation,
                                         std::function<void(const drogon::HttpResponsePtr&)>& callback);
};

#endif //DARK_TRIAD_SERVICES_GLOBAL_EXCEPTION_MAPPER_HPP

#include <drogon_extended/exception_mapper/global_exception_mapper.hpp>
#include "drogon_extended/security/exceptions/unauthorized_exception.hpp"

void GlobalExceptionMapper::handle_global_exceptions(std::function<void()>&& controllerImplementation,
                                                     std::function<void(const drogon::HttpResponsePtr&)>& callback)
{
    try
    {
        controllerImplementation();
    }
    catch (const std::invalid_argument& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k400BadRequest,
                "Invalid argument(s)",
                e.what()
        );
        callback(response);
    }
    catch (const UnauthorizedException& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k401Unauthorized,
                "Authorization failed",
                e.what()
        );
        callback(response);
    }
    catch (Json::Exception& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k400BadRequest,
                "Data has wrong format",
                e.what()
        );
        callback(response);
    }
    catch (const std::exception& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k500InternalServerError,
                "Unknown internal server error",
                "An unknown, unrecoverable server error occurred"
        );
        callback(response);
    }
}
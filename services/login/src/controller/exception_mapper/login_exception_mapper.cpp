#include <include/service/login/exception/invalid_session_exception.hpp>
#include <include/service/login/exception/invalid_challenge_response_exception.hpp>
#include <include/controller/exception_mapper/login_exception_mapper.hpp>
#include <include/client/exceptions/unauthorized_exception.hpp>

void LoginExceptionMapper::handle_exceptions(std::function<void()>&& controllerImplementation,
                                             std::function<void(const drogon::HttpResponsePtr&)>& callback)
{
    try
    {
        controllerImplementation();
    }
    catch (SessionNotFoundException& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k404NotFound,
                "Session not found",
                e.what()
        );
        callback(response);
    }
    catch (InvalidChallengeResponseException& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k403Forbidden,
                "Invalid challenge response",
                e.what()
        );
        callback(response);
    }
    catch (UnauthorizedException& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k401Unauthorized,
                "Wrong credentials",
                e.what()
        );
        callback(response);
    }
}
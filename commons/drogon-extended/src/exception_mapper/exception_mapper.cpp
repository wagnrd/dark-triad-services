#include <drogon_extended/exception_mapper/exception_mapper.hpp>

std::shared_ptr<drogon::HttpResponse> ExceptionMapper::build_exception_response(drogon::HttpStatusCode statusCode,
                                                                                const std::string& error,
                                                                                const std::string& description)
{
    Json::Value responseBody;
    responseBody["error"] = error;
    responseBody["description"] = description;

    auto response = drogon::HttpResponse::newHttpJsonResponse(responseBody);
    response->setStatusCode(statusCode);

    return response;
}

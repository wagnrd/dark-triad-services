#include <drogon_extended/exception_mapper/exception_mapper_macros.hpp>

#include <include/service/characters/characters_service.hpp>
#include <include/service/characters/model/character.hpp>
#include <include/converter/character_converter.hpp>
#include "include/controller/private_api/private_characters_controller.hpp"

drogon::Task<> private_api::characters::get_character(drogon::HttpRequestPtr request,
                                                      std::function<void(const drogon::HttpResponsePtr&)> callback,
                                                      const std::string& characterName, const std::string& userId)
{
    try
    {
        SECURITY_GUARD(API_KEY(config->webServer->apiKey))

        auto character = co_await charactersService->get_character(userId, characterName);
        auto responseJson = CharacterConverter::to_json(character);
        callback(drogon::HttpResponse::newHttpJsonResponse(*responseJson));
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }
}

drogon::Task<void> private_api::characters::update_exp(drogon::HttpRequestPtr request,
                                                       std::function<void(const drogon::HttpResponsePtr&)> callback,
                                                       const std::string& characterName, uint32_t exp)
{
    try
    {
        SECURITY_GUARD(API_KEY(config->webServer->apiKey))

        charactersService->update_exp(characterName, exp);

        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::HttpStatusCode::k204NoContent);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }
}


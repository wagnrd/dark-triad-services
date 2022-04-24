#include <drogon_extended/exception_mapper/exception_mapper_macros.hpp>

#include <include/service/characters/characters_service.hpp>
#include <include/service/characters/model/character.hpp>
#include "include/factory/character_factory.hpp"
#include "include/controller/private_api/private_characters_controller.hpp"

drogon::Task<> private_api::characters::get_character(drogon::HttpRequestPtr request,
                                                      std::function<void(const drogon::HttpResponsePtr&)> callback,
                                                      const std::string& characterName)
{
    try
    {
        apiKeyGuard.check(request);

        auto character = co_await charactersService->get_character(characterName);
        auto responseJson = CharacterFactory::to_json(character);
        callback(drogon::HttpResponse::newHttpJsonResponse(*responseJson));
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }

    co_return;
}

drogon::Task<void> private_api::characters::update_exp(drogon::HttpRequestPtr request,
                                                       std::function<void(const drogon::HttpResponsePtr&)> callback,
                                                       const std::string& characterName, uint32_t exp)
{
    try
    {
        apiKeyGuard.check(request);

        charactersService->update_exp(characterName, exp);

        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::HttpStatusCode::k204NoContent);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }

    co_return;
}
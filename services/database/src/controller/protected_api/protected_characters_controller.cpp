#include <drogon_extended/exception_mapper/exception_mapper_macros.hpp>

#include "include/service/characters/characters_service.hpp"
#include "include/service/characters/model/character.hpp"
#include "include/controller/protected_api/protected_characters_controller.hpp"
#include "include/factory/character_factory.hpp"
#include "include/factory/character_creation_factory.hpp"

drogon::Task<> protected_api::characters::get_all_characters(drogon::HttpRequestPtr request,
                                                             std::function<void(
                                                                     const drogon::HttpResponsePtr&)> callback)
{
    try
    {
        auto decodedJwtToken = jwtTokenGuard.check(request);
        std::string userId = decodedJwtToken.get_payload_claim("email")
                                            .as_string();
        auto characters = co_await charactersService->all_characters(userId);

        Json::Value charactersJson;

        for (int i = 0; i < characters.size(); ++i)
            charactersJson[i] = *CharacterFactory::to_json(characters[i]);

        Json::Value charactersResponse;
        charactersResponse["characters"] = charactersJson;

        auto response = drogon::HttpResponse::newHttpJsonResponse(charactersResponse);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }

    co_return;
}

drogon::Task<> protected_api::characters::create_character(drogon::HttpRequestPtr request,
                                                           std::function<void(
                                                                   const drogon::HttpResponsePtr&)> callback)
{
    try
    {
        auto decodedJwtToken = jwtTokenGuard.check(request);

        auto character = CharacterCreationFactory::from_json(request->jsonObject());

        std::string userId = decodedJwtToken.get_payload_claim("email")
                                            .as_string();
        co_await charactersService->create_character(userId, character);

        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::HttpStatusCode::k201Created);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }

    co_return;
}

drogon::Task<> protected_api::characters::delete_character(drogon::HttpRequestPtr request,
                                                           std::function<void(const drogon::HttpResponsePtr&)> callback,
                                                           const std::string& characterName)
{
    try
    {
        auto decodedJwtToken = jwtTokenGuard.check(request);

        std::string userId = decodedJwtToken.get_payload_claim("email")
                                            .as_string();
        charactersService->delete_character(userId, characterName);

        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::HttpStatusCode::k204NoContent);
        callback(response);
    }
    catch (...)
    {
        HANDLE_GLOBAL_EXCEPTIONS
    }

    co_return;
}

drogon::Task<> protected_api::characters::delete_all_characters(drogon::HttpRequestPtr request,
                                                                std::function<void(
                                                                        const drogon::HttpResponsePtr&
                                                                )> callback)
{
    try
    {
        auto decodedJwtToken = jwtTokenGuard.check(request);

        auto userId = decodedJwtToken.get_payload_claim("email")
                                     .as_string();
        charactersService->delete_all_characters(userId);

        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::HttpStatusCode::k204NoContent);
        callback(response);
    }
    catch (...)
    {
        HANDLE_GLOBAL_EXCEPTIONS
    }

    co_return;
}

drogon::Task<> protected_api::characters::character_name_exists(drogon::HttpRequestPtr request,
                                                                std::function<void(
                                                                        const drogon::HttpResponsePtr&)> callback,
                                                                const std::string& characterName)
{
    try
    {
        jwtTokenGuard.check(request);

        bool characterNameExists = co_await charactersService->character_name_exists(characterName);
        auto response = drogon::HttpResponse::newHttpResponse();

        if (characterNameExists)
            response->setStatusCode(drogon::HttpStatusCode::k204NoContent);
        else
            response->setStatusCode(drogon::HttpStatusCode::k404NotFound);

        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }

    co_return;
}
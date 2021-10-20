#include <drogon_extended/exception_mapper/exception_mapper_macros.hpp>

#include <include/service/characters/characters_service.hpp>
#include <include/service/characters/model/character.hpp>
#include <include/converter/character_converter.hpp>
#include "include/controller/protected_api/protected_characters_controller.hpp"

void protected_api::characters::get_all_characters(const drogon::HttpRequestPtr& request,
                                                   std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    try
    {
        SECURITY_GUARD(JWT_TOKEN(publicKey))

        std::string userId = decodedJwtToken.get_payload_claim("email")
                                            .as_string();
        auto characters = charactersService->all_characters(userId);

        Json::Value charactersJson;

        for (int i = 0; i < characters.size(); ++i)
            charactersJson[i] = *CharacterConverter::to_json(characters[i]);

        Json::Value charactersResponse;
        charactersResponse["characters"] = charactersJson;

        auto response = drogon::HttpResponse::newHttpJsonResponse(charactersResponse);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }
}

void protected_api::characters::create_character(const drogon::HttpRequestPtr& request,
                                                 std::function<void(const drogon::HttpResponsePtr&)>&& callback)
{
    try
    {
        SECURITY_GUARD(JWT_TOKEN(publicKey))

        auto character = CharacterConverter::from_json(request->jsonObject());

        std::string userId = decodedJwtToken.get_payload_claim("email")
                                            .as_string();
        charactersService->create_character(userId, character);

        auto response = drogon::HttpResponse::newHttpResponse();
        response->setStatusCode(drogon::HttpStatusCode::k201Created);
        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }
}

void protected_api::characters::delete_character(const drogon::HttpRequestPtr& request,
                                                 std::function<void(const drogon::HttpResponsePtr&)>&& callback,
                                                 const std::string& characterName)
{
    try
    {
        SECURITY_GUARD(JWT_TOKEN(publicKey))

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
}

void protected_api::characters::character_name_exists(const drogon::HttpRequestPtr& request,
                                                      std::function<void(const drogon::HttpResponsePtr&)>&& callback,
                                                      const std::string& characterName)
{
    try
    {
        SECURITY_GUARD(JWT_TOKEN(publicKey))

        bool characterNameExists = charactersService->character_name_exists(characterName);
        auto response = drogon::HttpResponse::newHttpResponse();

        if (!characterNameExists)
            response->setStatusCode(drogon::HttpStatusCode::k404NotFound);

        callback(response);
    }
    catch (...)
    {
        HANDLE_CUSTOM_EXCEPTIONS(exceptionMapper)
    }
}


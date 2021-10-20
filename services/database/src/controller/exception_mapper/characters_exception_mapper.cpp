#include <include/service/characters/exception/character_not_found_exception.hpp>
#include <include/controller/exception_mapper/characters_exception_mapper.hpp>

void CharactersExceptionMapper::handle_exceptions(std::function<void()>&& controllerImplementation,
                                                  std::function<void(const drogon::HttpResponsePtr&)>& callback)
{
    try
    {
        controllerImplementation();
    }
    catch (CharacterNotFoundException& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k404NotFound,
                "Character(s) not found",
                e.what()
        );
        callback(response);
    }
    catch (drogon::orm::Failure& e)
    {
        LOG_ERROR << e.what();

        auto response = build_exception_response(
                drogon::HttpStatusCode::k400BadRequest,
                "Character creation failed",
                e.what()
        );
        callback(response);
    }
}

#include <fmt/format.h>

#include "include/service/characters/util/character_class.hpp"
#include "include/service/characters/characters_service.hpp"

drogon::Task<Character> CharactersService::get_character(const std::string& userId, const std::string& characterName)
{
    co_return co_await charactersDb->get_character(userId, characterName);
}

drogon::Task<std::vector<Character>> CharactersService::all_characters(const std::string& userId)
{
    co_return co_await charactersDb->all_characters(userId);
}

drogon::Task<> CharactersService::create_character(const std::string& userId, Character& character)
{
    if (CharacterClass::is_class_invalid(character.className))
        throw std::invalid_argument("Character class is invalid: '" + character.className + "'");

    check_character_name(character.name);

    // Don't allow the client (player) to preset experience points when creating a new character
    character.exp = 0;

    co_return co_await charactersDb->create_character(userId, character);
}

void CharactersService::delete_character(const std::string& userId, const std::string& characterName)
{
    charactersDb->delete_character(userId, characterName);
}

drogon::Task<bool> CharactersService::character_name_exists(const std::string& characterName)
{
    co_return co_await charactersDb->character_name_exists(characterName);
}

void CharactersService::update_exp(const std::string& characterName, uint32_t exp)
{
    charactersDb->update_exp(characterName, exp);
}

void CharactersService::check_character_name(const std::string& name)
{
    if (name.length() > 25)
    {
        auto errorDescription = fmt::format(
                "Character name '{}' is longer than 25 characters: {}",
                name,
                name.length()
        );
        throw std::invalid_argument(errorDescription);
    }

    if (name.length() < 2)
    {
        auto errorDescription = fmt::format(
                "Character name '{}' is shorter than 2 characters: {}",
                name,
                name.length()
        );
        throw std::invalid_argument(errorDescription);
    }

    if (!isalpha(name.front()))
        throw std::invalid_argument("Character name must have a alphabetic character as first character: " + name);

    auto characterNameIt = std::find_if(
            name.begin(),
            name.end(),
            [](char c) { return !(isalnum(c) || (c == ' ')); }
    );

    if (characterNameIt != name.end())
        throw std::invalid_argument("Character name is not alphanumeric: " + name);
}
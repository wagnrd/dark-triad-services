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
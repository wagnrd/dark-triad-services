#include "include/service/characters/characters_service.hpp"

drogon::Task<Character> CharactersService::get_character(const std::string& userId, const std::string& characterName)
{
    return charactersDb->get_character(userId, characterName);
}

drogon::Task<std::vector<Character>> CharactersService::all_characters(const std::string& userId)
{
    return charactersDb->all_characters(userId);
}

drogon::Task<> CharactersService::create_character(const std::string& userId, const Character& character)
{
    charactersDb->create_character(userId, character);
}

void CharactersService::delete_character(const std::string& userId, const std::string& characterName)
{
    charactersDb->delete_character(userId, characterName);
}

drogon::Task<bool> CharactersService::character_name_exists(const std::string& characterName)
{
    return charactersDb->character_name_exists(characterName);
}

void CharactersService::update_exp(const std::string& characterName, uint32_t exp)
{
    charactersDb->update_exp(characterName, exp);
}

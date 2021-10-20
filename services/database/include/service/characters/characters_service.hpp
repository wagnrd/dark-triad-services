#ifndef DATABASE_API_CHARACTERS_SERVICE_HPP
#define DATABASE_API_CHARACTERS_SERVICE_HPP

#include <drogon/drogon.h>
#include <drogon_extended/service/service.hpp>

#include <include/service/characters/model/character.hpp>
#include <include/database/characters_db.hpp>

class CharactersService: public Service<CharactersService> {

    CharactersDB* charactersDb = CharactersDB::get();

public:
    Character get_character(const std::string& userId, const std::string& characterName);
    std::vector<Character> all_characters(const std::string& userId);
    void create_character(const std::string& userId, const Character& character);
    void delete_character(const std::string& userId, const std::string& characterName);
    bool character_name_exists(const std::string& characterName);
    void update_exp(const std::string& characterName, uint32_t exp);
};

#endif //DATABASE_API_CHARACTERS_SERVICE_HPP

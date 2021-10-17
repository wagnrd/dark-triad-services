#ifndef DATABASE_API_CHARACTERS_DB_HPP
#define DATABASE_API_CHARACTERS_DB_HPP

#include <drogon/drogon.h>
#include <drogon_extended/service/service.hpp>

#include <include/service/characters/model/character.hpp>

class CharactersDB: public Service<CharactersDB> {

    std::shared_ptr<drogon::orm::DbClient> postgres = drogon::app().getDbClient();

public:
    Character get_character(const std::string& userId, const std::string& characterName);
    std::vector<Character> all_characters(const std::string& userId);
    void create_character(const std::string& userId, const Character& character);
    void delete_character(const std::string& userId, const std::string& characterName);
    void update_exp(const std::string& characterName, uint32_t exp);

    bool character_name_exists(const std::string& characterName);
private:
    Character build_character(const drogon::orm::Row& row);
};

#endif //DATABASE_API_CHARACTERS_DB_HPP

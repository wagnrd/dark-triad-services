#ifndef DARK_TRIAD_SERVICES_CHARACTERS_DB_HPP
#define DARK_TRIAD_SERVICES_CHARACTERS_DB_HPP

#include <drogon/drogon.h>
#include <drogon_extended/service/service.hpp>

#include <include/service/characters/model/character.hpp>

class CharactersDB: public Service<CharactersDB> {

    std::shared_ptr<drogon::orm::DbClient> postgres = drogon::app().getDbClient();

public:
    drogon::Task<Character> get_character(const std::string& userId, const std::string& characterName);
    drogon::Task<std::vector<Character>> all_characters(const std::string& userId);
    drogon::Task<> create_character(const std::string& userId, const Character& character);
    void delete_character(const std::string& userId, const std::string& characterName);
    void update_exp(const std::string& characterName, uint32_t exp);

    drogon::Task<bool> character_name_exists(const std::string& characterName);

private:
    Character build_character(const drogon::orm::Row& row);
};

#endif //DARK_TRIAD_SERVICES_CHARACTERS_DB_HPP

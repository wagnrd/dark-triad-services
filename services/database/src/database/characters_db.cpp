#include <fmt/color.h>

#include <include/service/characters/exception/character_not_found_exception.hpp>
#include "include/database/characters_db.hpp"

drogon::Task<Character> CharactersDB::get_character(const std::string& userId, const std::string& characterName)
{
    auto sql = fmt::format(
            "SELECT * FROM character WHERE user_id = '{}' AND name = '{}';",
            userId,
            characterName
    );

    auto rows = co_await postgres->execSqlCoro(sql);

    if (rows.empty())
        throw CharacterNotFoundException(userId);

    co_return build_character(rows[0]);
}

drogon::Task<std::vector<Character>> CharactersDB::all_characters(const std::string& userId)
{
    auto sql = fmt::format(
            "SELECT * FROM character WHERE user_id = '{}';",
            userId
    );
    auto rows = co_await postgres->execSqlCoro(sql);

    if (rows.empty())
        throw CharacterNotFoundException(userId);

    auto characters = std::vector<Character>(rows.size());

    for (int i = 0; i < rows.size(); ++i)
        characters[i] = build_character(rows[i]);

    co_return characters;
}

drogon::Task<> CharactersDB::create_character(const std::string& userId, const Character& character)
{
    auto sql = fmt::format(
            "INSERT INTO character (user_id, name, class) VALUES ('{}', '{}', '{}');",
            userId,
            character.name,
            character.className
    );
    co_await postgres->execSqlCoro(sql);
}

void CharactersDB::delete_character(const std::string& userId, const std::string& characterName)
{
    auto sql = fmt::format(
            "DELETE FROM character WHERE user_id = '{}' AND name = '{}';",
            userId,
            characterName
    );
    postgres->execSqlAsyncFuture(sql);
}

drogon::Task<bool> CharactersDB::character_name_exists(const std::string& characterName)
{
    auto sql = fmt::format(
            "SELECT * FROM character WHERE name = '{}';",
            characterName
    );
    auto rows = co_await postgres->execSqlCoro(sql);

    co_return !rows.empty();
}

void CharactersDB::update_exp(const std::string& characterName, uint32_t exp)
{
    auto sql = fmt::format(
            "UPDATE character SET exp = {} WHERE name = '{}'",
            exp,
            characterName
    );
    postgres->execSqlAsyncFuture(sql);
}

Character CharactersDB::build_character(const drogon::orm::Row& row)
{
    return Character(
            row["name"].c_str(),
            row["class"].c_str(),
            row["exp"].as<uint32_t>()
    );
}


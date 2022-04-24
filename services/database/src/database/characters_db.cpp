#include <fmt/format.h>

#include <include/service/characters/exception/no_characters_found_exception.hpp>
#include "include/service/characters/exception/character_not_found_exception.hpp"
#include "include/factory/util/characters_db_color_util.hpp"
#include "include/factory/display_character_factory.hpp"
#include "include/factory/character_factory.hpp"
#include "include/database/characters_db.hpp"

drogon::Task<Character> CharactersDB::get_character(const std::string& name)
{
    auto sql = fmt::format(
            R"(
                SELECT *
                FROM character,
                     appearance,
                     equipment
                WHERE character.name = '{}' AND
                      character.name = appearance.character AND
                      character.name = equipment.character;
            )",
            name
    );

    auto rows = co_await postgres->execSqlCoro(sql);

    if (rows.empty())
        throw CharacterNotFoundException(name);

    co_return CharacterFactory::from_orm(rows[0]);
}

drogon::Task<std::vector<DisplayCharacter>> CharactersDB::get_all_characters(const std::string& userId)
{
    auto sql = fmt::format(
            R"(
                SELECT character.*,
                       appearance.*,
                       equipment.*,
                       statistic.last_used_timestamp
                FROM character,
                     appearance,
                     equipment,
                     statistic
                WHERE character.user_id = '{}' AND
                      character.name = appearance.character AND
                      character.name = equipment.character AND
                      character.name = statistic.character;
            )",
            userId
    );
    auto rows = co_await postgres->execSqlCoro(sql);

    if (rows.empty())
        throw NoCharactersFoundException(userId);

    auto characters = std::vector<DisplayCharacter>(rows.size());

    for (int i = 0; i < rows.size(); ++i)
        characters[i] = DisplayCharacterFactory::from_orm(rows[i]);

    co_return characters;
}

drogon::Task<> CharactersDB::create_character(const std::string& userId, const DisplayCharacter& character)
{
    auto currentTimestamp = std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
    ).count();

    auto encodedSkinColor = CharactersDBColorUtil::encode_color(character.appearance.skinColor);
    auto encodedEyeColor = CharactersDBColorUtil::encode_color(character.appearance.eyeColor);
    auto encodedScarColor = CharactersDBColorUtil::encode_color(character.appearance.scarColor);
    auto encodedTattooColor = CharactersDBColorUtil::encode_color(character.appearance.tattooColor);
    auto encodedHairColor = CharactersDBColorUtil::encode_color(character.appearance.hairColor);

    auto sqlCreateBaseCharacter = fmt::format(
            R"(
                INSERT INTO character
                    (user_id, name, class)
                VALUES
                    ('{}', '{}', '{}');
            )",
            userId,
            character.name,
            character.className
    );

    auto sqlCreateAppearance = fmt::format(
            R"(
                INSERT INTO appearance
                    (character, gender, height, face_id, ears_id, hair_id, eyebrows_id, facial_hair_id, skin_color, eye_color, scar_color, tattoo_color, hair_color)
                VALUES
                    ('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}');
            )",
            character.name,
            character.appearance.gender,
            character.appearance.height,
            character.appearance.faceId,
            character.appearance.earsId,
            character.appearance.hairId,
            character.appearance.eyebrowsId,
            character.appearance.facialHairId,
            encodedSkinColor,
            encodedEyeColor,
            encodedScarColor,
            encodedTattooColor,
            encodedHairColor
    );

    auto sqlCreateEquipment = fmt::format(
            R"(
                INSERT INTO equipment
                    (character, main_weapon, support_weapon, head_armour, torso_armour, shoulder_armour, arm_armour, leg_armour, foot_armour)
                VALUES
                    ('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}');
            )",
            character.name,
            character.equipment.mainWeapon,
            character.equipment.supportWeapon,
            character.equipment.headArmour,
            character.equipment.torsoArmour,
            character.equipment.shoulderArmour,
            character.equipment.armArmour,
            character.equipment.legArmour,
            character.equipment.footArmour
    );

    auto sqlCreateStatistic = fmt::format(
            R"(
                INSERT INTO statistic
                    (character, created_timestamp, last_used_timestamp)
                VALUES
                    ('{}', '{}', '{}');
            )",
            character.name,
            currentTimestamp,
            currentTimestamp
    );

    auto transaction = postgres->newTransaction();
    co_await transaction->execSqlCoro(sqlCreateBaseCharacter);
    co_await transaction->execSqlCoro(sqlCreateAppearance);
    co_await transaction->execSqlCoro(sqlCreateEquipment);
    co_await transaction->execSqlCoro(sqlCreateStatistic);
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

void CharactersDB::delete_all_characters(const std::string& userId)
{
    auto sql = fmt::format(
            "DELETE FROM character WHERE user_id = '{}'",
            userId
    );
    postgres->execSqlAsyncFuture(sql);
}

drogon::Task<bool> CharactersDB::character_name_exists(const std::string& name)
{
    auto sql = fmt::format(
            "SELECT * FROM character WHERE name = '{}';",
            name
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
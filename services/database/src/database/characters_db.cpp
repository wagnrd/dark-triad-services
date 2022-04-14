#include <fmt/format.h>

#include <include/service/characters/exception/character_not_found_exception.hpp>
#include "include/database/characters_db.hpp"
#include "include/database/utils/characters_db_color_util.hpp"

drogon::Task<Character> CharactersDB::get_character(const std::string& userId, const std::string& characterName)
{
    auto sql = fmt::format(
            R"(
                SELECT * FROM character, appearance, equipment
                WHERE character.user_id = '{}' AND
                      character.name = '{}' AND
                      character.name = appearance.character AND
                      character.name = equipment.character;
                )",
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
            R"(
                SELECT * FROM character, appearance, equipment
                WHERE character.user_id = '{}' AND
                      character.name = appearance.character AND
                      character.name = equipment.character;
            )",
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
    auto encodedSkinColor = CharactersDBColorUtil::encode_color(character.appearance.skinColor);
    auto encodedEyeColor = CharactersDBColorUtil::encode_color(character.appearance.eyeColor);
    auto encodedScarColor = CharactersDBColorUtil::encode_color(character.appearance.scarColor);
    auto encodedTattooColor = CharactersDBColorUtil::encode_color(character.appearance.tattooColor);
    auto encodedHairColor = CharactersDBColorUtil::encode_color(character.appearance.hairColor);

    auto sql = fmt::format(
            R"(
                WITH tmp AS (
                    INSERT INTO character
                        (user_id, name, class)
                    VALUES
                        ('{}', '{}', '{}')
                )
                INSERT INTO appearance
	                (character, gender, height, face_id, ears_id, hair_id, eyebrows_id, facial_hair_id, skin_color, eye_color, scar_color, tattoo_color, hair_color)
                VALUES
	                ('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}');
                INSERT INTO equipment
                    (character, main_weapon, support_weapon, head_armour, torso_armour, shoulder_armour, arm_armour, leg_armour, foot_armour)
                VALUES
                    ('{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}', '{}');
            )",
            userId,
            character.name,
            character.className,
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
            encodedHairColor,
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
    return Character{
            .name = row["name"].c_str(),
            .className = row["class"].c_str(),
            .exp = row["exp"].as<uint32_t>(),
            .appearance{
                    .gender = row["gender"].c_str(),
                    .height = row["height"].as<double>(),
                    .faceId = row["face_id"].as<int>(),
                    .earsId = row["ears_id"].as<int>(),
                    .hairId = row["hair_id"].as<int>(),
                    .eyebrowsId = row["eyebrows_id"].as<int>(),
                    .facialHairId = row["facial_hair_id"].as<int>(),
                    .skinColor = CharactersDBColorUtil::decode_color(row["skin_color"].as<int>()),
                    .eyeColor = CharactersDBColorUtil::decode_color(row["eye_color"].as<int>()),
                    .scarColor = CharactersDBColorUtil::decode_color(row["scar_color"].as<int>()),
                    .tattooColor = CharactersDBColorUtil::decode_color(row["tattoo_color"].as<int>()),
                    .hairColor = CharactersDBColorUtil::decode_color(row["hair_color"].as<int>())
            },
            .equipment {
                .mainWeapon = row["main_weapon"].c_str(),
                .supportWeapon = row["support_weapon"].c_str(),
                .headArmour = row["head_armour"].c_str(),
                .torsoArmour = row["torso_armour"].c_str(),
                .shoulderArmour = row["shoulder_armour"].c_str(),
                .armArmour = row["arm_armour"].c_str(),
                .legArmour = row["leg_armour"].c_str(),
                .footArmour = row["foot_armour"].c_str(),
            }
    };
}
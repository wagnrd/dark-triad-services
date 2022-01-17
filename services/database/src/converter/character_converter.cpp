#include <drogon_extended/json_mapper/json_converter.hpp>

#include <include/converter/character_converter.hpp>
#include <include/converter/appearance_converter.hpp>

Character CharacterConverter::from_json(const std::shared_ptr<Json::Value>& json)
{
    Character character;
    character.name = JsonConverter::check(json, "name").asString();
    character.className = JsonConverter::check(json, "className").asString();
    character.exp = json->get("exp", 0).asUInt();
    const auto& appearanceJson = JsonConverter::check(json, "appearance");
    character.appearance = AppearanceConverter::from_json(appearanceJson);

    return character;
}

std::shared_ptr<Json::Value> CharacterConverter::to_json(const Character& character)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["name"] = character.name;
    (*json)["className"] = character.className;
    (*json)["exp"] = character.exp;
    (*json)["appearance"] = *AppearanceConverter::to_json(character.appearance);

    return json;
}

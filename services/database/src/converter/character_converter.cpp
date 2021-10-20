#include <drogon_extended/json_mapper/json_converter.hpp>

#include <include/converter/character_converter.hpp>

Character CharacterConverter::from_json(const std::shared_ptr<Json::Value>& json)
{
    auto name = JsonConverter::check(json, "name").asString();
    auto className = JsonConverter::check(json, "className").asString();
    auto exp = json->get("exp", 0).asUInt();

    return Character(std::move(name), std::move(className), exp);
}

std::shared_ptr<Json::Value> CharacterConverter::to_json(const Character& character)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["name"] = character.name;
    (*json)["className"] = character.className;
    (*json)["exp"] = character.exp;

    return json;
}

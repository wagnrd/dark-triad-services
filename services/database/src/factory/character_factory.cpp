#include "drogon_extended/json_mapper/json_converter.hpp"

#include <include/factory/character_factory.hpp>
#include <include/factory/appearance_factory.hpp>
#include <include/factory/equipment_factory.hpp>

std::shared_ptr<Json::Value> CharacterFactory::to_json(const Character& character)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["name"] = character.name;
    (*json)["className"] = character.className;
    (*json)["exp"] = character.exp;
    (*json)["appearance"] = *AppearanceFactory::to_json(character.appearance);
    (*json)["equipment"] = *EquipmentFactory::to_json(character.equipment);

    return json;
}

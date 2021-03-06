#include "include/factory/character_factory.hpp"
#include "include/factory/appearance_factory.hpp"
#include "include/factory/equipment_factory.hpp"

std::shared_ptr<Json::Value> CharacterFactory::to_json(const Character& character)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["name"] = character.name;
    (*json)["className"] = character.className;
    (*json)["exp"] = static_cast<Json::Value::UInt64>(character.exp);
    (*json)["appearance"] = *AppearanceFactory::to_json(character.appearance);
    (*json)["equipment"] = *EquipmentFactory::to_json(character.equipment);

    return json;
}

Character CharacterFactory::from_orm(const drogon::orm::Row& row)
{
    return Character{
            .name = row["name"].c_str(),
            .className = row["class"].c_str(),
            .exp = row["exp"].as<uint64_t>(),
            .appearance = AppearanceFactory::from_orm(row),
            .equipment = EquipmentFactory::from_orm(row)
    };
}
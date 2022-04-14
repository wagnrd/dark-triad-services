#include "drogon_extended/json_mapper/json_converter.hpp"

#include <include/factory/character_creation_factory.hpp>
#include <include/factory/appearance_factory.hpp>

CharacterCreation CharacterCreationFactory::from_json(const std::shared_ptr<Json::Value>& json)
{
    CharacterCreation characterCreation;
    characterCreation.name = JsonConverter::check(json, "name").asString();
    characterCreation.className = JsonConverter::check(json, "className").asString();
    const auto& appearanceJson = JsonConverter::check(json, "appearance");
    characterCreation.appearance = AppearanceFactory::from_json(appearanceJson);

    return characterCreation;
}

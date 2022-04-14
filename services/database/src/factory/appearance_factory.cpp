#include <drogon_extended/json_mapper/json_converter.hpp>
#include <include/factory/color_factory.hpp>

#include "include/factory/appearance_factory.hpp"

Appearance AppearanceFactory::from_json(const std::shared_ptr<Json::Value>& jsonPtr)
{
    const auto& json = JsonConverter::check_root(jsonPtr);
    return AppearanceFactory::from_json(json);
}

Appearance AppearanceFactory::from_json(const Json::Value& json)
{
    Appearance appearance;
    appearance.gender = JsonConverter::check(json, "gender").asString();
    appearance.height = JsonConverter::check(json, "height").asDouble();
    appearance.faceId = JsonConverter::check(json, "faceId").asInt();
    appearance.earsId = JsonConverter::check(json, "earsId").asInt();
    appearance.hairId = JsonConverter::check(json, "hairId").asInt();
    appearance.eyebrowsId = JsonConverter::check(json, "eyebrowsId").asInt();
    appearance.facialHairId = JsonConverter::check(json, "facialHairId").asInt();
    const auto& skinColorJson = JsonConverter::check(json, "skinColor");
    appearance.skinColor = ColorFactory::from_json(skinColorJson);
    const auto& eyeColorJson = JsonConverter::check(json, "eyeColor");
    appearance.eyeColor = ColorFactory::from_json(eyeColorJson);
    const auto& scarColorJson = JsonConverter::check(json, "scarColor");
    appearance.scarColor = ColorFactory::from_json(scarColorJson);
    const auto& tattooColorJson = JsonConverter::check(json, "tattooColor");
    appearance.tattooColor = ColorFactory::from_json(tattooColorJson);
    const auto& hairColorJson = JsonConverter::check(json, "hairColor");
    appearance.hairColor = ColorFactory::from_json(hairColorJson);

    return appearance;
}

std::shared_ptr<Json::Value> AppearanceFactory::to_json(const Appearance& appearance)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["gender"] = appearance.gender;
    (*json)["height"] = appearance.height;
    (*json)["faceId"] = appearance.faceId;
    (*json)["earsId"] = appearance.earsId;
    (*json)["hairId"] = appearance.hairId;
    (*json)["eyebrowsId"] = appearance.eyebrowsId;
    (*json)["facialHairId"] = appearance.facialHairId;
    (*json)["skinColor"] = *ColorFactory::to_json(appearance.skinColor);
    (*json)["eyeColor"] = *ColorFactory::to_json(appearance.eyeColor);
    (*json)["scarColor"] = *ColorFactory::to_json(appearance.scarColor);
    (*json)["tattooColor"] = *ColorFactory::to_json(appearance.tattooColor);
    (*json)["hairColor"] = *ColorFactory::to_json(appearance.hairColor);

    return json;
}

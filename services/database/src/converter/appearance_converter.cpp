#include <drogon_extended/json_mapper/json_converter.hpp>
#include <include/converter/color_converter.hpp>

#include "include/converter/appearance_converter.hpp"

Appearance AppearanceConverter::from_json(const std::shared_ptr<Json::Value>& jsonPtr)
{
    const auto& json = JsonConverter::check_root(jsonPtr);
    return AppearanceConverter::from_json(json);
}

Appearance AppearanceConverter::from_json(const Json::Value& json)
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
    appearance.skinColor = ColorConverter::from_json(skinColorJson);
    const auto& eyeColorJson = JsonConverter::check(json, "eyeColor");
    appearance.eyeColor = ColorConverter::from_json(eyeColorJson);
    const auto& scarColorJson = JsonConverter::check(json, "scarColor");
    appearance.scarColor = ColorConverter::from_json(scarColorJson);
    const auto& tattooColorJson = JsonConverter::check(json, "tattooColor");
    appearance.tattooColor = ColorConverter::from_json(tattooColorJson);
    const auto& hairColorJson = JsonConverter::check(json, "hairColor");
    appearance.hairColor = ColorConverter::from_json(hairColorJson);

    return appearance;
}

std::shared_ptr<Json::Value> AppearanceConverter::to_json(const Appearance& appearance)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["gender"] = appearance.gender;
    (*json)["height"] = appearance.height;
    (*json)["faceId"] = appearance.faceId;
    (*json)["earsId"] = appearance.earsId;
    (*json)["hairId"] = appearance.hairId;
    (*json)["eyebrowsId"] = appearance.eyebrowsId;
    (*json)["facial_hairId"] = appearance.facialHairId;
    (*json)["skinColor"] = *ColorConverter::to_json(appearance.skinColor);
    (*json)["eyeColor"] = *ColorConverter::to_json(appearance.eyeColor);
    (*json)["scarColor"] = *ColorConverter::to_json(appearance.scarColor);
    (*json)["tattooColor"] = *ColorConverter::to_json(appearance.tattooColor);
    (*json)["hairColor"] = *ColorConverter::to_json(appearance.hairColor);

    return json;
}

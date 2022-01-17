#include <drogon_extended/json_mapper/json_converter.hpp>

#include "include/converter/color_converter.hpp"

Color ColorConverter::from_json(const std::shared_ptr<Json::Value>& jsonPtr)
{
    const auto& json = JsonConverter::check_root(jsonPtr);
    return ColorConverter::from_json(json);
}

Color ColorConverter::from_json(const Json::Value& json)
{
    Color color;
    color.r = JsonConverter::check(json, "r").asDouble();
    color.g = JsonConverter::check(json, "g").asDouble();
    color.b = JsonConverter::check(json, "b").asDouble();
    color.a = JsonConverter::check(json, "a").asDouble();

    return color;
}

std::shared_ptr<Json::Value> ColorConverter::to_json(const Color& color)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["r"] = color.r;
    (*json)["g"] = color.g;
    (*json)["b"] = color.b;
    (*json)["a"] = color.a;

    return json;
}


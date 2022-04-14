#include <drogon_extended/json_mapper/json_converter.hpp>

#include "include/factory/color_factory.hpp"

Color ColorFactory::from_json(const std::shared_ptr<Json::Value>& jsonPtr)
{
    const auto& json = JsonConverter::check_root(jsonPtr);
    return ColorFactory::from_json(json);
}

Color ColorFactory::from_json(const Json::Value& json)
{
    Color color;
    color.r = JsonConverter::check(json, "r").asDouble();
    color.g = JsonConverter::check(json, "g").asDouble();
    color.b = JsonConverter::check(json, "b").asDouble();
    color.a = JsonConverter::check(json, "a").asDouble();

    return color;
}

std::shared_ptr<Json::Value> ColorFactory::to_json(const Color& color)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["r"] = color.r;
    (*json)["g"] = color.g;
    (*json)["b"] = color.b;
    (*json)["a"] = color.a;

    return json;
}


#ifndef DARK_TRIAD_SERVICES_COLOR_FACTORY_HPP
#define DARK_TRIAD_SERVICES_COLOR_FACTORY_HPP

#include <memory>
#include <json/value.h>

#include <include/service/characters/model/color.hpp>

class ColorFactory {
public:
    static Color from_json(const std::shared_ptr<Json::Value>& jsonPtr);
    static Color from_json(const Json::Value& json);
    static std::shared_ptr<Json::Value> to_json(const Color& color);
};

#endif //DARK_TRIAD_SERVICES_COLOR_FACTORY_HPP

#ifndef DARK_TRIAD_SERVICES_APPEARANCE_FACTORY_HPP
#define DARK_TRIAD_SERVICES_APPEARANCE_FACTORY_HPP

#include <memory>
#include <json/value.h>

#include <include/service/characters/model/display_character.hpp>
#include "drogon/drogon.h"

class AppearanceFactory {
public:
    static Appearance from_json(const std::shared_ptr<Json::Value>& jsonPtr);
    static Appearance from_json(const Json::Value& json);
    static std::shared_ptr<Json::Value> to_json(const Appearance& appearance);

    static Appearance from_orm(const drogon::orm::Row& row);
};

#endif //DARK_TRIAD_SERVICES_APPEARANCE_FACTORY_HPP
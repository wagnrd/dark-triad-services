#ifndef DARK_TRIAD_SERVICES_DISPLAY_CHARACTER_FACTORY_HPP
#define DARK_TRIAD_SERVICES_DISPLAY_CHARACTER_FACTORY_HPP

#include <memory>
#include <json/value.h>

#include "drogon/drogon.h"

#include <include/service/characters/model/display_character.hpp>

class DisplayCharacterFactory {
public:
    static std::shared_ptr<Json::Value> to_json(const DisplayCharacter& character);
    static DisplayCharacter from_orm(const drogon::orm::Row& row);
};

#endif //DARK_TRIAD_SERVICES_DISPLAY_CHARACTER_FACTORY_HPP
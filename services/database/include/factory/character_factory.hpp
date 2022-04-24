#ifndef DARK_TRIAD_SERVICES_CHARACTER_FACTORY_HPP
#define DARK_TRIAD_SERVICES_CHARACTER_FACTORY_HPP

#include <memory>
#include <json/value.h>

#include "drogon/drogon.h"

#include <include/service/characters/model/character.hpp>

class CharacterFactory {
public:
    static std::shared_ptr<Json::Value> to_json(const Character& character);
    static Character from_orm(const drogon::orm::Row& row);
};

#endif //DARK_TRIAD_SERVICES_CHARACTER_FACTORY_HPP
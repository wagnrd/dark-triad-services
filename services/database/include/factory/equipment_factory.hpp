#ifndef DARK_TRIAD_SERVICES_EQUIPMENT_FACTORY_HPP
#define DARK_TRIAD_SERVICES_EQUIPMENT_FACTORY_HPP

#include <memory>
#include <json/value.h>
#include <drogon/drogon.h>

#include "include/service/characters/model/display_character.hpp"

class EquipmentFactory {
public:
    static std::shared_ptr<Json::Value> to_json(const Equipment& equipment);
    static Equipment from_orm(const drogon::orm::Row& row);
};

#endif //DARK_TRIAD_SERVICES_EQUIPMENT_FACTORY_HPP
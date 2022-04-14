#ifndef DARK_TRIAD_SERVICES_EQUIPMENT_FACTORY_HPP
#define DARK_TRIAD_SERVICES_EQUIPMENT_FACTORY_HPP

#include <memory>
#include <json/value.h>

#include "include/service/characters/model/character.hpp"

class EquipmentFactory {
public:
    static std::shared_ptr<Json::Value> to_json(const Equipment& equipment);
};

#endif //DARK_TRIAD_SERVICES_EQUIPMENT_FACTORY_HPP

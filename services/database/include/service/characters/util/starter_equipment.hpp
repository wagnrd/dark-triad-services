#ifndef DARK_TRIAD_SERVICES_STARTER_EQUIPMENT_HPP
#define DARK_TRIAD_SERVICES_STARTER_EQUIPMENT_HPP

#include "include/service/characters/model/equipment.hpp"

class StarterEquipment {
public:
    static Equipment create(std::string_view characterClass);

private:
    static Equipment create_heavy_armour();
    static Equipment create_medium_armour();

    static void add_warrior_weapons(Equipment& equipment);
    static void add_archer_weapons(Equipment& equipment);
};

#endif //DARK_TRIAD_SERVICES_STARTER_EQUIPMENT_HPP

#include <stdexcept>
#include "include/service/characters/util/character_class.hpp"
#include "include/service/characters/util/starter_equipment.hpp"

Equipment StarterEquipment::create(std::string_view characterClass)
{
    if (characterClass == CharacterClass::warrior)
    {
        auto equipment = create_heavy_armour();
        add_warrior_weapons(equipment);
        return equipment;
    }

    if (characterClass == CharacterClass::archer)
    {
        auto equipment = create_medium_armour();
        add_archer_weapons(equipment);
        return equipment;
    }

    throw std::invalid_argument("Character class is invalid: '" + std::string(characterClass) + "'");
}

Equipment StarterEquipment::create_heavy_armour()
{
    return Equipment{
            .torsoArmour = "Recruit Chestplate",
            .armArmour = "Recruit Gloves",
            .legArmour = "Recruit Legwear",
            .footArmour = "Recruit Boots"
    };
}

Equipment StarterEquipment::create_medium_armour()
{
    return Equipment{
            .torsoArmour = "Strayer Jacket",
            .armArmour = "Strayer Gloves",
            .legArmour = "Strayer Trousers",
            .footArmour = "Strayer Boots"
    };
}

void StarterEquipment::add_warrior_weapons(Equipment& equipment)
{
    equipment.mainWeapon = "Shortsword";
    equipment.supportWeapon = "Wooden Heater Shield";
}

void StarterEquipment::add_archer_weapons(Equipment& equipment)
{
    equipment.mainWeapon = "Wooden Bow";
    equipment.supportWeapon = "Wooden Arrows";
}

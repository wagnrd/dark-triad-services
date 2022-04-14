#ifndef DARK_TRIAD_SERVICES_EQUIPMENT_HPP
#define DARK_TRIAD_SERVICES_EQUIPMENT_HPP

#include <string>

#include "color.hpp"

class Equipment {
public:
    std::string mainWeapon{};
    std::string supportWeapon{};
    std::string headArmour{};
    std::string torsoArmour{};
    std::string shoulderArmour{};
    std::string armArmour{};
    std::string legArmour{};
    std::string footArmour{};
};

#endif //DARK_TRIAD_SERVICES_EQUIPMENT_HPP

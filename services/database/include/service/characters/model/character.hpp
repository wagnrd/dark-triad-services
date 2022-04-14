#ifndef DARK_TRIAD_SERVICES_CHARACTER_HPP
#define DARK_TRIAD_SERVICES_CHARACTER_HPP

#include <string>
#include <utility>

#include "appearance.hpp"
#include "equipment.hpp"

class Character {
public:
    std::string name{};
    std::string className{};
    uint32_t exp{};
    Appearance appearance{};
    Equipment equipment{};
};

#endif //DARK_TRIAD_SERVICES_CHARACTER_HPP
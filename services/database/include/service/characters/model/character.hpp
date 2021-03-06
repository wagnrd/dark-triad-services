#ifndef DARK_TRIAD_SERVICES_CHARACTER_HPP
#define DARK_TRIAD_SERVICES_CHARACTER_HPP

#include "appearance.hpp"
#include "equipment.hpp"
#include "statistic.hpp"

class Character {
public:
    std::string name{};
    std::string className{};
    uint64_t exp{};
    Appearance appearance{};
    Equipment equipment{};
};

#endif //DARK_TRIAD_SERVICES_CHARACTER_HPP
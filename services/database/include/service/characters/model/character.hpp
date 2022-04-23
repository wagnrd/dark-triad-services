#ifndef DARK_TRIAD_SERVICES_CHARACTER_HPP
#define DARK_TRIAD_SERVICES_CHARACTER_HPP

#include <string>
#include <utility>

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
    Statistic statistic{};
};

#endif //DARK_TRIAD_SERVICES_CHARACTER_HPP
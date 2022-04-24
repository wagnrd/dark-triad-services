#ifndef DARK_TRIAD_SERVICES_DISPLAY_CHARACTER_HPP
#define DARK_TRIAD_SERVICES_DISPLAY_CHARACTER_HPP

#include "appearance.hpp"
#include "equipment.hpp"
#include "statistic.hpp"

class DisplayCharacter {
public:
    uint64_t lastUsedTimestamp{};
    std::string name{};
    std::string className{};
    uint64_t exp{};
    Appearance appearance{};
    Equipment equipment{};
};

#endif //DARK_TRIAD_SERVICES_DISPLAY_CHARACTER_HPP
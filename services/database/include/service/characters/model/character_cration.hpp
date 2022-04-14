#ifndef DARK_TRIAD_SERVICES_CHARACTER_CREATION_HPP
#define DARK_TRIAD_SERVICES_CHARACTER_CREATION_HPP

#include <string>
#include <utility>

#include "appearance.hpp"

class CharacterCreation {
public:
    std::string name{};
    std::string className{};
    Appearance appearance{};
};

#endif //DARK_TRIAD_SERVICES_CHARACTER_CREATION_HPP
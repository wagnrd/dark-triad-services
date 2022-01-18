#ifndef DATABASE_API_CHARACTER_HPP
#define DATABASE_API_CHARACTER_HPP

#include <string>
#include <utility>

#include "character_class.hpp"
#include "appearance.hpp"

class Character {
public:
    std::string name{};
    std::string className{};
    uint32_t exp{};
    Appearance appearance{};
};

#endif //DATABASE_API_CHARACTER_HPP

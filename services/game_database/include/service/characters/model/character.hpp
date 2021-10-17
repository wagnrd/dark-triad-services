#ifndef DATABASE_API_CHARACTER_HPP
#define DATABASE_API_CHARACTER_HPP

#include <string>
#include <utility>
#include "character_class.hpp"

class Character {
public:
    std::string name{};
    std::string className{};
    uint32_t exp{};

    Character() = default;

    explicit Character(std::string name, std::string className, uint32_t exp)
            : name(std::move(name)),
              className(std::move(className)),
              exp(exp)
    {}
};

#endif //DATABASE_API_CHARACTER_HPP

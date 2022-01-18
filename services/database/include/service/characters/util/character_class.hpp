#ifndef DATABASE_API_CHARACTER_CLASS_HPP
#define DATABASE_API_CHARACTER_CLASS_HPP

#include <string>
#include <utility>

class CharacterClass {
public:
    static inline const std::string wizard = "Wizard";
    static inline const std::string archer = "Archer";
    static inline const std::string warrior = "Warrior";
    static inline const std::string rogue = "Rogue";

    static bool is_class_invalid(std::string_view className);
};

#endif //DATABASE_API_CHARACTER_CLASS_HPP
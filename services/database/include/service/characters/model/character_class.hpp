#ifndef DATABASE_API_CHARACTER_CLASS_HPP
#define DATABASE_API_CHARACTER_CLASS_HPP

#include <string>
#include <utility>

class CharacterClass {

public:
    enum class Type {
        WIZARD,
        ARCHER,
        WARRIOR,
        ROGUE,
        UNKNOWN
    };

    Type value;

    explicit CharacterClass(const std::string& value)
    {
        if (value == "wizard")
            this->value = CharacterClass::Type::WIZARD;
        else if (value == "archer")
            this->value = CharacterClass::Type::ARCHER;
        else if (value == "warrior")
            this->value = CharacterClass::Type::WARRIOR;
        else if (value == "rogue")
            this->value = CharacterClass::Type::ROGUE;
        else
            this->value = CharacterClass::Type::UNKNOWN;
    }
};

#endif //DATABASE_API_CHARACTER_CLASS_HPP

#include "include/service/characters/util/character_class.hpp"

bool CharacterClass::is_class_invalid(std::string_view className)
{
    return className != wizard &&
           className != archer &&
           className != warrior &&
           className != rogue;
}
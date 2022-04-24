#include "include/service/characters/exception/character_not_found_exception.hpp"

CharacterNotFoundException::CharacterNotFoundException(const std::string& name)
        : runtime_error("Character not found with name '" + name + "'")
{}
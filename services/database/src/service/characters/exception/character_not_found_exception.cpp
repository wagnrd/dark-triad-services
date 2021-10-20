#include "include/service/characters/exception/character_not_found_exception.hpp"

CharacterNotFoundException::CharacterNotFoundException(const std::string& userId)
        : runtime_error("No character found for user '" + userId + "'")
{}

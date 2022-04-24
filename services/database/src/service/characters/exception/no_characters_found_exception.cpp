#include "include/service/characters/exception/no_characters_found_exception.hpp"

NoCharactersFoundException::NoCharactersFoundException(const std::string& userId)
        : runtime_error("No character found for user '" + userId + "'")
{}
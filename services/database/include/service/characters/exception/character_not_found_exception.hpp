#ifndef DARK_TRIAD_SERVICES_CHARACTER_NOT_FOUND_EXCEPTION_HPP
#define DARK_TRIAD_SERVICES_CHARACTER_NOT_FOUND_EXCEPTION_HPP

#include <stdexcept>

class CharacterNotFoundException: public std::runtime_error {
public:
    explicit CharacterNotFoundException(const std::string& name);
};

#endif //DARK_TRIAD_SERVICES_CHARACTER_NOT_FOUND_EXCEPTION_HPP
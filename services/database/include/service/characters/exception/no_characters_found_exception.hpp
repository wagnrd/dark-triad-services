#ifndef DARK_TRIAD_SERVICES_NO_CHARACTERS_FOUND_EXCEPTION_HPP
#define DARK_TRIAD_SERVICES_NO_CHARACTERS_FOUND_EXCEPTION_HPP

#include <stdexcept>

class NoCharactersFoundException: public std::runtime_error {
public:
    explicit NoCharactersFoundException(const std::string& arg);
};

#endif //DARK_TRIAD_SERVICES_NO_CHARACTERS_FOUND_EXCEPTION_HPP
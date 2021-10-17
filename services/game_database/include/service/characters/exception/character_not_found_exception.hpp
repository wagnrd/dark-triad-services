#ifndef DATABASE_API_CHARACTER_NOT_FOUND_EXCEPTION_HPP
#define DATABASE_API_CHARACTER_NOT_FOUND_EXCEPTION_HPP

#include <stdexcept>

class CharacterNotFoundException: public std::runtime_error {
public:
    explicit CharacterNotFoundException(const std::string& arg);
};

#endif //DATABASE_API_CHARACTER_NOT_FOUND_EXCEPTION_HPP

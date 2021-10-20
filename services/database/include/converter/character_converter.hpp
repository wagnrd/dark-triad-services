#ifndef DARK_TRIAD_DATABASE_API_CHARACTER_CONVERTER_HPP
#define DARK_TRIAD_DATABASE_API_CHARACTER_CONVERTER_HPP

#include <memory>
#include <json/value.h>

#include <include/service/characters/model/character.hpp>

class CharacterConverter {
public:
    static Character from_json(const std::shared_ptr<Json::Value>& json);
    static std::shared_ptr<Json::Value> to_json(const Character& character);
};

#endif //DARK_TRIAD_DATABASE_API_CHARACTER_CONVERTER_HPP

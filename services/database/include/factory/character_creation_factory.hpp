#ifndef DARK_TRIAD_SERVICES_CHARACTER_CREATION_FACTORY_HPP
#define DARK_TRIAD_SERVICES_CHARACTER_CREATION_FACTORY_HPP

#include <memory>
#include <json/value.h>

#include <include/service/characters/model/character_cration.hpp>

class CharacterCreationFactory {
public:
    static CharacterCreation from_json(const std::shared_ptr<Json::Value>& json);
};

#endif //DARK_TRIAD_SERVICES_CHARACTER_CREATION_FACTORY_HPP

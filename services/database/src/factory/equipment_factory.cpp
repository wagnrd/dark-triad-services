#include "include/factory/equipment_factory.hpp"

std::shared_ptr<Json::Value> EquipmentFactory::to_json(const Equipment& equipment)
{
    auto json = std::make_shared<Json::Value>();
    (*json)["mainWeapon"] = equipment.mainWeapon;
    (*json)["supportWeapon"] = equipment.supportWeapon;
    (*json)["headArmour"] = equipment.headArmour;
    (*json)["torsoArmour"] = equipment.torsoArmour;
    (*json)["shoulderArmour"] = equipment.shoulderArmour;
    (*json)["armArmour"] = equipment.armArmour;
    (*json)["legArmour"] = equipment.legArmour;
    (*json)["footArmour"] = equipment.footArmour;

    return json;
}

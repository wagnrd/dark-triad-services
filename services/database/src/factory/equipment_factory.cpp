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

Equipment EquipmentFactory::from_orm(const drogon::orm::Row& row)
{
    return Equipment{
            .mainWeapon = row["main_weapon"].c_str(),
            .supportWeapon = row["support_weapon"].c_str(),
            .headArmour = row["head_armour"].c_str(),
            .torsoArmour = row["torso_armour"].c_str(),
            .shoulderArmour = row["shoulder_armour"].c_str(),
            .armArmour = row["arm_armour"].c_str(),
            .legArmour = row["leg_armour"].c_str(),
            .footArmour = row["foot_armour"].c_str()
    };
}
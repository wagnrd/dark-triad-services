#ifndef DARK_TRIAD_SERVICES_APPEARANCE_HPP
#define DARK_TRIAD_SERVICES_APPEARANCE_HPP

#include "color.hpp"

class Appearance {
public:
    std::string gender;
    double height{};
    int faceId{};
    int earsId{};
    int hairId{};
    int eyebrowsId{};
    int facialHairId{};
    Color skinColor{};
    Color eyeColor{};
    Color scarColor{};
    Color tattooColor{};
    Color hairColor{};
};

#endif //DARK_TRIAD_SERVICES_APPEARANCE_HPP

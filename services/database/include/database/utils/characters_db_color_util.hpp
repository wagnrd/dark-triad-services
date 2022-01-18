#ifndef DARK_TRIAD_SERVICES_CHARACTERS_DB_COLOR_UTIL_HPP
#define DARK_TRIAD_SERVICES_CHARACTERS_DB_COLOR_UTIL_HPP

#include <cstdint>

#include "include/service/characters/model/color.hpp"

class CharactersDBColorUtil {
public:
    static int encode_color(const Color& color);
    static Color decode_color(int encodedColor);
    static int convert_double_color_to_int(double color);
    static double convert_int_color_to_double(int color);
};

#endif //DARK_TRIAD_SERVICES_CHARACTERS_DB_COLOR_UTIL_HPP
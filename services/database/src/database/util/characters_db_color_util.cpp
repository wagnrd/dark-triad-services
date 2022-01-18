#include <cmath>
#include "include/database/utils/characters_db_color_util.hpp"

int CharactersDBColorUtil::encode_color(const Color& color)
{
    int ri = convert_double_color_to_int(color.r) & 0xFF;
    int gi = convert_double_color_to_int(color.g) & 0xFF;
    int bi = convert_double_color_to_int(color.b) & 0xFF;
    int ai = convert_double_color_to_int(color.a) & 0xFF;

    return (ri << 24) | (gi << 16) | (bi << 8) | (ai);
}

Color CharactersDBColorUtil::decode_color(int encodedColor)
{
    int ri = encodedColor >> 24 & 0xFF;
    int gi = encodedColor >> 16 & 0xFF;
    int bi = encodedColor >> 8 & 0xFF;
    int ai = encodedColor & 0xFF;

    return Color{
            .r = convert_int_color_to_double(ri),
            .g = convert_int_color_to_double(gi),
            .b = convert_int_color_to_double(bi),
            .a = convert_int_color_to_double(ai)
    };
}

int CharactersDBColorUtil::convert_double_color_to_int(double color)
{
    return std::max(0, std::min(255, static_cast<int>(std::floor(color * 256.0))));
}

double CharactersDBColorUtil::convert_int_color_to_double(int color)
{
    return color / 255.0;
}
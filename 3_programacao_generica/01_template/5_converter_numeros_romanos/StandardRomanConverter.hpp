#ifndef STD_ROMAN_CONVERTER_HPP
#define STD_ROMAN_CONVERTER_HPP

#include "RomanConverter.hpp"

class StandardRomanConverter : public RomanConverter
{
public:
    std::string toRoman(int value) const override;
    int fromRoman(std::string_view roman) const override;
};

#endif
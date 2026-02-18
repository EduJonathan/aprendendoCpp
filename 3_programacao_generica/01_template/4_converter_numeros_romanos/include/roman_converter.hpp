#ifndef ROMAN_CONVERTER_HPP
#define ROMAN_CONVERTER_HPP

#include <string>
#include <string_view>
#include "policies.hpp"

template <typename Policy>
class RomanConverter : private Policy
{
public:
    using Policy::from_roman_impl;
    using Policy::to_roman_impl;

    std::string toRoman(int value) const;
    int fromRoman(std::string_view roman) const;

    std::string operator()(int value) const;
    int operator()(std::string_view roman) const;
};

#endif // ROMAN_CONVERTER_HPP

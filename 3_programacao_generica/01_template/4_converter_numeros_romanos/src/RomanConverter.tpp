#include "../include/roman_converter.hpp"

template <typename Policy>
std::string RomanConverter<Policy>::toRoman(int value) const
{
    return this->to_roman_impl(value);
}

template <typename Policy>
int RomanConverter<Policy>::fromRoman(std::string_view roman) const
{
    return this->from_roman_impl(roman);
}

template <typename Policy>
std::string RomanConverter<Policy>::operator()(int value) const
{
    return toRoman(value);
}

template <typename Policy>
int RomanConverter<Policy>::operator()(std::string_view roman) const
{
    return fromRoman(roman);
}

// Instanciações explícitas das templates que vamos usar
template class RomanConverter<StandardRomanPolicy>;
template class RomanConverter<AdditiveRomanPolicy>;

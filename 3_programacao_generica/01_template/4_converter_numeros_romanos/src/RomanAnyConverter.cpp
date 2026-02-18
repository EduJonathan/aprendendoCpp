#include "../include/roman_any_converter.hpp"
#include "../include/roman_converter.hpp" // necessário para usar RomanConverter nas instanciações

template <typename Converter>
RomanAnyConverter::RomanAnyConverter(const Converter &conv) : self(std::make_shared<Model<Converter>>(conv))
{
}

template <typename T>
std::string RomanAnyConverter::Model<T>::toRoman(int v) const
{
    return converter.toRoman(v);
}

template <typename T>
int RomanAnyConverter::Model<T>::fromRoman(std::string_view s) const
{
    return converter.fromRoman(s);
}

// Instanciações explícitas do construtor template
template RomanAnyConverter::RomanAnyConverter(const RomanConverter<StandardRomanPolicy> &);
template RomanAnyConverter::RomanAnyConverter(const RomanConverter<AdditiveRomanPolicy> &);

// Instanciações dos Model (necessárias porque são usadas indiretamente)
template class RomanAnyConverter::Model<RomanConverter<StandardRomanPolicy>>;
template class RomanAnyConverter::Model<RomanConverter<AdditiveRomanPolicy>>;

int RomanAnyConverter::fromRoman(std::string_view s) const { return self->fromRoman(s); }
std::string RomanAnyConverter::toRoman(int v) const { return self->toRoman(v); }

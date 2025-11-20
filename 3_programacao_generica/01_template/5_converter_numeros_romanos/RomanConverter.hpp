#ifndef ROMAN_CONVERTER_HPP
#define ROMAN_CONVERTER_HPP

#include <string>
#include <string_view>

// Herda Policy, Policy é um "mixin", ou seja, uma classe que fornece funcionalidades para serem usadas por outra classe
template <typename Policy>
class RomanConverter : private Policy
{
public:
    using Policy::from_roman_impl;
    using Policy::to_roman_impl;

    // Converte inteiro → romano
    std::string toRoman(int value) const
    {
        return this->to_roman_impl(value);
    }

    // Converte romano → inteiro
    int fromRoman(std::string_view roman) const
    {
        return this->from_roman_impl(roman);
    }

    // operator() para uso como função, ele funciona como um "atalho" para os métodos de conversão
    // será melhor explicado posteriormente com sobrecarga de operadores
    std::string operator()(int value) const { return toRoman(value); }
    int operator()(std::string_view roman) const { return fromRoman(roman); }
};

#endif

#ifndef ROMAN_CONVERTER_HPP
#define ROMAN_CONVERTER_HPP

#include <string>
#include <string_view>

class RomanConverter
{
public:
    virtual ~RomanConverter() = default;

    // Converte inteiro → romano
    virtual std::string toRoman(int value) const = 0;

    // Converte romano → inteiro
    virtual int fromRoman(std::string_view roman) const = 0;

    // operator() para uso como função, ele funciona como um "atalho" para os métodos de conversão
    // será melhor explicado posteriormente com sobrecarga de operadores
    std::string operator()(int value) const { return toRoman(value); }
    int operator()(std::string_view roman) const { return fromRoman(roman); }
};

#endif

#ifndef ROMAN_CONVERTER_HPP
#define ROMAN_CONVERTER_HPP

#include <string>
#include <string_view>
#include "policies.hpp"

// A classe `RomanConverter` é uma implementação de um conversor de números romanos que utiliza
// uma política de conversão específica (definida por um tipo de política) para realizar as operações de conversão.
// Ela é construída a partir de um objeto de conversão específico (como `StandardRomanPolicy` ou `AdditiveRomanPolicy`)
// e fornece métodos para converter números inteiros para suas representações em números romanos e vice-versa.
template <typename Policy>
class RomanConverter : private Policy
{
public:
    // Permite o acesso ao método `from_roman_impl` da política de conversão específica (Policy)
    // para realizar a conversão de números romanos para inteiros.
    using Policy::from_roman_impl;

    // Permite o acesso ao método `to_roman_impl` da política de conversão específica (Policy)
    // para realizar a conversão de números inteiros para números romanos.
    using Policy::to_roman_impl;

    /**
     * @brief Converte um número inteiro para uma string representando o número romano.
     *
     * O método `toRoman` é responsável por realizar a conversão de um número inteiro para sua representação
     * em números romanos, utilizando a política de conversão configurada na classe `RomanConverter`.
     * O método `toRoman` é implementado utilizando o método `to_roman_impl` da política de conversão específica
     * (Policy) para realizar a operação de conversão de acordo com a política de conversão representada pelo tipo `Policy`.
     *
     * @param v O número inteiro a ser convertido.
     * @return Uma string representando o número romano correspondente ao valor inteiro fornecido, obtida através
     * do método `to_roman_impl` da política de conversão específica.
     */
    std::string toRoman(int value) const;

    /**
     * @brief Converte uma string representando um número romano para um número inteiro.
     *
     * O método `fromRoman` é responsável por realizar a conversão de uma string representando um número romano
     * para seu valor inteiro correspondente, utilizando a política de conversão configurada na classe `RomanConverter`.
     * O método `fromRoman` é implementado utilizando o método `from_roman_impl` da política de conversão específica
     * (Policy) para realizar a operação de conversão de acordo com a política de conversão representada pelo tipo `Policy`.
     *
     * @param roman A string representando o número romano a ser convertido.
     * @return O valor inteiro correspondente à string de número romano fornecida, obtido através do método `from_roman_impl`
     * da política de conversão específica.
     */
    int fromRoman(std::string_view roman) const;

    /**
     * @brief Sobrecarga do operador de chamada para conversão de números inteiros para números romanos.
     *
     * O operador de chamada é sobrecarregado para permitir a conversão de números inteiros para números
     * romanos de forma mais conveniente, utilizando a sintaxe de chamada de função. Ele é implementado
     * para chamar o método `toRoman`, permitindo que o objeto `RomanConverter` seja utilizado como uma função
     * para realizar a conversão de números inteiros para números romanos.
     *
     * @param value O número inteiro a ser convertido para número romano.
     * @return Uma string representando o número romano correspondente ao valor inteiro fornecido, obtida através do método `toRoman`.
     */
    std::string operator()(int value) const;

    /**
     * @brief Sobrecarga do operador de chamada para conversão de números romanos para inteiros.
     *
     * O operador de chamada é sobrecarregado para permitir a conversão de números romanos para inteiros de
     * forma mais conveniente, utilizando a sintaxe de chamada de função. Ele é implementado para chamar o método `fromRoman`,
     * permitindo que o objeto `RomanConverter` seja utilizado como uma função para realizar a conversão de números romanos para inteiros.
     *
     * @param roman A string representando o número romano a ser convertido para inteiro.
     * @return O valor inteiro correspondente à string de número romano fornecida, obtido através
     */
    int operator()(std::string_view roman) const;
};

#include "../src/RomanConverter.tpp" // Inclui as implementações dos métodos template da classe RomanConverter

#endif // ROMAN_CONVERTER_HPP

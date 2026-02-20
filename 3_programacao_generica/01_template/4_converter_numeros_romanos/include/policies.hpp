#ifndef POLICIES_HPP
#define POLICIES_HPP

#include <string>
#include <string_view>

/**
 * @brief Políticas de conversão para números romanos.
 *
 * Cada política implementa os métodos `to_roman_impl` e `from_roman_impl`, que são usados pelo RomanConverter para realizar as conversões.
 */
struct StandardRomanPolicy
{
    /**
     * @brief Converte um número inteiro para uma string representando o número romano.
     *
     * O método `to_roman_impl` é responsável por realizar a conversão de um número inteiro para sua representação em números romanos.
     *
     * @param value O número inteiro a ser convertido.
     * @return Uma string representando o número romano correspondente ao valor inteiro fornecido.
     */
    std::string to_roman_impl(int value) const;

    /**
     * @brief Converte uma string representando um número romano para um número inteiro.
     *
     * O método `from_roman_impl` é responsável por realizar a conversão de uma string representando
     * um número romano para seu valor inteiro correspondente.
     *
     * @param s A string representando o número romano a ser convertido.
     * @return O valor inteiro correspondente à string de número romano fornecida.
     */
    int from_roman_impl(std::string_view s) const;
};

/**
 * @brief Política de conversão aditiva para números romanos.
 *
 * A política `AdditiveRomanPolicy` implementa uma abordagem aditiva para a conversão de números romanos,
 * onde os símbolos são somados para obter o valor total.
 */
struct AdditiveRomanPolicy
{
    /**
     * @brief Converte um número inteiro para uma string representando o número romano usando a abordagem aditiva.
     *
     * O método `to_roman_impl` é responsável por realizar a conversão de um número inteiro para sua representação
     * em números romanos usando a abordagem aditiva, onde os símbolos são somados para obter o valor total.
     *
     * @param value O número inteiro a ser convertido.
     * @return Uma string representando o número romano correspondente ao valor inteiro fornecido, usando a abordagem aditiva.
     */
    std::string to_roman_impl(int value) const;

    /**
     * @brief Converte uma string representando um número romano para um número inteiro usando a abordagem aditiva.
     *
     * O método `from_roman_impl` é responsável por realizar a conversão de uma string representando um número romano
     * para seu valor inteiro correspondente usando a abordagem aditiva, onde os símbolos são somados para obter o valor total.
     *
     * @param s A string representando o número romano a ser convertido.
     * @return O valor inteiro correspondente à string de número romano fornecida, usando a abordagem aditiva.
     */
    int from_roman_impl(std::string_view s) const;
};

#endif // POLICIES_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include <ranges>

/**
 * std::ranges::input_range / std::ranges::output_range(): São os ranges mais básicos
 * do sistema de ranges do C++20.
 *
 * - Um *input_range* permite **ler** valores sequencialmente (como um stream de entrada).
 * - Um *output_range* permite **escrever** valores sequencialmente (como um stream de saída).
 *
 * Esses tipos de ranges são usados geralmente em situações onde não é necessário voltar
 * ou acessar elementos aleatoriamente — como streams, arquivos ou operações simples de I/O.
 *
 * Exemplo:
 * - std::istream_iterator<T> é um input_range (leitura de fluxo como std::cin).
 * - std::ostream_iterator<T> é um output_range (escrita em fluxo como std::cout`).
 */

/**
 * @brief Função que retorna um lambda para mapear valores de um intervalo de entrada
 * [inputMin, inputMax] para um intervalo de saída [outputMin, outputMax].
 *
 * Utiliza std::clamp para garantir que o valor fique dentro dos limites esperados.
 */
auto mapToRange(float inputMin, float inputMax, float outputMin, float outputMax)
{
    return [=](float value)
    {
        value = std::clamp(value, inputMin, inputMax);
        return outputMin + (value - inputMin) / (inputMax - inputMin) * (outputMax - outputMin);
    };
}

int main(int argc, char **argv)
{
    // input_range(pode ser qualquer container ou view)
    std::vector<float> valores = {0.0f, 25.0f, 50.0f, 75.0f, 100.0f};

    // output_range
    std::vector<float> resultados;
    auto outputIterator = std::back_inserter(resultados);

    // Verificação estática
    static_assert(std::ranges::input_range<decltype(valores)>, "O intervalo não é um input_range!");

    // Exige que o outputIterator seja um input_range e output_range, Aplica uma função a
    // cada elemento de um input_range e grava o resultado em um output_range.
    std::ranges::transform(
        valores,                               // input_range
        outputIterator,                        // output_range
        mapToRange(0.0f, 100.0f, 0.0f, 1.0f)); // mapeia de [0, 100] para [0, 1]

    // Imprime os resultados
    for (std::size_t i = 0; i < resultados.size(); ++i)
    {
        std::cout << valores[i] << " -> " << resultados[i] << '\n';
    }
    return 0;
}

#include <iostream>
#include <type_traits>
#include <chrono>

/**
 * std::chrono::treat_as_floating_point<Rep>
 *
 * É uma type trait que verifica se o tipo Rep deve ser tratado como ponto flutuante
 * nas operações de std::chrono::duration.
 *
 * - Se Rep for int, long, etc. → value == false
 * - Se Rep for float, double → value == true
 *
 * Isso afeta:
 * - Conversões entre durações
 * - Arredondamento em operações como duration_cast
 */

int main(int argc, char **argv)
{
    std::cout << std::boolalpha; // Mostra true/false em vez de 1/0
    std::cout << std::noboolalpha << '\n';

    // === Testando a type trait ===
    std::cout << "int    -> treat_as_floating_point: "
              << std::chrono::treat_as_floating_point<int>::value << '\n'; // false

    std::cout << "double -> treat_as_floating_point: "
              << std::chrono::treat_as_floating_point<double>::value << '\n'; // true

    std::cout << "float  -> treat_as_floating_point: "
              << std::chrono::treat_as_floating_point<float>::value << '\n'; // true

    std::cout << '\n';

    // === Durações corretas (com período explícito ou usando aliases) ===
    using namespace std::chrono;

    // 1 segundo inteiro
    seconds d1(1); // duration<int, ratio<1>>
    // ou: duration<int, ratio<1>> d1(1);

    // 1.5 segundos em ponto flutuante
    duration<double> d2(1.5); // duration<double, ratio<1>>

    // Ou com alias mais claro:
    duration<double, std::ratio<1>> d3(1.5);

    std::cout << "d1 (int): " << d1.count() << " segundos\n";
    std::cout << "d2 (double): " << d2.count() << " segundos\n";

    std::cout << '\n';

    // === Demonstração prática: conversão com perda de precisão ===
    auto d_int_to_double = duration_cast<duration<double>>(d1);
    std::cout << "d1 (int) -> double: " << d_int_to_double.count() << " s\n"; // 1.0

    auto d_double_to_int = duration_cast<seconds>(d2);
    std::cout << "d2 (double) -> int: " << d_double_to_int.count() << " s\n"; // 1 (truncado!)

    std::cout << '\n';

    // === Por que treat_as_floating_point importa? ===
    std::cout << "Pode truncar? (int -> double): "
              << std::chrono::treat_as_floating_point<int>::value << " → sem truncamento\n";

    std::cout << "Pode truncar? (double -> int): "
              << std::chrono::treat_as_floating_point<double>::value
              << " → pode truncar ao converter para int!\n";

    return 0;
}

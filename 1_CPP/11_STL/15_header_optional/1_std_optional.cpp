#include <iostream>
#include <optional>

/**
 * O header <optional> do C++ fornece a classe template std::optional, que representa
 * um valor que pode ou não estar presente. Em outras palavras, é uma forma segura de
 * lidar com situações em que uma variável pode ter um valor válido ou nenhum valor,
 * sem usar ponteiros nulos (nullptr) ou flags extras.
 *
 * Quando usar:
 *
 * - Resultados de funções que podem falhar ou não retornar nada.
 * - Substituir flags booleanas + variável auxiliar.
 * - Evitar ponteiros nulos, aumentando segurança e clareza do código.
 */

int main(int argc, char **argv)
{
    std::optional<int> a;      // sem valor
    std::optional<int> b = 42; // com valor

    if (a.has_value())
        std::cout << "a = " << a.value() << '\n';
    else
        std::cout << "a não tem valor\n";

    std::cout << "b = " << b.value() << '\n'; // b tem valor
}

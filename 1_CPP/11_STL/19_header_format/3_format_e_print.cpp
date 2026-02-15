#include <iostream>
#include <string>
#include <algorithm>
#include <format>
#include <ranges>
#include <print>

/**
 * Explicando sobre as bibliotecas <format> e <print>
 *
 * Em termos de funcionalidade, tanto <format> quanto <print> fornecem capacidades de formatação de strings
 * No entanto, a principal diferença está na forma como são usadas:
 *
 * - <format>: Implementada no C++20 ele requer duas etapas, primeiro, você cria uma string formatada usando std::format, e depois imprime essa string.
 * - <print>: Implementada no C++23 Permite imprimir diretamente com formatação em uma única etapa usando std::print.
 */

int main(int argc, char **argv)
{
    int x = 42;
    double y = 3.14159;

    // Com <format> - duas etapas, :.2f para formatar float com 2 casas decimais
    std::string formatted = std::format("x = {}, y = {:.2f}", x, y);
    std::cout << formatted << '\n';

    // Com <print> - uma etapa
    std::print("x = {}, y = {:.2f}\n", x, y);
    std::print("Olá, {}!\n", "Mundo"); // imprime com formatação
    std::println("Número: {}", 42);    // imprime e adiciona \n automaticamente

    std::cout << "------------------------\n";

    std::string s = "String Reversa";

    std::string rev(s.rbegin(), s.rend()); // constrói string invertida
    std::cout << std::format("{}\n", rev);

    for (char c : s | std::views::reverse)
        std::print("{}", c);
    std::print("\n");

    /**
     * Graças ao <print>, Execute comando de compilação com g++:
     * g++ -std=c++23 -o prints 3_header_format_e_header_print.cpp
     *
     * ou
     *
     * g++-14 -std=c++23 -o prints 3_header_format_e_header_print.cpp
     *
     * Depois de compilar, execute o programa:
     * ./prints
     */
    return 0;
}

#include <iostream>
#include <string>
#include <string_view>

using namespace std::literals::string_literals;
using namespace std::literals::string_view_literals;

int main(int argc, char **argv)
{
    auto str = "Hello"s; // std::string
    auto sv = "World"sv; // std::string_view

    std::cout << "std::string: " << str << '\n';     // Copia os dados
    std::cout << "std::string_view: " << sv << '\n'; // Apenas referencia

    // Modificando std::string
    str += ", modified!"; // OK, std::string é mutável
    std::cout << "std::string modificado: " << str << '\n';

    // sv += ", modified!"; // ERRO: std::string_view não é mutável

    return 0;
}

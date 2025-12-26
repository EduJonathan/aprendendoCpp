#include <iostream>
#include <format>

// Função que define campos de largura
void formatar_largura()
{
    std::cout << std::format("{:7}\n", 42);   // yields "     42"
    std::cout << std::format("{:7}\n", 42.0); // yields "     42"
    std::cout << std::format("{:7}\n", 'x');  // yields "x      "
    std::cout << std::format("{:7}\n", true); // yields "true   "
}

// Função que demonstra filtros de formatação
void formatar_filtros()
{
    std::cout << std::format("{:*<7}\n", 42); // yields "42*****"
    std::cout << std::format("{:*>7}\n", 42); // yields "*****42"
    std::cout << std::format("{:*^7}\n", 42); // yields "**42***"
}

// Função que demonstra a formatação binária
void formatar_binarios()
{
    std::cout << std::format("{:#b} {:#b} {:#b}\n", 42, '@', true);
    // Output: 0b101010 0b1000000 0b1
}

// Função que demonstra a formatação de valores flutuantes
void formatar_valores_flutuante()
{
    // Formatação de valores flutuantes
    std::cout << std::format("{0} {0:#} {0:#g} {0:e}\n", -1.0);
    // Output: -1 -1 -1  -1.000000e+00

    std::cout << std::format("{}", 0.12345678) << '\n';       // yields "0.12345678"
    std::cout << std::format("{:.5}", 0.12345678) << '\n';    // yields "0.12346"
    std::cout << std::format("{:10.5}", 0.12345678) << '\n';  // yields "   0.12346"
    std::cout << std::format("{:^10.5}", 0.12345678) << '\n'; // yields " 0.12346  "
}

void formatar_strings()
{
    std::cout << std::format("{}", "counter") << '\n';    // yields "counter"
    std::cout << std::format("{:s}", "counter") << '\n';  // yields "counter"
    std::cout << std::format("{:.5}", "counter") << '\n'; // yields "count"
    std::cout << std::format("{:.5}", "hi") << '\n';      // yields "hi"

    std::cout << std::format("{}", "counterproductive") << '\n';       // yields "counterproductive"
    std::cout << std::format("{:20}", "counterproductive") << '\n';    // yields "counterproductive   "
    std::cout << std::format("{:.7}", "counterproductive") << '\n';    // yields "counter"
    std::cout << std::format("{:20.7}", "counterproductive") << '\n';  // yields "counter             "
    std::cout << std::format("{:^20.7}", "counterproductive") << '\n'; // yields "      counter       "
}

int main(int argc, char **argv)
{
    // Chamando as funções para demonstrar as formatações
    formatar_largura();
    std::cout << "------------------------\n";

    formatar_filtros();
    std::cout << "------------------------\n";

    formatar_binarios();
    std::cout << "------------------------\n";

    formatar_valores_flutuante();
    std::cout << "------------------------\n";

    formatar_strings();

    /**
     * Exemplo de comando de compilação com g++:
     * g++ -std=c++20 -o formats 4_formatacoes_com_format.cpp
     *
     * ./formats
     *
     * @note
     * Informações e codificação retirada do livro:
     * C++20 The Complete Guide First, de Nicolai M. Josuttis
     */

    return 0;
}

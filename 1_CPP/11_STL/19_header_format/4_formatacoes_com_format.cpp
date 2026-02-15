#include <iostream>
#include <format>

/**
 * @brief Para formatar um valor com uma largura mínima, use o especificador de formato 'width' (ex: {:7}).
 * O valor será alinhado à direita por padrão, mas você pode usar os filtros de formatação para controlar o alinhamento.
 *
 * Função que demonstra a formatação de largura
 *
 * Exemplo: std::format("{:7}", 42) produzirá "     42".
 */
void formatar_largura()
{
    std::cout << std::format("{:7}\n", 42);   // yields "     42"
    std::cout << std::format("{:7}\n", 42.0); // yields "     42"
    std::cout << std::format("{:7}\n", 'x');  // yields "x      "
    std::cout << std::format("{:7}\n", true); // yields "true   "
}

/**
 * @brief Filtros de formatação permitem preencher o campo com um caractere específico
 * em vez de espaços. O formato geral é {:[fill][align][width]}.
 *
 *  Função que demonstra filtros de formatação
 *
 * - fill: caractere usado para preencher o campo (ex: '*')
 * - align: '<' (esquerda), '>' (direita), '^' (centralizado)
 * - width: largura total do campo
 */
void formatar_filtros()
{
    std::cout << std::format("{:*<7}\n", 42); // yields "42*****"
    std::cout << std::format("{:*>7}\n", 42); // yields "*****42"
    std::cout << std::format("{:*^7}\n", 42); // yields "**42***"
}

/**
 * @brief Para formatar um número em binário, use o especificador de formato 'b' com a opção '#' para incluir o prefixo '0b'.
 *
 * Função que demonstra a formatação binária
 *
 * Exemplo: std::format("{:#b}", 42) produzirá "0b101010".
 */
void formatar_binarios()
{
    std::cout << std::format("{:#b} {:#b} {:#b}\n", 42, '@', true);
    // Output: 0b101010 0b1000000 0b1
}

/**
 * @brief Para formatar valores flutuantes, use os especificadores de formato 'f' para notação decimal, 'e' para notação científica
 * e 'g' para escolher automaticamente entre as duas com base no valor.
 *
 * Função que demonstra a formatação de valores flutuantes
 *
 * Exemplo: std::format("{:e}", 1.0) produzirá "1.000000e+00".
 */
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

/**
 * @brief Para formatar strings, use o especificador de formato 's' para indicar que o argumento é uma string.
 * Você pode usar os mesmos filtros de formatação (fill, align, width) para controlar a aparência da string formatada.
 *
 * Função que demonstra a formatação de strings
 *
 * Exemplo: std::format("{:20}", "counterproductive") produzirá "counterproductive   ".
 */
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

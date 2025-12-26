#include <iostream>
#include <string>
#include <format>

/**
 * std::format (C++20)
 * --------------------
 * Fornece formatação de strings segura e eficiente.
 * Permite criar strings formatadas usando placeholders.
 *
 * Quando usar:
 * - Quando precisar de formatação de strings semelhante a printf,
 *   mas com segurança de tipo e melhor legibilidade.
 *
 * Exemplos de uso:
 * - std::format("Hello, {}!", name): substitui {} por name.
 * - Suporta especificadores de formato para números, alinhamento, precisão, etc.
 *
 * Vantagens:
 * - Segurança de tipo em tempo de compilação.
 * - Evita erros comuns de formatação.
 * - Código mais limpo e expressivo.
 */

int main(int argc, char **argv)
{
    int a = 5, b = 4;
    std::cout << std::format("A soma de {} + {} = {}\n", a, b, a + b) << '\n';

    std::string nome = "Maria";
    int idade = 30;
    std::cout << std::format("Nome: {}, Idade: {}\n", nome, idade) << '\n';

    /**
     * Exemplo de comando de compilação com g++:
     * g++ -std=c++20 -o format 1_header_format.cpp
     *
     * ./format
     */
    return 0;
}

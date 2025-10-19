#include <iostream>
#include <string>
#include <regex>

/**
 * @brief Introdução ao uso de expressões regulares (Regex) em C++.
 *
 * Regex (Regular Expressions / Expressões Regulares) é uma técnica poderosa usada para
 * buscar, validar e manipular strings com base em padrões específicos.
 *
 * Pode ser aplicada em diversas linguagens (C++, Python, Java, JavaScript etc.).
 *
 * @note Disponível a partir do padrão C++11.
 *
 * @details
 * Exemplos de uso:
 * - Validação de entradas do usuário (e-mail, telefone, CPF)
 * - Extração de informações de textos
 * - Substituição e manipulação de conteúdo textual
 * - Busca avançada em arquivos ou logs
 *
 * Sintaxe básica:
 * - `\\d` → representa um dígito (0–9)
 * - `{n}` → indica a quantidade de repetições
 * - `^` e `$` → delimitam o início e o fim da string, garantindo correspondência exata
 */

int main(int argc, char **argv)
{
    // Expressão regular para validar formato de telefone internacional brasileiro
    // Formato esperado: +55 86 9999-9999
    std::regex validarNumeroDeTelefone("^\\+\\d{2} \\d{2} \\d{4}-\\d{4}$");

    // Exemplo válido
    std::string numeroValido = "+55 86 9999-9999";

    // Exemplo inválido (faltando o '+', e com um espaço extra)
    std::string numeroInvalido = "55 86 99999-9999";

    std::cout << "Testando número válido:   " << numeroValido << '\n';
    if (std::regex_match(numeroValido, validarNumeroDeTelefone))
    {
        std::cout << "Número de telefone válido\n";
    }
    else
    {
        std::cout << "Número de telefone inválido\n";
    }

    std::cout << "\nTestando número inválido: " << numeroInvalido << '\n';
    if (std::regex_match(numeroInvalido, validarNumeroDeTelefone))
    {
        std::cout << "Número de telefone válido\n";
    }
    else
    {
        std::cout << "Número de telefone inválido\n";
    }

    return 0;
}

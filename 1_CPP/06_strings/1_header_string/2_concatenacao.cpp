#include <iostream>
#include <string>

/**
 * Concatenação de strings: Significa mesclar duas strings.
 * A concatenação ocorre pelo uso do operador `+` entre as strings.
 *
 * @note Tipos C-STYLE como `char*` e `const char[]` não tem essa capacidade
 * de concatenar, sem o uso de funções específicas como (strcat/strncat)
 */

int main(int argc, char **argv)
{
    // Concatenando duas strings
    std::string str1{"Hello, "};
    std::string str2{"World!"};
    std::string str3 = str1 + str2;

    // Exibe a string concatenada
    std::cout << str3 << '\n';

    std::cout << "------------------------------------------\n";

    // Concatenando strings e variáveis
    std::string primeiroNome{"Eduardo"};
    std::string sobrenome{"Silva"};
    std::string nomeCompleto = primeiroNome + ' ' + sobrenome;

    // Exibe o nome completo
    std::cout << nomeCompleto << '\n';

    std::cout << "------------------------------------------\n";

    // Começa com 1 dígito, "0"
    std::string digitos{"0"};

    // Verifica se a string tem apenas 1 dígito, continua até ter 10 dígitos
    while (digitos.length() < 10)
    {
        std::cout << "Número atual: " << digitos << '\n';

        // Adiciona o próximo dígito (1, 2, ..., 9)
        // Adiciona o próximo dígito, '0' é somado para converter o número em caractere
        digitos += (digitos.length() + '0');

        // Verifica se já temos 10 dígitos
        if (digitos.length() == 10)
        {
            std::cout << "Agora temos 10 dígitos: " << digitos << '\n';
        }
    }
    return 0;
}

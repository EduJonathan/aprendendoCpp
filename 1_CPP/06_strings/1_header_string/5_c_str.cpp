#include <iostream>
#include <cstring>
#include <string>

/**
 * c_str(): É um método da classe std::string que retorna um ponteiro constante para
 * um array de caracteres (const char*) que representa o conteúdo da string. c_str()
 * é usado para obter um ponteiro para uma string C-style (const char*) a partir de um
 * objeto std::string.
 *
 * Tecnicamente o método .c_str() converte cada std::string em um const char* terminado por \0, compatível
 * com std::strcmp. Isso é seguro, pois .c_str() garante que o ponteiro retornado aponte para uma representação
 * válida da string, com término nulo.
 *
 * CSTYLE: Refere-se ao estilo de programação e aos elementos da linguagem C, que incluem
 * o uso de arrays de caracteres para representar strings e a abordagem procedural para
 * escrever código.
 *
 * SINTAXE: inline const char *std::__1::string::c_str() const noexcept;
 */

int main(int argc, char **argv)
{
    std::string str{"Hello, world!"};
    const char *cstr = str.c_str();

    // Agora podemos usar cstr com funções que esperam uma string C-style
    std::cout << "A string C-style é: " << cstr << '\n';

    // Comparando strings C-style
    if (std::strcmp(cstr, "Hello, world!") == 0)
    {
        std::cout << "As strings são iguais" << '\n';
    }
    else
    {
        std::cout << "As strings são diferentes" << '\n';
    }
    return 0;
}

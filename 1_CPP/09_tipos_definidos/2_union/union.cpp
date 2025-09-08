#include <iostream>

/**
 * Uniões (unions): Semelhante a uma estrutura(struct), mas com a diferença de que
 * todos os membros compartilham o mesmo espaço de memória.
 */

union Dados
{
    char caractere;
    int inteiro;
    float real;
};

int main(int argc, char **argv)
{
    /** Cria um objeto 'dado' do tipo 'union Dados' */
    Dados dado = {0}; // Inicializa todos os membros com zero

    dado.caractere = 'A'; // Atribui o valor 'A' ao membro 'caractere'
    std::cout << "Caractere: " << dado.caractere << '\n';

    dado.inteiro = 123; // Atribui o valor 123 ao membro 'inteiro'
    std::cout << "Inteiro: " << dado.inteiro << '\n';

    dado.real = 3.14; // Atribui o valor 3.14 ao membro 'real'
    std::cout << "Real: " << dado.real << '\n';

    std::cout << "----------------------------------------\n";

    std::cout << "Tamanho do union: " << sizeof(Dados) << " bytes" << '\n';
    std::cout << "Tamanho do caractere: " << sizeof(dado.caractere) << " bytes" << '\n';
    std::cout << "Tamanho do inteiro: " << sizeof(dado.inteiro) << " bytes" << '\n';
    std::cout << "Tamanho do real: " << sizeof(dado.real) << " bytes" << '\n';

    std::cout << "----------------------------------------\n";

    std::cout << "Endereço do union: " << &dado << '\n';
    std::cout << "Endereço do caractere: " << &dado.caractere << '\n';
    std::cout << "Endereço do inteiro: " << &dado.inteiro << '\n';
    std::cout << "Endereço do real: " << &dado.real << '\n';
    return 0;
}

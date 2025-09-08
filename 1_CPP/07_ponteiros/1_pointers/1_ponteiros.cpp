#include <iostream>

/**
 * PONTEIROS: Os ponteiros são uma ferramenta poderosa e fundamental para programadores.
 * Eles permitem o acesso direto à memória do computador e são essenciais para tarefas como
 * alocação dinâmica de memória e manipulação de arrays.
 */

int main(int argc, char **argv)
{
    std::cout << "\t>> PONTEIROS" << '\n';
    std::cout << "----------------------------------\n";

    // Variável
    int x = 0;
    std::cout << "O valor de X é: " << x << '\n';
    std::cout << "O endereco de X é: " << &x << '\n';

    std::cout << "----------------------------------\n";

    // Ponteiro
    int *ptr = NULL;
    std::cout << "O endereco do ponteiro ptr é: " << &ptr << '\n';
    std::cout << "O valor do ponteiro ptr antes de ser atribuido é: " << ptr << '\n';

    // Atribuindo o endereco da variavel x ao ponteiro
    ptr = &x;
    std::cout << "O valor da variável X com ptr apontando para ele é: " << *ptr << '\n';

    std::cout << "----------------------------------\n";

    // Atribuindo um novo valor ao ponteiro que irá alterar o valor da variável x
    *ptr = 10;
    std::cout << "Agora, X vale: " << *ptr << '\n';

    return 0;
}

#include <iostream>
#include <cstring>
#include <new>

/**
 * NEW: É uma keyword que aloca memória dinamicamente, ou seja, cria uma área na memória
 * na memória heap, new retorna um ponteiro para a área alocada, no C++ nós utilizamos new
 * em vez do malloc.
 *
 * DELETE: Destrói o(s) objeto(s) alocado(s) anteriormente pela nova expressão e libera a
 * área de memória obtida.
 */

int main(int argc, char **argv)
{
    int *ptr_a = NULL;

    // Cria a área necessária para 01 inteiro e coloca em 'ptr_a' o endereço desta área.
    ptr_a = new int;

    if (ptr_a == NULL)
    {
        std::cerr << "Memória insuficiente!" << '\n';
        return 1;
    }

    std::cout << "Endereço de ptr_a: " << &ptr_a << '\n';
    std::cout << "Endereço de ptr_a alocado por new: " << ptr_a << '\n';
    *ptr_a = 90;

    std::cout << "Conteúdo de ptr_a: " << *ptr_a << '\n';
    delete ptr_a;

    std::cout << "\n=====================================\n";

    std::size_t tamanho = 10ull;         // Tamanho do vetor
    double *vetor = new double[tamanho]; // Alocação dinâmica de 10 elementos

    std::cout << "Endereço de 'vetor': " << vetor << '\n';

    // Atribuindo valores para cada posição do vetor
    vetor[0] = 10.00;
    vetor[1] = 11.01;
    vetor[2] = 12.02;
    vetor[3] = 13.03;
    vetor[4] = 14.04;
    vetor[5] = 15.05;
    vetor[6] = 16.06;
    vetor[7] = 17.07;
    vetor[8] = 18.08;
    vetor[9] = 19.09;

    // Exibindo os valores e os endereços do vetor
    for (std::size_t i = 0ull; i < tamanho; ++i)
        std::cout << "vetor[" << i << "]: " << vetor[i]
                  << "\tEndereço do vetor[" << i << "]: " << &vetor[i] << '\n';

    delete[] vetor; // Liberando a memória alocada

    std::cout << "\n=====================================" << '\n';

    // Declarando ponteiro para char
    char *frase = nullptr;

    // Alocando memória para o ponteiro de um vetor de char
    frase = new char[20];
    // Em C++, em vez de frase = (char *) malloc(20 * sizeof(char)); basta somente utilizar
    // o new. new[] é usado para alocar memória para um array. Criando um bloco de memória
    // na heap que pode armazenar 20 caracteres.

    // frase = "Hello World!";
    // Não é recomendado, pois 'frase' apontaria para uma string literal
    // em memória estática, sobrescrevendo a memória dinamicamente alocada.

    // Copiando uma string para atribuir ao ponteiro um valor(string)
    std::strcpy(frase, "Hello World!");

    // Imprimindo o ponteiro de um vetor de char
    std::cout << frase << '\n';

    // Liberando memória, delete[] é uma instrução para liberar a memória alocada
    // dinamicamente para um array de objetos ou tipos. é usado para desalocar (liberar)
    // memória que foi alocada dinamicamente com new[].
    delete[] frase;
    return 0;
}

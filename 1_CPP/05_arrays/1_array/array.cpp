#include <iostream>

/**
 * Arrays: São estruturas de dados que representam uma sequência de elementos do mesmo
 * tipo, armazenados de forma contígua na memória. Eles podem ser unidimensionais
 * (como uma lista) ou multidimensionais (como uma matriz).
 * 
 * Arrays são usados para armazenar dados de forma eficiente, permitindo o acesso
 * rápido a elementos por meio de índices.
 */

int main(int argc, char **argv)
{
    // Um array de 5 elementos, e obtendo o tamanho do array
    int arr[5] = {1, 2, 3, 4, 5};
    std::size_t size = sizeof(arr) / sizeof(arr[0]);

    // índice para acessar o array
    int index = 6;

    // Verificação manual para garantir que o índice está dentro dos limites
    if (index >= 0 && index < size)
    {
        std::cout << "Valor no índice " << index << ": " << arr[index] << '\n';
    }
    else
    {
        std::cout << "Erro: Índice fora dos limites do array!" << '\n';
    }

    // índice para acessar o array
    int indice = 5;

    // Verificação manual para garantir que o índice está dentro dos limites
    if (indice >= 0 && indice < size)
    {
        std::cout << "Valor no índice " << indice << ": " << arr[indice] << '\n';
    }
    else
    {
        std::cout << "Erro: Índice fora dos limites do array!" << '\n';
    }
    
    return 0;
}

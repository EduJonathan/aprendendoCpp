#include <iostream>
#include <new>

int main(int argc, char **argv)
{
    int numeroLinhas = 0, numeroColunas = 0;

    std::cout << "Digite o tamanho de linhas: ";
    std::cin >> numeroLinhas;

    std::cout << "Digite o tamanho de colunas: ";
    std::cin >> numeroColunas;

    std::cout << "Tamanho de Linhas: " << numeroLinhas << '\n';
    std::cout << "Tamanho de Colunas: " << numeroColunas << '\n';

    // Ponteiro de ponteiro para matriz
    int **matriz = new int *[numeroLinhas]; // alocando linhas

    for (int i = 0; i < numeroLinhas; ++i)
    {
        matriz[i] = new int[numeroColunas]; // alocando colunas
    }

    // Preenchendo e imprimindo
    for (int i = 0; i < numeroLinhas; ++i)
    {
        for (int j = 0; j < numeroColunas; ++j)
        {
            matriz[i][j] = i;
            std::cout << ' ' << matriz[i][j];
        }
        std::cout << '\n';
    }

    // Liberando memória
    for (int i = 0; i < numeroLinhas; ++i)
    {
        delete[] matriz[i]; // libera cada linha
    }
    delete[] matriz; // libera o array de ponteiros

    return 0;
}

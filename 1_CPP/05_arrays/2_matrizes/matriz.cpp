#include <iostream>
#include <array>
#include <iomanip>

/**
 * Matrizes ou arrays bidimensionais em C++: São estruturas de dados que
 * representam uma coleção de elementos organizados em linhas e colunas.
 * Elas sao usadas para armazenar dados de forma organizada e eficiente em
 * forma de tabela(linhas e colunas).
 */

int main(int argc, char **argv)
{
    int valoresSomados = 0;    // Variável para armazenar a soma total de todos os elementos
    int somarLinhas[3] = {0};  // Vetor para armazenar a soma de cada linha da matriz
    int somarColunas[3] = {0}; // Vetor para armazenar a soma de cada coluna da matriz

    int matriz[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};           // Matriz 3x3 inicializada com 0
    std::size_t linhas = sizeof(matriz) / sizeof(matriz[0]);        // Obtém o número de linhas
    std::size_t colunas = sizeof(matriz[0]) / sizeof(matriz[0][0]); // Obtém o número de colunas

    // Loop para a entrada dos valores da matriz
    // Iterando sobre as linhas
    for (std::size_t i = 0ull; i < linhas; ++i)
    {
        // Iterando sobre as colunas
        for (std::size_t j = 0ull; j < colunas; ++j)
        {
            // Solicita ao usuário o valor
            std::cout << "Informe o elemento [" << i << "][" << j << "]: ";

            // Armazena o valor na posição correspondente da matriz
            std::cin >> matriz[i][j];
        }
        std::cout << '\n';
    }

    // Calculando as somas das linhas, colunas e o total dos elementos da matriz
    // Iterando sobre as linhas
    for (std::size_t i = 0ull; i < linhas; ++i)
    {
        // Iterando sobre as colunas
        for (std::size_t j = 0ull; j < colunas; ++j)
        {
            somarLinhas[i] += matriz[i][j];  // Adiciona o valor da célula atual à soma da linha
            somarColunas[j] += matriz[i][j]; // Adiciona o valor da célula atual à soma da coluna
            valoresSomados += matriz[i][j];  // Adiciona o valor da célula atual à soma total
        }
    }

    // Exibindo a matriz modificada com a soma das linhas ao lado
    std::cout << "Matriz Modificada" << '\n';

    // Iterando sobre as linhas
    for (std::size_t i = 0ull; i < linhas; ++i)
    {
        // Iterando sobre as colunas
        for (std::size_t j = 0ull; j < colunas; ++j)
        {
            // Exibe cada elemento da matriz com um espaçamento de 4 caracteres
            std::cout << std::setw(4) << matriz[i][j];
        }

        // Exibe a soma da linha à direita
        std::cout << " | " << somarLinhas[i] << '\n';
    }

    // Exibindo as somas das colunas e a soma total no final
    std::cout << "------------------------------" << '\n';

    // Iterando sobre as colunas
    for (std::size_t i = 0ull; i < linhas; ++i)
    {
        // Exibe a soma de cada coluna
        std::cout << std::setw(4) << somarColunas[i];
    }

    // Exibe a soma total dos valores da matriz
    std::cout << " | " << valoresSomados << '\n';

    std::cout << "\n------------------------------" << '\n';

    // Matriz com representação mais moderna utilizando com std::array (C++11)
    std::cout << "\tMatriz com std::array" << '\n';

    // Definindo uma matriz 3x3 usando std::array e valores já definidos
    std::array<std::array<double, 3>, 3> matriz2 = {
        {{1.1, 1.2, 1.3},
         {2.1, 2.2, 2.3},
         {3.1, 3.2, 3.3}}};

    // Modificando elementos da matriz2
    for (std::size_t i = 0ull; i < matriz2.size(); ++i)
    {
        for (std::size_t j = 0ull; j < matriz2[i].size(); ++j)
        {
            matriz2[i][j] += 1.0; // Incrementa cada elemento em 1.0
        }
    }

    // Exibindo a matriz usando std::array
    for (const auto &linha : matriz2)
    {
        for (const auto &elemento : linha)
        {
            std::cout << '\t' << std::setw(4) << elemento;
        }
        std::cout << '\n';
    }

    return 0;
}

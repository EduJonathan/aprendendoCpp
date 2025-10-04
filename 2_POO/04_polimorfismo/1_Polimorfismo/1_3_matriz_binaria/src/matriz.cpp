#include "../class/class_matriz.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Construtor para inicializar a matriz com zeros
Matriz::Matriz()
{
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            matriz[i][j] = 0;
}

// Método para exibir a matriz
void Matriz::exibirMatriz() const
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            std::cout << matriz[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

// Método para atualizar uma linha aleatória com valores binários de um valor polimórfico
void Matriz::atualizarLinhaComBinario(Valor *valor)
{
    std::string binario = valor->paraBinario(); // Obtém o valor binário
    int linhaAleatoria = std::rand() % 8;       // Escolhe uma linha aleatória de 0 a 7

    std::cout << "Atualizando linha " << linhaAleatoria + 1 << " com o valor binário: " << binario << '\n';

    // Atualiza a linha com os valores binários
    for (int i = 0; i < 8; ++i)
    {
        matriz[linhaAleatoria][i] = binario[i] == '1' ? 1 : 0;
    }
}

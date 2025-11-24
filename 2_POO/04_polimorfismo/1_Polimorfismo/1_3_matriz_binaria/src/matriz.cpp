#include "../class/class_matriz.hpp"
#include <iostream>
#include <random>
#include <algorithm>

static std::mt19937 rng(std::random_device{}());
static std::uniform_int_distribution<int> dist(0, 7);

// Construtor para inicializar a matriz com zeros
Matriz::Matriz()
{
    for (auto &linha : matriz)
        for (int &celula : linha)
            celula = 0;
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
    std::cout << '\n';
}

// Método para atualizar uma linha aleatória com valores binários de um valor polimórfico
void Matriz::atualizarLinhaAleatoria(const std::unique_ptr<Valor> &valor)
{
    // Garante linha única
    int linha = 0;
    do
    {
        linha = dist(rng);
    } while (std::find(linhasUsadas.begin(), linhasUsadas.end(), linha) != linhasUsadas.end());

    linhasUsadas.push_back(linha);

    std::string bin = valor->paraBinario();
    std::cout << "Atualizando linha " << (linha + 1)
              << " → " << bin << "  ←  ";
    valor->exibirValor();
    std::cout << '\n';

    for (int j = 0; j < 8; ++j)
    {
        matriz[linha][j] = (bin[j] == '1') ? 1 : 0;
    }
}

#ifndef CLASS_MATRIZ_HPP
#define CLASS_MATRIZ_HPP

#include "class_value.hpp"
#include <memory>
#include <vector>

class Matriz
{
private:
    int matriz[8][8]; // Matriz 8x8
    std::vector<int> linhasUsadas;

public:
    // Construtor para inicializar a matriz
    Matriz();

    // Método para exibir a matriz
    void exibirMatriz() const;

    // Método para atualizar uma linha aleatória com valores binários de um valor polimórfico
    void atualizarLinhaAleatoria(const std::unique_ptr<Valor> &valor);
};

#endif // MATRIZ_HPP

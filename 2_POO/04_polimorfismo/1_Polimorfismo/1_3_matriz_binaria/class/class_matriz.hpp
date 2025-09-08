#ifndef CLASS_MATRIZ_HPP
#define CLASS_MATRIZ_HPP

#include <string>
#include "class_value.hpp" // Incluir o cabeçalho da classe base

class Matriz
{
private:
    int matriz[8][8]; // Matriz 8x8

public:
    // Construtor para inicializar a matriz
    Matriz();

    // Método para exibir a matriz
    void exibirMatriz() const;

    // Método para atualizar uma linha aleatória com valores binários de um valor polimórfico
    void atualizarLinhaComBinario(Valor *valor);
};

#endif // MATRIZ_HPP

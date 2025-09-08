#ifndef CLASS_PRODUTO_HPP
#define CLASS_PRODUTO_HPP

#include "classCompetidor.hpp"

/**
 * @class Produto
 * @brief Representa a classe Produto com um valor inteiro.
 *
 * A classe Produto contém um único atributo inteiro e fornece uma função amiga
 * 'compararValor' que compara o valor de Produto com o valor de Competidor.
 */
class Produto
{
private:
    int valorProduto; /**< Atributo privado que armazena o valor do produto. */

public:
    /**
     * @brief Construtor da classe Produto.
     *
     * Este construtor inicializa o atributo 'valorProduto' com o valor fornecido.
     *
     * @param valor Valor para inicializar o atributo 'valorProduto'.
     */
    Produto(int valor);

    /**
     * @brief Declara a função amiga compararValor.
     *
     * A função 'compararValor' compara os valores de Produto e Competidor e é
     * capaz de acessar o atributo privado de Produto.
     *
     * @param p Objeto da classe Produto.
     * @param c Objeto da classe Competidor.
     * @return Retorna true ou false dependendo da comparação entre os valores.
     */
    friend bool compararValor(Produto p, Competidor c);
};

#endif

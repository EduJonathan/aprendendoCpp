#ifndef COMPETIDOR_HPP
#define COMPETIDOR_HPP

#include "classProduto.hpp"
#include "classCompetidor.hpp"

/**
 * @class Competidor
 * @brief Representa a classe Competidor com um valor inteiro.
 *
 * A classe Competidor contém um único atributo inteiro e fornece acesso a esse valor.
 */
class Competidor
{
private:
    int valorCompetidor; /**< Atributo privado que armazena o valor do competidor. */

public:
    /**
     * @brief Construtor da classe Competidor.
     *
     * Este construtor inicializa o atributo 'valorCompetidor' com o valor fornecido.
     *
     * @param valor Valor para inicializar o atributo 'valorCompetidor'.
     */
    Competidor(int valor);

    /**
     * @brief Declara a função amiga compararValor.
     *
     * A função 'compararValor' compara os valores de Produto e Competidor e
     * é capaz de acessar o atributo privado de Competidor.
     *
     * @param p Objeto da classe Produto.
     * @param c Objeto da classe Competidor.
     * @return Retorna true ou false dependendo da comparação entre os valores.
     */
    friend bool compararValor(Produto p, Competidor c);
};

#endif

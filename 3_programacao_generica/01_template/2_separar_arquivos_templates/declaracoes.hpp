#ifndef MINHACLASSE_HPP
#define MINHACLASSE_HPP

/**
 * @brief Declaração da classe template MinhaClasse.
 * Esta classe é um exemplo simples de uma classe template que armazena um valor do tipo T e
 * fornece métodos para adicionar e obter esse valor.
 *
 * @tparam T O tipo de dado que a classe irá armazenar.
 */
template <typename T>
class MinhaClasse
{
public:
    /**
     * @brief Construtor padrão da classe MinhaClasse.
     */
    MinhaClasse();

    /**
     * @brief Adiciona um valor do tipo T à instância da classe.
     *
     * @param valor O valor do tipo T a ser adicionado.
     */
    void adicionar(const T &valor);

    /**
     * @brief Retorna o valor armazenado na instância da classe.
     *
     * @return O valor do tipo T armazenado na classe.
     */
    T obterValor() const;

private:
    T valor; // Variável para armazenar o valor do tipo T.
};

// Sempre inclua o .tpp no final do .hpp após as declarações, para que as implementações estejam disponíveis ao compilador.
#include "templates.tpp"

#endif // MINHACLASSE_HPP

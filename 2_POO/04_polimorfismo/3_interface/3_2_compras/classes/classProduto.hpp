#ifndef CLASS_PRODUTO_HPP
#define CLASS_PRODUTO_HPP

#include "../interfaces/interface_produto.hpp"
#include <string>

/**
 * @class GPU
 * @brief Representa uma unidade de processamento gráfico.
 *
 * Esta classe herda da interface IProduto e define as funções específicas de um produto do tipo GPU.
 */
class GPU : public IProduto
{
    std::string modelo; // Modelo da GPU
    double preco;       // Preço da GPU

public:
    /**
     * @brief Construtor da classe GPU.
     *
     * Inicializa a GPU com o modelo e o preço fornecidos.
     *
     * @param modelo Modelo da GPU.
     * @param preco Preço da GPU.
     */
    GPU(std::string modelo, double preco);

    /**
     * @brief Exibe os detalhes da GPU.
     *
     * Função que imprime as informações do modelo e preço da GPU.
     */
    void exibirDetalhes() const override;

    /**
     * @brief Retorna o preço da GPU.
     *
     * @return O preço da GPU.
     */
    double getPreco() const override;
};

/**
 * @class CPU
 * @brief Representa uma unidade central de processamento.
 *
 * Esta classe herda da interface IProduto e define as funções específicas de um produto do tipo CPU.
 */
class CPU : public IProduto
{
    std::string modelo; // Modelo da CPU
    double preco;       // Preço da CPU

public:
    /**
     * @brief Construtor da classe CPU.
     *
     * Inicializa a CPU com o modelo e o preço fornecidos.
     *
     * @param modelo Modelo da CPU.
     * @param preco Preço da CPU.
     */
    CPU(std::string modelo, double preco);

    /**
     * @brief Exibe os detalhes da CPU.
     *
     * Função que imprime as informações do modelo e preço da CPU.
     */
    void exibirDetalhes() const override;

    /**
     * @brief Retorna o preço da CPU.
     *
     * @return O preço da CPU.
     */
    double getPreco() const override;
};

/**
 * @class RAM
 * @brief Representa a memória RAM.
 *
 * Esta classe herda da interface IProduto e define as funções específicas de um produto do tipo RAM.
 */
class RAM : public IProduto
{
    std::string modelo; // Modelo da RAM
    double preco;       // Preço da RAM

public:
    /**
     * @brief Construtor da classe RAM.
     *
     * Inicializa a RAM com o modelo e o preço fornecidos.
     *
     * @param modelo Modelo da RAM.
     * @param preco Preço da RAM.
     */
    RAM(std::string modelo, double preco);

    /**
     * @brief Exibe os detalhes da RAM.
     *
     * Função que imprime as informações do modelo e preço da RAM.
     */
    void exibirDetalhes() const override;

    /**
     * @brief Retorna o preço da RAM.
     *
     * @return O preço da RAM.
     */
    double getPreco() const override;
};

/**
 * @class Gabinete
 * @brief Representa um gabinete de computador.
 *
 * Esta classe herda da interface IProduto e define as funções específicas de um produto do tipo Gabinete.
 */
class Gabinete : public IProduto
{
    std::string modelo; // Modelo do Gabinete
    double preco;       // Preço do Gabinete

public:
    /**
     * @brief Construtor da classe Gabinete.
     *
     * Inicializa o Gabinete com o modelo e o preço fornecidos.
     *
     * @param modelo Modelo do Gabinete.
     * @param preco Preço do Gabinete.
     */
    Gabinete(std::string modelo, double preco);

    /**
     * @brief Exibe os detalhes do Gabinete.
     *
     * Função que imprime as informações do modelo e preço do Gabinete.
     */
    void exibirDetalhes() const override;

    /**
     * @brief Retorna o preço do Gabinete.
     *
     * @return O preço do Gabinete.
     */
    double getPreco() const override;
};

#endif

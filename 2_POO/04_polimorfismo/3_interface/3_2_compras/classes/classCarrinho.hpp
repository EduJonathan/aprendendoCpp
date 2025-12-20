#ifndef CLASS_CARRINHO_HPP
#define CLASS_CARRINHO_HPP

#include "../interfaces/interface_produto.hpp"
#include "../interfaces/interface_cupom.hpp"
#include "../interfaces/interface_pagamento.hpp"
#include <vector>
#include <memory>

/**
 * @class Carrinho
 * @brief Representa um carrinho de compras que armazena produtos, aplica cupons de desconto
 *        e realiza a finalização de compras com métodos de pagamento.
 */
class Carrinho
{
    /// Lista de produtos adicionados ao carrinho.
    std::vector<std::shared_ptr<IProduto>> itens;

    /// Cupom de desconto aplicado ao carrinho.
    std::shared_ptr<ICupom> cupom;

public:
    /**
     * @brief Adiciona um produto ao carrinho.
     * 
     * @param produto Produto a ser adicionado (shared_ptr para IProduto).
     */
    void adicionarProduto(std::shared_ptr<IProduto> produto);

    /**
     * @brief Aplica um cupom de desconto ao carrinho.
     * 
     * @param novoCupom Cupom a ser aplicado (shared_ptr para ICupom).
     */
    void aplicarCupom(std::shared_ptr<ICupom> novoCupom);

    /**
     * @brief Lista todos os produtos atualmente no carrinho.
     */
    void listarProdutos() const;

    /**
     * @brief Calcula o valor total bruto (sem desconto) dos produtos no carrinho.
     * 
     * @return Valor total bruto.
     */
    double calcularTotalBruto() const;

    /**
     * @brief Calcula o valor total com o desconto aplicado pelo cupom.
     * 
     * @return Valor total com desconto.
     */
    double calcularTotalComDesconto() const;

    /**
     * @brief Finaliza a compra utilizando um método de pagamento.
     * 
     * @param metodoPagamento Referência para a implementação da interface de pagamento (IPagamento).
     */
    void finalizarCompra(const IPagamento &metodoPagamento) const;
};

#endif

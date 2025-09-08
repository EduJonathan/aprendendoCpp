#ifndef CLASS_PAGAMENTO_HPP
#define CLASS_PAGAMENTO_HPP

#include "../interfaces/interface_pagamento.hpp"

class CartaoCredito : public IPagamento
{
public:
    /**
     * @brief Realiza o pagamento utilizando cartão de crédito.
     *
     * @param valor O valor a ser pago.
     */
    void pagar(double valor) const override;
};

class Pix : public IPagamento
{
public:
    /**
     * @brief Realiza o pagamento utilizando Pix.
     *
     * @param valor O valor a ser pago.
     */
    void pagar(double valor) const override;
};

#endif

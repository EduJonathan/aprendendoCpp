#ifndef CLASS_BOLETO_BANCARIO_HPP
#define CLASS_BOLETO_BANCARIO_HPP

#include "classModoPagamento.hpp"

/**
 * @class BoletoBancario
 *
 * @brief Implementa o pagamento por boleto bancário.
 */
class BoletoBancario : public ModoPagamento
{
public:
    /**
     * @brief Gera e exibe um boleto bancário.
     *
     * @param valor Valor da compra.
     */
    void processarPagamento(double valor) override;

    /**
     * @brief Retorna a descrição do método.
     *
     * @return "Boleto Bancário"
     */
    std::string getDescricao() const override;
};

#endif

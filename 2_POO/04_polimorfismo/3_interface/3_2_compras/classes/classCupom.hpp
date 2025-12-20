#ifndef CLASS_CUPOM_HPP
#define CLASS_CUPOM_HPP

#include "../interfaces/interface_cupom.hpp"

class Cupom10Porcento : public ICupom
{
public:
    /**
     * @brief Aplica um desconto de 10% ao valor total da compra.
     *
     * @param valorTotal O valor total bruto da compra antes do desconto.
     * @return O valor com desconto aplicado.
     */
    double aplicarDesconto(double valorTotal) const override;
};

class CupomValorFixo : public ICupom
{
    double desconto;

public:
    /**
     * @brief Construtor da classe CupomValorFixo.
     *
     * @param desconto O valor fixo de desconto a ser aplicado.
     */
    CupomValorFixo(double desconto);

    /**
     * @brief Aplica um desconto fixo ao valor total da compra.
     *
     * @param valorTotal O valor total bruto da compra antes do desconto.
     * @return O valor com desconto aplicado.
     */
    double aplicarDesconto(double valorTotal) const override;
};

#endif

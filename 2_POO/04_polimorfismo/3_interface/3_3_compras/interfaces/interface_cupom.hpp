#ifndef INTERFACE_CUPOM_HPP
#define INTERFACE_CUPOM_HPP

class ICupom
{
public:
    /**
     * @brief Aplica um desconto ao valor total da compra.
     *
     * @param valorTotal O valor total bruto da compra antes do desconto.
     * @return O valor com desconto aplicado.
     */
    virtual double aplicarDesconto(double valorTotal) const = 0;

    virtual ~ICupom() {}
};

#endif

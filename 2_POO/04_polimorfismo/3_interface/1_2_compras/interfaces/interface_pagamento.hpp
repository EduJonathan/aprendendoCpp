#ifndef INTERFACE_PAGAMENTO_HPP
#define INTERFACE_PAGAMENTO_HPP

class IPagamento
{
public:
    /**
     * @brief Realiza o pagamento de um determinado valor.
     *
     * @param valor O valor a ser pago.
     */
    virtual void pagar(double valor) const = 0;
    
    virtual ~IPagamento() {}
};

#endif

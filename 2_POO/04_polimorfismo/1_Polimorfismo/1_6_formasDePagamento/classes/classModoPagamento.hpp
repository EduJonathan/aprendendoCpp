#ifndef CLASS_MODO_PAGAMENTO_HPP
#define CLASS_MODO_PAGAMENTO_HPP

#include <string>

/**
 * @class ModoPagamento
 *
 * @brief Interface base para diferentes métodos de pagamento.
 */
class ModoPagamento
{
public:
    /**
     * @brief Destrutor virtual.
     */
    virtual ~ModoPagamento() = default;

    /**
     * @brief Processa um pagamento.
     *
     * @param valor Valor do pagamento.
     */
    virtual void processarPagamento(double valor) = 0;

    /**
     * @brief Retorna uma descrição do método de pagamento.
     *
     * @return String com a descrição.
     */
    virtual std::string getDescricao() const = 0;
};

#endif

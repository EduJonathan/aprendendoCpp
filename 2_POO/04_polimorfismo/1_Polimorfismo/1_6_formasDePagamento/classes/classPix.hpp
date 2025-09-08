#ifndef CLASS_PIX_HPP
#define CLASS_PIX_HPP

#include "classModoPagamento.hpp"
#include <string>

/**
 * @class Pix
 *
 * @brief Implementa o pagamento via PIX.
 */
class Pix : public ModoPagamento
{
private:
    std::string chavePix;

public:
    /**
     * @brief Construtor.
     *
     * @param chave Chave PIX usada para pagamento.
     */
    Pix(const std::string &chave);

    /**
     * @brief Processa o pagamento via PIX.
     *
     * @param valor Valor a ser transferido.
     */
    void processarPagamento(double valor) override;

    /**
     * @brief Retorna a descrição do método.
     *
     * @return String com a chave PIX.
     */
    std::string getDescricao() const override;
};

#endif

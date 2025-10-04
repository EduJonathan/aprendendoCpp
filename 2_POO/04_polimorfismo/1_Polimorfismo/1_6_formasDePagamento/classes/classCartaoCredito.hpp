#ifndef CLASS_CARTAO_CREDITO_HPP
#define CLASS_CARTAO_CREDITO_HPP

#include <string>
#include <vector>
#include "classModoPagamento.hpp"

/**
 * @class CartaoCredito
 *
 * @brief Implementa pagamento via cartão de crédito com validação e parcelamento.
 */
class CartaoCredito : public ModoPagamento
{
private:
    std::string numeroCartao;
    std::string nomeTitular;
    std::string dataValidade;
    std::string cvv;
    int parcelas;

    /**
     * @brief Valida o número do cartão usando o algoritmo de Luhn.
     *
     * @return true se válido, false caso contrário.
     */
    bool validarNumeroCartao() const;

    /**
     * @brief Verifica se a data de validade é posterior à data atual.
     *
     * @return true se válida, false caso contrário.
     */
    bool validarData() const;

    /**
     * @brief Valida o código CVV.
     *
     * @return true se válido.
     */
    bool validarCVV() const;

    /**
     * @brief Calcula os valores de cada parcela.
     *
     * @param valorTotal Valor total da compra.
     * @param numParcelas Quantidade de parcelas.
     * @return Vetor com os valores das parcelas.
     */
    std::vector<double> calcularParcelas(double valorTotal, int numParcelas) const;

    /**
     * @brief Determina o número máximo de parcelas permitidas.
     *
     * @param valor Valor da compra.
     * @return Número máximo de parcelas.
     */
    int determinarMaxParcelas(double valor) const;

public:
    /**
     * @brief Construtor.
     *
     * @param num Número do cartão.
     * @param nome Nome do titular.
     * @param validade Data de validade no formato MM/AA.
     * @param cvv Código de segurança.
     * @param parcelas Número de parcelas (padrão = 1).
     */
    CartaoCredito(const std::string &num, const std::string &nome,
                  const std::string &validade, const std::string &cvv, int parcelas = 1);

    /**
     * @brief Define o número de parcelas.
     *
     * @param numParcelas Número desejado de parcelas.
     * @throw std::invalid_argument se for inválido.
     */
    void setParcelas(int numParcelas);

    /**
     * @brief Processa o pagamento com cartão.
     *
     * @param valor Valor total da compra.
     * @throw std::runtime_error em caso de erro na validação.
     */
    void processarPagamento(double valor) override;

    /**
     * @brief Retorna a descrição do pagamento.
     * @return String com descrição.
     */
    std::string getDescricao() const override;

    /**
     * @brief Retorna os últimos 4 dígitos do cartão.
     *
     * @return String com os 4 últimos dígitos.
     */
    std::string getUltimosDigitos() const;

    /**
     * @brief Verifica se o cartão é válido.
     *
     * @return true se válido.
     */
    bool ehValido() const;
};

#endif

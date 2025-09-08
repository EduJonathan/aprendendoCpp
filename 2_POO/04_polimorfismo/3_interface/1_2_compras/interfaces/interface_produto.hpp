#ifndef INTERFACE_PRODUTO_HPP
#define INTERFACE_PRODUTO_HPP

class IProduto
{
public:
    /**
     * @brief Exibe detalhes específicos da implementação (ex: método de pagamento ou produto).
     */
    virtual void exibirDetalhes() const = 0;

    /**
     * @brief Obtém o preço do item/produto.
     *
     * @return O preço atual do produto.
     */
    virtual double getPreco() const = 0;
    virtual ~IProduto() {}
};

#endif

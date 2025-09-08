#ifndef CLASS_CARRO_HPP
#define CLASS_CARRO_HPP

#include <string>

/**
 * @class Carro
 *
 * @brief Classe que representa um carro, contendo informações
 * sobre a marca, ano, custo e preço de venda.
 */
class Carro
{
public:
    std::string marca; // Marca do carro
    int ano;           // Ano de fabricação
    double custo;      // Custo do carro
    double precoVenda; // Preço de venda do carro

    void setDadosDoCarro(const std::string &marca, int year, double cost, double preco);
    void exibirInformacoes() const;
    static void exibirInformacoesDoCarro(const Carro &car);
};

#endif

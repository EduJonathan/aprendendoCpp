#include <iostream>
#include <iomanip>
#include "class_carro.hpp"

/**
 * @brief Configura as informações de um carro.
 *
 * Este método inicializa os atributos do objeto com os valores fornecidos.
 *
 * @param marca Nome da marca do carro.
 * @param year Ano de fabricação do carro.
 * @param cost Custo do carro.
 * @param preco Preço de venda do carro.
 *
 * @note this em C++ representa o ponteiro para o objeto, ou seja, referencia o próprio objeto.
 */
void Carro::setDadosDoCarro(const std::string &marca, int year, double cost, double preco)
{
    this->marca = marca;
    this->ano = year;
    this->custo = cost;
    this->precoVenda = preco;
}

/**
 * @brief Exibe as informações de um carro.
 *
 * Este método imprime na tela as informações detalhadas do carro,
 * incluindo marca, ano, custo e preço de venda.
 */
void Carro::exibirInformacoes(void) const
{
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Marca: " << marca << '\n';
    std::cout << "Ano: " << ano << '\n';
    std::cout << "Custo: R$" << custo << '\n';
    std::cout << "Preço de Venda: R$" << precoVenda << '\n';
}

/**
 * @brief Exibe as informações de um carro passado como argumento.
 *
 * Este método imprime na tela as informações detalhadas do carro.
 *
 * @param car Objeto da classe Carro contendo as informações a serem exibidas.
 */
void Carro::exibirInformacoesDoCarro(const Carro &car)
{
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "Marca: " << car.marca << '\n';
    std::cout << "Ano: " << car.ano << '\n';
    std::cout << "Custo: R$" << car.custo << '\n';
    std::cout << "Preço de Venda: R$" << car.precoVenda << '\n';
}

int main(int argc, char **argv)
{
    Carro bmw;
    bmw.setDadosDoCarro("BMW", 1917, 50000.00, 190000.00);
    bmw.exibirInformacoes();

    std::cout << "----------------------------------\n";

    Carro mercedes;
    mercedes.setDadosDoCarro("Mercedes", 1901, 62450.00, 240000.00);
    mercedes.exibirInformacoes();

    std::cout << "----------------------------------\n";

    Carro audi;
    audi.setDadosDoCarro("Audi", 1960, 35000.00, 190000.00);
    Carro::exibirInformacoesDoCarro(audi);
    return 0;
}

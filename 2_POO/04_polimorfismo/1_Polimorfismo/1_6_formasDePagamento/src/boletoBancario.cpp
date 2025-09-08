#include "../classes/classBoletoBancario.hpp"
#include <iostream>

void BoletoBancario::processarPagamento(double valor)
{
    std::cout << "Gerando boleto bancário no valor de R$" << valor << '\n';
}

std::string BoletoBancario::getDescricao() const
{
    return "Boleto Bancário";
}

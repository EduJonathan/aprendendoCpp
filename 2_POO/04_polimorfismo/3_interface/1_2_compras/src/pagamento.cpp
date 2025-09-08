#include "../classes/classPagamento.hpp"
#include <iostream>

void CartaoCredito::pagar(double valor) const
{
    std::cout << "Pagamento de R$" << valor << " realizado com Cartão de Crédito.\n";
}

void Pix::pagar(double valor) const
{
    std::cout << "Pagamento de R$" << valor << " realizado via Pix.\n";
}

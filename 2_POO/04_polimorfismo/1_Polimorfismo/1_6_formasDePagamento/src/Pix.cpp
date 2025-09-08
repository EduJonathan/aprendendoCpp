#include "../classes/classPix.hpp"
#include <iostream>

Pix::Pix(const std::string &chave) : chavePix(chave) {}

void Pix::processarPagamento(double valor)
{
    std::cout << "Processando pagamento PIX de R$" << valor << " para a chave " << chavePix << '\n';
}

std::string Pix::getDescricao() const
{
    return "PIX (" + chavePix + ')';
}

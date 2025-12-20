#include "../classes/classCupom.hpp"

CupomValorFixo::CupomValorFixo(double desconto) : desconto(desconto) {}

double Cupom10Porcento::aplicarDesconto(double valorTotal) const
{
    return valorTotal * 0.90;
}

double CupomValorFixo::aplicarDesconto(double valorTotal) const
{
    return (valorTotal - desconto >= 0) ? valorTotal - desconto : 0;
}

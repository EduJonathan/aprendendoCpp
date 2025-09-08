#include "../class/class_decimal.hpp"
#include <bitset>
#include <iostream>

Decimal::Decimal(int v) : valor(v) {}

std::string Decimal::paraBinario() const
{
    return std::bitset<8>(valor).to_string(); // Converte para binário com 8 bits
}

void Decimal::exibirValor() const
{
    std::cout << "Valor Decimal: " << valor << " => Binário: " << paraBinario() << '\n';
}

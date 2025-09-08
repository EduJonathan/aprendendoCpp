#include "../class/class_octal.hpp"
#include <bitset>
#include <iostream>

Octal::Octal(int v) : valor(v) {}

std::string Octal::paraBinario() const
{
    return std::bitset<8>(valor).to_string(); // Converte para binário com 8 bits
}

void Octal::exibirValor() const
{
    std::cout << "Valor Octal: " << valor << " => Binário: " << paraBinario() << '\n';
}

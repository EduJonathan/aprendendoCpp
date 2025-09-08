#include "../class/class_hexadecimal.hpp"
#include <iostream>
#include <bitset>

Hexadecimal::Hexadecimal(int v) : valor(v) {}

std::string Hexadecimal::paraBinario() const
{
    return std::bitset<8>(valor).to_string(); // Converte para binário com 8 bits
}

void Hexadecimal::exibirValor() const
{
    std::cout << "Valor Hexadecimal: " << valor << " => Binário: " << paraBinario() << '\n';
}

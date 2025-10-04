#include "../class/classHexadecimal.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

Hexadecimal::Hexadecimal(const std::string &hex) : hex(hex)
{
    if (hex.length() != 6)
        throw std::invalid_argument("Hex deve ter 6 caracteres (ex: FF0000).");
}

void Hexadecimal::exibir() const
{
    // Desestrutura a tupla manualmente
    // std::tuple<int, int, int> rgb = paraRGB();
    // int r = std::get<0>(rgb);
    // int g = std::get<1>(rgb);
    // int b = std::get<2>(rgb);

    auto [r, g, b] = paraRGB(); // C++17 Desestruturação de tupla
    std::cout << "Hexadecimal: #" << hex << " => RGB(" << r << ", " << g << ", " << b << ")\n";
}

std::string Hexadecimal::comoString() const
{
    return '#' + hex;
}

std::tuple<int, int, int> Hexadecimal::paraRGB() const
{
    int r = std::stoi(hex.substr(0, 2), nullptr, 16);
    int g = std::stoi(hex.substr(2, 2), nullptr, 16);
    int b = std::stoi(hex.substr(4, 2), nullptr, 16);
    return {r, g, b};
}

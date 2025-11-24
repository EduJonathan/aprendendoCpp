#include "../class/classHexadecimal.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <stdexcept>

Hexadecimal::Hexadecimal(const std::string &codigo) : hex(normalizar(codigo)) {}

std::string Hexadecimal::normalizar(const std::string &entrada)
{
    std::string s = entrada;
    
    // Remove espaços e #
    s.erase(std::remove_if(s.begin(), s.end(), [](char c)
    {
        return std::isspace(c) || c == '#';
    }), s.end());

    if (s.length() != 6)
        throw std::invalid_argument("Código hexadecimal deve ter 6 caracteres (ex: FF00A5 ou #FF00A5)");

    // Valida se são dígitos hexadecimais
    for (char c : s)
    {
        if (!std::isxdigit(static_cast<unsigned char>(c)))
            throw std::invalid_argument(std::string("Caractere inválido em hexadecimal: '") + c + "'");
    }

    // Converte para maiúscula
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
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

const std::string & Hexadecimal::valor() const { return hex; }

#include "../class/classRgb.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

RGB::RGB(int r, int g, int b) : r(r), g(g), b(b)
{
    validar(r);
    validar(g);
    validar(b);
}

// Construtor a partir de Hexadecimal — muito útil!
RGB::RGB(const Hexadecimal &hex)
{
    auto [red, green, blue] = hex.paraRGB();
    r = red;
    g = green;
    b = blue;
}

void RGB::validar(int valor)
{
    if (valor < 0 || valor > 255)
        throw std::out_of_range("Valor RGB deve estar entre 0 e 255");
}

void RGB::exibir() const
{
    std::cout << "RGB(" << r << ", " << g << ", " << b << ") → " << comoString() << '\n';
}

std::string RGB::comoString() const
{
    std::ostringstream ss;
    ss << '#' << std::hex << std::uppercase << std::setfill('0')
       << std::setw(2) << r
       << std::setw(2) << g
       << std::setw(2) << b;
    return ss.str();
}

int RGB::getR() const { return r; }
int RGB::getG() const { return g; }
int RGB::getB() const { return b; }

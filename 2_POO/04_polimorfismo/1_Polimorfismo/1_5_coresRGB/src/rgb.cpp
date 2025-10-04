#include "../class/classRgb.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdexcept>

RGB::RGB(int r, int g, int b) : r(r), g(g), b(b)
{
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        throw std::out_of_range("Valor RGB deve estar entre 0 e 255.");
}

void RGB::exibir() const
{
    std::cout << "RGB(" << r << ", " << g << ", " << b << ") => " << paraHex() << '\n';
}

std::string RGB::comoString() const
{
    return paraHex();
}

std::string RGB::paraHex() const
{
    std::stringstream ss;
    ss << '#' << std::uppercase << std::setfill('0') << std::hex;

    ss << std::setw(2) << r;
    ss << std::setw(2) << g;
    ss << std::setw(2) << b;
    return ss.str();
}

int RGB::getR() const { return r; }
int RGB::getG() const { return g; }
int RGB::getB() const { return b; }

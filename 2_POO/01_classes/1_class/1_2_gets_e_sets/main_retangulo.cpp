#include <iostream>
#include <iomanip>
#include "class_rectangle.hpp"

/**
 * @note Em C++, os métodos `set` e `get` não são padrão da linguagem (como no Java/JavaBeans).
 * O uso dos nomes `setX` e `getX` é apenas adotado por convenção para clareza e organização.
 *
 * Em C++ temos liberdade para nomear métodos como quisermos, ao que se remete aos métodos,
 * como: `definirAltura()`, `obter_area_do_retangulo()`, etc.
 */

void Rectangle::setDimensoes(double width, double height)
{
    largura = width;
    altura = height;
}

double Rectangle::getAreaDoRetangulo(void) const
{
    return largura * altura;
}

int main(int argc, char **argv)
{
    // Cria um objeto da classe Rectangle
    Rectangle retangulo;

    // Define largura e altura do retângulo
    retangulo.setDimensoes(5.0, 3.0);

    // Exibe a área do retângulo
    std::cout << "Área total do retângulo: " << std::fixed << std::setprecision(2) << retangulo.getAreaDoRetangulo() << '\n';
    return 0;
}

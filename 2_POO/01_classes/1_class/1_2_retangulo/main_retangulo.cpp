#include <iostream>
#include <iomanip>
#include "class_rectangle.hpp"

/// @brief Implementa o método para definir a largura.
void Rectangle::setWidht(double widht)
{
    largura = widht;
}

/// @brief Implementa o método para definir a altura.
void Rectangle::setHeight(double height)
{
    altura = height;
}

/// @brief Implementa o cálculo da área do retângulo.
double Rectangle::getAreaDoRetangulo(void) const
{
    return largura * altura;
}

int main(int argc, char **argv)
{
    Rectangle retangulo; // Cria um objeto da classe Rectangle

    // Define largura e altura do retângulo
    retangulo.setWidht(3.0);
    retangulo.setHeight(4.0);

    // Exibe a área do retângulo
    std::cout << "Área total do retângulo: " << std::fixed << std::setprecision(2) << retangulo.getAreaDoRetangulo() << '\n';

    /**
     * @note Em C++, métodos `set` e `get` não são padrão da linguagem
     * (como no Java/JavaBeans). O uso dos nomes `setX` e `getX` é apenas
     * adotado por convenção para clareza e organização.
     *
     * Em C++ temos liberdade para nomear métodos como quisermos,
     * como: `definirAltura()`, `obter_area_do_retangulo()`, etc.
     */
    return 0;
}

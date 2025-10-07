#include <iostream>
#include <iomanip>
#include "class_circulo.hpp"

constexpr double PI = 3.14159;

void Circulo::setCirculo(double raio)
{
    radius = raio;
}

double Circulo::getRaio() const
{
    return radius;
}

double Circulo::calcularArea() const
{
    return PI * radius * radius;
}

void Circulo::imprimirCirculo() const
{
    std::cout << "Área do círculo: " << calcularArea() << '\n';
}

int main(int argc, char **argv)
{
    Circulo circulo; // Cria um objeto da classe Circulo

    circulo.setCirculo(5.0);              // Define o raio
    circulo.imprimirCirculo();            // Imprime a área
    double area = circulo.calcularArea(); // Calcula a área

    std::cout << "Área calculada manualmente: " << std::fixed << std::setprecision(2) << area << '\n';
    std::cout << "Raio atual do círculo: " << std::fixed << std::setprecision(2) << circulo.getRaio() << '\n';

    return 0;
}

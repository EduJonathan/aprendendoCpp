#include <iostream>
#include <string>
#include <memory>

class Forma
{
public:
    std::string nome;
    Forma(const std::string &n) : nome(n) {}

    void desenhar() const
    {
        std::cout << "Desenhando " << nome << '.' << '\n';
    }
};

class Circulo : public Forma
{
public:
    Circulo(const std::string &n) : Forma(n) {}

    void calcularArea(double raio) const
    {
        double area = 3.14159 * raio * raio;
        std::cout << "Calculando a área do círculo " << nome << " é " << area << '.' << '\n';
    }
};

class Quadrado : public Forma
{
public:
    Quadrado(const std::string &n) : Forma(n) {}

    void calcularArea(double lado) const
    {
        double area = lado * lado;
        std::cout << "Calculando a área do quadrado " << nome << " é " << area << '.' << '\n';
    }
};

int main(int argc, char **argv)
{
    auto circulo = std::make_unique<Circulo>("Círculo");
    circulo->desenhar();
    circulo->calcularArea(5.0);

    auto quadrado = std::make_unique<Quadrado>("Quadrado");
    quadrado->desenhar();
    quadrado->calcularArea(4.0);

    return 0;
}

#include <iostream>
#include <memory>

// Classe Base 1
class Motor
{
public:
    void ligar() const
    {
        std::cout << "Motor ligado." << '\n';
    }
};

// Classe Base 2
class Asas
{
public:
    void voar() const
    {
        std::cout << "Voando com asas." << '\n';
    }
};

// Classe Derivada que herda mais de uma classe base
class Aviao : public Motor, public Asas
{
public:
    void decolar() const
    {
        ligar();
        voar();
        std::cout << "Avião decolando." << '\n';
    }
};

int main(int argc, char **argv)
{
    std::unique_ptr<Aviao> meuAviao = std::make_unique<Aviao>();
    meuAviao->decolar();
    return 0;
}

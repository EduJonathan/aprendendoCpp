#include <iostream>
#include <new>
#include <stdexcept>

enum class Unidade
{
    Celsius,
    Fahrenheit,
    Kelvin
};

class Temperatura
{
private:
    double valor;
    Unidade unidade;

    // Converte qualquer valor para Celsius
    static double paraCelsius(double valor, Unidade u)
    {
        switch (u)
        {
        case Unidade::Celsius:
            return valor;

        case Unidade::Fahrenheit:
            return (valor - 32) * 5.0 / 9.0;

        case Unidade::Kelvin:
            return valor - 273.15;

        default:
            throw std::invalid_argument("Unidade inválida");
        }
    }

public:
    Temperatura(double v, Unidade u) : valor(v), unidade(u) {}

    // Converte para a unidade de destino
    double converter(Unidade destino) const
    {
        double celsius = paraCelsius(valor, unidade);

        switch (destino)
        {
        case Unidade::Celsius:
            return celsius;

        case Unidade::Fahrenheit:
            return (celsius * 9.0 / 5.0) + 32;

        case Unidade::Kelvin:
            return celsius + 273.15;

        default:
            throw std::invalid_argument("Unidade de destino inválida");
        }
    }

    void exibirConversoes(void) const
    {
        std::cout << "Temperatura original: " << valor << ' ';

        switch (unidade)
        {
        case Unidade::Celsius:
            std::cout << "°C\n";
            break;

        case Unidade::Fahrenheit:
            std::cout << "°F\n";
            break;

        case Unidade::Kelvin:
            std::cout << "K\n";
            break;
        }

        std::cout << "Em Celsius: " << converter(Unidade::Celsius) << " °C\n";
        std::cout << "Em Fahrenheit: " << converter(Unidade::Fahrenheit) << " °F\n";
        std::cout << "Em Kelvin: " << converter(Unidade::Kelvin) << " K\n";
    }
};

int main(int argc, char **argv)
{
    Temperatura temperatura1(100, Unidade::Fahrenheit);
    temperatura1.exibirConversoes();

    std::cout << "------------------\n";

    Temperatura *temperatura2 = new Temperatura(0, Unidade::Celsius);
    temperatura2->exibirConversoes();
    delete temperatura2;
    return 0;
}

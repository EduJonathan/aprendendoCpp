#include <iostream>
#include <stdexcept>
#include <memory>

class Distancia
{
private:
    double metros; // Armazena a distância em metros

public:
    // Construtor para inicializar a distância em metros
    Distancia(double m = 0) : metros(m) {}

    // Sobrecarga do operador *= para multiplicar a distância por um fator
    Distancia &operator*=(double fator)
    {
        metros *= fator;
        return *this; // Retorna o objeto atualizado
    }

    // Sobrecarga do operador /= para dividir a distância por um fator
    Distancia &operator/=(double fator)
    {
        if (fator == 0)
        {
            throw std::invalid_argument("Não é possível dividir por zero.");
        }
        metros /= fator;
        return *this; // Retorna o objeto atualizado
    }

    // Função para exibir a distância em metros
    void imprimir() const
    {
        std::cout << metros << " metros" << '\n';
    }

    // Função para obter a distância em metros
    double getDistancia() const
    {
        return metros;
    }
};

int main(int argc, char **argv)
{
    try
    {
        std::unique_ptr<Distancia> distancia = std::make_unique<Distancia>(200);

        std::cout << "Distância original: ";
        distancia->imprimir();

        // Multiplicando a distância por 2 para simular uma conversão (por exemplo, metros para centímetros)
        *distancia *= 2;
        std::cout << "Após multiplicar por 2: ";
        distancia->imprimir(); // Resultado: 200 metros

        // Dividindo a distância por 2 para simular uma conversão inversa
        *distancia /= 2;
        std::cout << "Após dividir por 2: ";
        distancia->imprimir(); // Resultado: 100 metros

        // Dividindo a distância por 10 para simular uma conversão para quilômetros
        *distancia /= 1000;
        std::cout << "Após dividir por 1000 (para km): ";
        distancia->imprimir(); // Resultado: 0.1 metros (ou 10 centímetros)
    }
    catch (const std::exception &e)
    {
        std::cout << "Erro: " << e.what() << '\n';
    }

    return 0;
}

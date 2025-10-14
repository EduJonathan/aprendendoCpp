#include <iostream>
#include <cmath>
#include <new>

class Vetor
{
public:
    double x, y;
    Vetor(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Sobrecarga do operador + (membro da classe)
    Vetor operator+(const Vetor &outro) const
    {
        return Vetor(x + outro.x, y + outro.y);
    }

    // Sobrecarga do operador -
    Vetor operator-(const Vetor &outro) const
    {
        return Vetor(x - outro.x, y - outro.y);
    }

    // Norma (magnitude do vetor)
    double norma(void) const
    {
        return std::sqrt(x * x + y * y);
    }
};

int main(int argc, char **argv)
{
    Vetor *posicaoAtual = new Vetor(1.0, 2.0);
    Vetor *posicaoDestino = new Vetor(3.0, 4.0);
    Vetor resultado = *posicaoAtual + *posicaoDestino; // Usa operator+
    std::cout << "Resultado: (" << resultado.x << ", " << resultado.y << ")\n";

    // Calcula o vetor diferença (destino - atual)
    Vetor diferenca = *posicaoDestino - *posicaoAtual;

    // A distância é o comprimento desse vetor
    double distancia = diferenca.norma();

    std::cout << "Distância faltando: " << distancia << " unidades\n";

    delete posicaoAtual;
    delete posicaoDestino;
    return 0;
}

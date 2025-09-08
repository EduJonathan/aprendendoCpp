#include <iostream>

/**
 * Herança multinível: Ocorre quando uma classe herda de outra que, por sua vez,
 * já herdou de outra. Isso cria uma cadeia onde cada classe pode expandir as 
 * funcionalidades das classes anteriores.
 */

// Classe base
class Veiculo
{
public:
    void tipo(void)
    {
        std::cout << "Sou um veículo." << '\n';
    }
};

// Classe intermediária herdando de Veiculo
class Carro : public Veiculo
{
public:
    void marca(void)
    {
        std::cout << "Sou um carro da marca XYZ." << '\n';
    }
};

// Classe final herdando de Carro
class Esportivo : public Carro
{
public:
    void velocidade(void)
    {
        std::cout << "Sou um carro esportivo e sou muito rápido!" << '\n';
    }
};

int main(int argc, char **argv)
{
    Esportivo meuCarro;
    meuCarro.tipo();       // Método da classe Veiculo
    meuCarro.marca();      // Método da classe Carro
    meuCarro.velocidade(); // Método da classe Esportivo

    return 0;
}

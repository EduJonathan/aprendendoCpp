#include "../classes/classVeiculoTerrestre.hpp"
#include <memory>

class Moto : public Terrestre
{
public:
    void mover() const override final
    {
        std::cout << "A moto está acelerando na pista.\n";
    }

    void tipo() const override final
    {
        std::cout << "Esta é uma moto esportiva.\n";
    }
};

// Veiculo *criarMoto() { return new Moto(); }

std::unique_ptr<Veiculo> criarMoto()
{
    return std::make_unique<Moto>();
}

#include "../classes/classVeiculoTerrestre.hpp"
#include <memory>

class Carro : public Terrestre
{
public:
    void mover() const override final
    {
        std::cout << "O carro está dirigindo pela rodovia.\n";
    }

    void tipo() const override final
    {
        std::cout << "Este é um carro esportivo.\n";
    }
};

// Veiculo *criarCarro() { return new Carro(); }

std::unique_ptr<Veiculo> criarCarro()
{
    return std::make_unique<Carro>(); // Usando std::make_unique
}

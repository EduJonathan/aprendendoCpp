#include "../classes/classVeiculoAquatico.hpp"
#include <memory>

class Barco : public Aquatico
{
public:
    void mover() const override final
    {
        std::cout << "O barco está navegando no mar.\n";
    }

    void tipo() const override final
    {
        std::cout << "Este é um barco de pesca.\n";
    }
};

// Veiculo *criarBarco() { return new Barco(); }

std::unique_ptr<Veiculo> criarBarco()
{
    return std::make_unique<Barco>();
}

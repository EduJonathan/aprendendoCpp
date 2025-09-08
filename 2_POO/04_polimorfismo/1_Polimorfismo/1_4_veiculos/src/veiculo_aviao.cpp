#include "../classes/classVeiculoAreo.hpp"
#include <memory>

class Aviao : public Aereo
{
public:
    void mover() const override final
    {
        std::cout << "O avião está voando alto no céu.\n";
    }

    void tipo() const override final
    {
        std::cout << "Este é um avião comercial.\n";
    }
};

// Veiculo *criarAviao() { return new Aviao(); }

// Utilize Smart Pointers
std::unique_ptr<Veiculo> criarAviao()
{
    return std::make_unique<Aviao>();
}

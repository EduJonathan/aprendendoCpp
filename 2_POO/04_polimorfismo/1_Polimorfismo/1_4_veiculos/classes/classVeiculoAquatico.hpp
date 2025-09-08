#ifndef CLASS_VEICULO_AQUATICO_HPP
#define CLASS_VEICULO_AQUATICO_HPP

#include "classVeiculo.hpp"

class Aquatico : public Veiculo
{
public:
    void mover() const override
    {
        std::cout << "Veículo aquático navegando nas águas.\n";
    }
};

#endif

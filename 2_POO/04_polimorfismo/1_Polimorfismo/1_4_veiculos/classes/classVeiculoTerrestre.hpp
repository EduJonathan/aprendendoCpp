#ifndef CLASS_VEICULO_TERRESTRE_HPP
#define CLASS_VEICULO_TERRESTRE_HPP

#include "classVeiculo.hpp"

class Terrestre : public Veiculo
{
public:
    void mover() const override
    {
        std::cout << "Veículo terrestre se movendo na estrada.\n";
    }
};

#endif

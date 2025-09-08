#ifndef CLASS_VEICULO_AREO_HPP
#define CLASS_VEICULO_AREO_HPP

#include "classVeiculo.hpp"

class Aereo : public Veiculo
{
public:
    void mover() const override
    {
        std::cout << "Veículo aéreo voando pelos céus.\n";
    }
};

#endif

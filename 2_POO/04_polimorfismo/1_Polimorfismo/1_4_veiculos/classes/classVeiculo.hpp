#ifndef CLASS_VEICULO_HPP
#define CLASS_VEICULO_HPP

#include <iostream>

class Veiculo
{
public:
    virtual void mover() const = 0;
    virtual void tipo() const = 0;
    virtual ~Veiculo() = default;
};

#endif

#ifndef CLASS_DECIMAL_HPP
#define CLASS_DECIMAL_HPP

#include "class_value.hpp"

class Decimal : public Valor
{
private:
    int valor;

public:
    Decimal(int v);

    std::string paraBinario() const override;
    void exibirValor() const override;
};

#endif // DECIMAL_HPP

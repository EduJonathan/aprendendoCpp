#ifndef CLASS_HEXADECIMAL_HPP
#define CLASS_HEXADECIMAL_HPP

#include "class_value.hpp"

class Hexadecimal : public Valor
{
private:
    int valor;

public:
    explicit Hexadecimal(int v);

    std::string paraBinario() const override;
    void exibirValor() const override;
};

#endif // DECIMAL_HPP

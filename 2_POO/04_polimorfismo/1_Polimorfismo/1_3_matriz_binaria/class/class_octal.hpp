#ifndef CLASS_OCTAL_HPP
#define CLASS_OCTAL_HPP

#include "class_value.hpp"

class Octal : public Valor
{
private:
    int valor;

public:
    Octal(int v);

    std::string paraBinario() const override;
    void exibirValor() const override;
};

#endif // DECIMAL_HPP

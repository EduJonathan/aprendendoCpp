#ifndef CLASS_VALOR_HPP
#define CLASS_VALOR_HPP

#include <string>

class Valor
{
public:
    virtual std::string paraBinario() const = 0;
    virtual void exibirValor() const = 0;
    virtual ~Valor() = default;
};

#endif // VALOR_HPP

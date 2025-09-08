#ifndef CLASS_VALOR_HPP
#define CLASS_VALOR_HPP

#include <string>

class Valor
{
public:
    virtual ~Valor() {}
    virtual std::string paraBinario() const = 0; // Função virtual pura
    virtual void exibirValor() const = 0;        // Função virtual pura
};

#endif // VALOR_HPP

#ifndef MINHACLASSE_HPP
#define MINHACLASSE_HPP

template <typename T>
class MinhaClasse
{
public:
    MinhaClasse();
    void adicionar(const T &valor);
    T obterValor() const;

private:
    T valor;
};
;

// Sempre inclua o .tpp no final do .hpp após as declarações, para que as implementações estejam disponíveis ao compilador.
#include "templates.tpp"

#endif // MINHACLASSE_HPP

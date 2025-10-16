#ifndef MINHACLASSE_TPP
#define MINHACLASSE_TPP

#include "declaracoes.hpp"

template <typename T>
MinhaClasse<T>::MinhaClasse() : valor(T()) {}

template <typename T>
void MinhaClasse<T>::adicionar(const T &valor)
{
    this->valor = valor;
}

template <typename T>
T MinhaClasse<T>::obterValor() const
{
    return valor;
}

#endif // MINHACLASSE_TPP

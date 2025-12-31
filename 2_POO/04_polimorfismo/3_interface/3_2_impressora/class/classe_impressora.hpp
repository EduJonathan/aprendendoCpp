// Impressora.hpp
#ifndef IMPRESSORA_HPP
#define IMPRESSORA_HPP

#include <queue>
#include <memory>
#include "../interface/interface_imprimir.hpp"

class Impressora
{
private:
    int papelDisponivel;
    std::queue<std::unique_ptr<IImprimivel>> fila;

public:
    explicit Impressora(int papelInicial);

    void adicionarTrabalho(std::unique_ptr<IImprimivel> trabalho);
    bool imprimirProximo();
    void adicionarPapel(int folhas);
    bool vazia() const;
};

#endif

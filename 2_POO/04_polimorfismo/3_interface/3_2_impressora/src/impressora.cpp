// Impressora.cpp
#include "../class/classe_impressora.hpp"
#include <iostream>
#include <utility>

Impressora::Impressora(int papelInicial) : papelDisponivel(papelInicial) {}

void Impressora::adicionarTrabalho(std::unique_ptr<IImprimivel> trabalho)
{
    fila.push(std::move(trabalho));
}

bool Impressora::imprimirProximo()
{
    if (fila.empty())
        return false;

    auto &trabalho = fila.front();
    int paginas = trabalho->paginas();

    if (paginas > papelDisponivel)
    {
        std::cout << "Erro: papel insuficiente!\n";
        std::cout << "Necessario: " << paginas
                  << " | Disponivel: " << papelDisponivel << "\n\n";
        return false;
    }

    std::cout << "Imprimindo: " << trabalho->descricao() << "\n";
    std::cout << "Paginas: " << paginas << "\n";

    papelDisponivel -= paginas;
    fila.pop();

    std::cout << "Papel restante: " << papelDisponivel << "\n\n";
    return true;
}

void Impressora::adicionarPapel(int folhas)
{
    papelDisponivel += folhas;
    std::cout << "Papel adicionado: " << folhas
              << " | Total: " << papelDisponivel << "\n\n";
}

bool Impressora::vazia() const
{
    return fila.empty();
}

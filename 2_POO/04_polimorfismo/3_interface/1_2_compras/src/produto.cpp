#include "../classes/classProduto.hpp"

#include <iostream>

GPU::GPU(std::string modelo, double preco) : modelo(modelo), preco(preco) {}
CPU::CPU(std::string modelo, double preco) : modelo(modelo), preco(preco) {}
RAM::RAM(std::string modelo, double preco) : modelo(modelo), preco(preco) {}
Gabinete::Gabinete(std::string modelo, double preco) : modelo(modelo), preco(preco) {}

void GPU::exibirDetalhes() const
{
    std::cout << "GPU: " << modelo << " - R$" << preco << '\n';
}

double GPU::getPreco() const
{
    return preco;
}

void CPU::exibirDetalhes() const
{
    std::cout << "CPU: " << modelo << " - R$" << preco << '\n';
}

double CPU::getPreco() const
{
    return preco;
}

void RAM::exibirDetalhes() const
{
    std::cout << "RAM: " << modelo << " - R$" << preco << '\n';
}

double RAM::getPreco() const
{
    return preco;
}

void Gabinete::exibirDetalhes() const
{
    std::cout << "Gabinete: " << modelo << " - R$" << preco << '\n';
}

double Gabinete::getPreco() const
{
    return preco;
}

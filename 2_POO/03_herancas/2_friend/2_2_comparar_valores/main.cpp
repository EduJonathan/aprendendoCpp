#include <iostream>
#include <memory>
#include "Competidor.hpp"
#include "classProduto.hpp"

Produto::Produto(int valor)
{
    this->valorProduto = valor;
}

Competidor::Competidor(int valor)
{
    this->valorCompetidor = valor;
}

bool compararValor(Produto p, Competidor c)
{
    // Usando o operador ternário para decidir o que imprimir
    return (p.valorProduto > c.valorCompetidor) ? (std::cout << "TRUE\n", true) : (std::cout << "FALSE\n", false);
}

int main(int argc, char **argv)
{
    std::cout << "Comparando Primeiros Valores: ";

    Produto produto(4);       // Cria um objeto Produto com valor 4
    Competidor competidor(5); // Cria um objeto Competidor com valor 5

    // Chama a função compararValor que compara os objetos Produto e Competidor
    compararValor(produto, competidor);

    std::cout << "-----------------------------\n";

    std::cout << "Comparando Segundos Valores: ";

    std::shared_ptr<Produto> produto1 = std::make_shared<Produto>(6);          // Cria um objeto Produto com valor 6
    std::shared_ptr<Competidor> competidor1 = std::make_shared<Competidor>(5); // Cria um objeto Competidor com valor 5

    // Chama a função compararValor que compara os objetos Produto e Competidor
    compararValor(*produto1, *competidor1);
    return 0;
}

#include "calculator.hpp"
#include <iostream>
#include <new>

Calculator::Calculator(int valorInicial) : valor(valorInicial) {}

Calculator &Calculator::valorDuplicado()
{
    auto operacao = [this]()
    {
        valor *= 2;
        std::cout << "Valor duplicado: " << valor << '\n';
    };
    operacao();   // Chama a lambda para realizar a operação
    return *this; // Retorna a referência do próprio objeto
}

Calculator &Calculator::add(int numero)
{
    auto operacao = [this](int x)
    {
        valor += x;
        std::cout << "Adicionando: " << valor << '\n';
    };
    operacao(numero); // Chama a lambda para realizar a operação
    return *this;     // Retorna a referência do próprio objeto
}

int Calculator::getValor() const
{
    return valor;
}

int main(int argc, char **argv)
{
    Calculator *calc = new Calculator(10);

    calc->valorDuplicado().add(5).valorDuplicado().add(10);
    std::cout << "Valor final: " << calc->getValor() << '\n';

    delete calc; // Libera a memória alocada para o objeto Calculator

    return 0;
}

#include <iostream>
#include <new>
#include <memory>

class Funcao
{
public:
    int operator()(int x)
    {
        return x * x;
    }
};

// Functor com parâmetros
class Adder
{
private:
    int valor;

public:
    Adder(int v) : valor(v) {}

    // Sobrecarga do operator() para somar um valor ao valor interno
    int operator()(int x) const
    {
        return valor + x;
    }
};

template <typename T>
class Multiplicador
{
private:
    static int fator;

public:
    Multiplicador(int f) : fator(f) {}

    // Sobrecarga do operator() para multiplicar o parâmetro pelo fator
    int operator()(int x) const
    {
        return x * fator;
    }
};

int main(int argc, char **argv)
{
    Funcao *function = new Funcao();
    std::cout << "Resultado: " << (*function)(5) << '\n';

    Adder soma(10);               // Cria o functor com valor inicial 10
    std::cout << soma(5) << '\n'; // Chama o operador, soma 10 + 5, imprime 15

    using MultiplicadorInt = Multiplicador<int>;
    std::unique_ptr<MultiplicadorInt> mult = std::make_unique<MultiplicadorInt>(3); // Cria o functor com fator 3

    std::cout << (*mult)(5) << '\n'; // Chama o operador, imprime 15

    return 0;
}

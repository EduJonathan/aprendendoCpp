#include <iostream>

template <int Base, int Expoente>
struct Potenciacao
{
    static const int valor = Base * Potenciacao<Base, Expoente - 1>::valor;
};

// Especialização para o caso base (qualquer número elevado a 0 é 1)
template <int Base>
struct Potenciacao<Base, 0>
{
    static const int valor = 1;
};

int main(int argc, char **argv)
{
    // Calculando 2 elevado a 10 em tempo de compilação
    constexpr int base = 2;
    constexpr int expoente = 10;
    constexpr int potencia = Potenciacao<base, expoente>::valor;
    std::cout << "2^10: " << potencia << '\n';

    return 0;
}

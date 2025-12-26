#include <iostream>

// Estrutura recursiva para calcular o fatorial em tempo de compilação
template <int N>
struct Fatorial
{
    static const int valor = N * Fatorial<N - 1>::valor;
};

// Especialização para o caso base (0!), O fatorial de 0 é definido como 1
template <>
struct Fatorial<0>
{
    static const int valor = 1;
};

int main(int argc, char **argv)
{
    // Calculando o fatorial de 5 em tempo de compilação
    constexpr int fatorial = Fatorial<5>::valor;
    std::cout << "Fatorial de 5: " << fatorial << '\n';
    return 0;
}

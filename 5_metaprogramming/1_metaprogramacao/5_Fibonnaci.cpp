#include <iostream>

// Template recursivo para calcular Fibonacci em tempo de compilação
template <int N>
struct Fibonacci
{
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

// Casos base (specializações)
template <>
struct Fibonacci<0>
{
    static constexpr int value = 0;
};

template <>
struct Fibonacci<1>
{
    static constexpr int value = 1;
};

// Função que simula renderização com o valor de Fibonacci
void render_fractal()
{
    constexpr int fib30 = Fibonacci<30>::value; // Computado em tempo de compilação
    std::cout << "Fibonacci(30) = " << fib30 << " (calculado em tempo de compilação)\n";

    // Poderia ser usado, por exemplo, como profundidade ou parâmetro de fractal
    // render_fractal_with_depth(fib30);
}

int main(int argc, char **argv)
{
    render_fractal();

    // Apenas para ilustrar outros valores possíveis
    std::cout << "Fibonacci(0) = " << Fibonacci<0>::value << '\n';
    std::cout << "Fibonacci(10) = " << Fibonacci<10>::value << '\n';
    std::cout << "Fibonacci(20) = " << Fibonacci<20>::value << '\n';

    return 0;
}

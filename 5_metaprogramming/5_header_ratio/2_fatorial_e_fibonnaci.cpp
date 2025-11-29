#include <iostream>
#include <ratio>

constexpr int fatorial(int n)
{
    return (n == 0) ? 1 : n * fatorial(n - 1);
}

constexpr int fibonnaci(int n)
{
    return (n <= 1) ? n : fibonnaci(n - 1) + fibonnaci(n - 2);
}

using Factorial10 = std::ratio<fatorial(10), 1>; // 10! = 3.628.800
using Fibonnaci5 = std::ratio<fibonnaci(5), 1>;  // Fibonacci(5) = 5

int main(int argc, char **argv)
{
    std::cout << "Fatorial de 10: " << Factorial10::num << '\n'; // 3628800
    std::cout << "Fibonacci de 5: " << Fibonnaci5::num << '\n';  // 5
    return 0;
}

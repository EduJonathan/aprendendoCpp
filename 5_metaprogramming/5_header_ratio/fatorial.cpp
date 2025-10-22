#include <ratio>
#include <iostream>

constexpr int fatorial(int n)
{
    return (n == 0) ? 1 : n * fatorial(n - 1);
}

using Factorial10 = std::ratio<fatorial(10), 1>; // 10! = 3.628.800

int main(int argc, char **argv)
{
    std::cout << "Fatorial de 10: " << Factorial10::num << '\n'; // 3628800
    return 0;
}

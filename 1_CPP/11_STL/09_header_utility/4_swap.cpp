#include <iostream>
#include <utility>

// std::swap(): Troca dois valores.

int main(int argc, char **argv)
{
    int a = 10, b = 20;
    std::swap(a, b);
    std::cout << "a: " << a << ", b: " << b << '\n';

    std::swap(b, a);
    std::cout << "a: " << a << ", b: " << b << '\n';

    char x = 'n', y = 'a';

    // Lambda que usa std::swap para trocar dois valores
    auto swap_lambda = [](char x, char y)
    {
        std::swap(x, y);
    };

    std::cout << "Antes da troca: x = " << x << ", y = " << y << '\n';

    swap_lambda(x, y); // Usando x lambda para trocar os valores

    std::cout << "Depois da troca: x = " << x << ", y = " << y << '\n';
    return 0;
}

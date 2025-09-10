#include <iostream>
#include <utility>

// std::swap(): Troca dois valores.

int main(int argc, char **argv)
{
    int a = 10, b = 20;
    std::swap(a, b);
    std::cout << "a: " << a << ", b: " << b << '\n';

    std::swap(b, a);
    std::cout << "b: " << a << ", a: " << b << '\n';
    return 0;
}

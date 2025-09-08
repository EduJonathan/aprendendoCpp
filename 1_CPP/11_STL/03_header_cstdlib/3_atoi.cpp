#include <iostream>
#include <cstdlib>

// std::atoi(): Função de conversão para inteiros.

int main(int argc, char **argv)
{
    const char *str_int = "42";
    const char *str_long = "1234567890";
    const char *str_long_long = "1234567890123456789";

    // Usando atoi para converter para int
    int i = std::atoi(str_int);
    std::cout << "std::atoi: " << i << '\n';

    // Usando atol para converter para long
    long l = std::atol(str_long);
    std::cout << "std::atol: " << l << '\n';

    // Usando atoll para converter para long long
    long long ll = std::atoll(str_long_long);
    std::cout << "std::atoll: " << ll << '\n';

    return 0;
}

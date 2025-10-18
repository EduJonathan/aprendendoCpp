#include <iostream>
#include <cstdlib>

// std::strtol() Função de conversão para inteiros com base.

int main(int argc, char **argv)
{
    const char *str_int = "-12345";
    const char *str_long = "9876543210";
    const char *str_long_long = "-9876543210987654321";

    // Usando strtol para converter para long
    long l = std::strtol(str_long, nullptr, 10); // Base 10
    std::cout << "strtol: " << l << '\n';

    // Usando strtoll para converter para long long
    long long ll = std::strtoll(str_long_long, nullptr, 10); // Base 10
    std::cout << "strtoll: " << ll << '\n';

    const char *str_ulong = "1234567890";
    const char *str_ulong_long = "1234567890123456789";

    // Usando strtoul para converter para unsigned long
    unsigned long ul = std::strtoul(str_ulong, nullptr, 10); // Base 10
    std::cout << "strtoul: " << ul << '\n';

    // Usando strtoull para converter para unsigned long long
    unsigned long long ull = std::strtoull(str_ulong_long, nullptr, 10); // Base 10
    std::cout << "strtoull: " << ull << '\n';

    return 0;
}

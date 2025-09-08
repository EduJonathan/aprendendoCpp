#include <iostream>
#include <iomanip>
#include <type_traits>

template <typename T>
constexpr auto getValue(T t)
{
    if constexpr (std::is_same_v<T, int>)
    {
        return t + 1;
    }
    else
    {
        return t * 2.0;
    }
}

int main(int argc, char **argv)
{
    constexpr int x = getValue(5);      // Calcula 5 + 1 = 6 em tempo de compilação
    constexpr double y = getValue(5.0); // Calcula 5.0 * 2.0 = 10.0 em tempo de compilação

    std::cout << "Valor de x: " << x << ", Valor de y: " << std::setprecision(2) << std::fixed << y << '\n'; // Imprime: 6 10.00
    return 0;
}

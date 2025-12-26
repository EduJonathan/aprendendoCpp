#include <iostream>
#include <iomanip>
#include <type_traits>

template <typename T>
struct Calculator
{
    static T add(T a, T b)
    {
        if constexpr (std::is_integral_v<T>)
        {
            return a + b;
        }
        else
        {
            return a + b + 0.5; // Exemplo de comportamento diferente para tipos flutuantes
        }
    }
};

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
    std::cout << Calculator<int>::add(2, 3) << '\n';        // Imprime: 5
    std::cout << Calculator<double>::add(2.0, 3.0) << '\n'; // Imprime: 5.5

    constexpr int x = getValue(5);      // Calcula 5 + 1 = 6 em tempo de compilação
    constexpr double y = getValue(5.0); // Calcula 5.0 * 2.0 = 10.0 em tempo de compilação

    std::cout << "Valor de x: " << x << ", Valor de y: " << std::setprecision(2) << std::fixed << y << '\n'; // Imprime: 6 10.00

    return 0;
}

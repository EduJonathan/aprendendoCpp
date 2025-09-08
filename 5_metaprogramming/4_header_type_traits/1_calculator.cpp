#include <iostream>
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

int main(int argc, char **argv)
{
    std::cout << Calculator<int>::add(2, 3) << '\n';        // Imprime: 5
    std::cout << Calculator<double>::add(2.0, 3.0) << '\n'; // Imprime: 5.5
    return 0;
}

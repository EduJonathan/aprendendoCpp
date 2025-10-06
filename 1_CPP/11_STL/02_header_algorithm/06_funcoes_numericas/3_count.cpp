#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::count(begin, end, value)
 *   → Conta quantas vezes `value` aparece no intervalo (begin, end).
 *
 * - std::count_if(begin, end, pred)
 *   → Conta quantos elementos no intervalo satisfazem a condição `pred`.
 */

/**
 * @brief Verifica se um número é primo.
 *
 * @param num Número inteiro a ser testado.
 * @return true se for primo, false caso contrário.
 */
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(int argc, char **argv)
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Lambda para verificar se é par
    auto isEven = [](int n)
    {
        return n % 2 == 0;
    };

    // Conta os números pares
    int countEven = std::count_if(numbers.begin(), numbers.end(), isEven);
    std::cout << "Quantidade de números pares: " << countEven << '\n';

    std::cout << "=============================" << '\n';

    // Conta os números primos diretamente com std::count_if
    int countPrimes = std::count_if(numbers.begin(), numbers.end(), isPrime);
    std::cout << "Quantidade de números primos: " << countPrimes << '\n';

    return 0;
}

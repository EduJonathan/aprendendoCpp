#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::fill(begin, end, value)
 *   → Preenche todo o intervalo (begin, end) com `value`.
 *
 * - std::fill_n(begin, count, value)
 *   → Preenche os `count` primeiros elementos a partir de `begin` com `value`.
 */

/**
 * @brief Substitui os valores menores que 10 por 7 no vetor.
 *
 * Utiliza `std::for_each` com uma função lambda e `std::fill` para preencher apenas
 * posições que atendem à condição `valor < 10`.
 *
 * @param vec Vetor de inteiros a ser processado.
 */
void preenchaVetor(std::vector<int> &vec)
{
    std::for_each(vec.begin(), vec.end(), [](int &num)
    {
        if (num < 10)
        {
            std::fill(&num, &num + 1, 7); // Preenche apenas o endereço de 'num'
        }
    });
}

int main(int argc, char **argv)
{
    std::vector<int> vec(5);
    std::fill(vec.begin(), vec.end(), 7);

    std::cout << "Vetor preenchido com std::fill: ";
    for (int num : vec)
    {
        std::cout << num << ' ';
    }

    std::cout << "\n---------------------------------" << '\n';

    std::vector<int> vector = {3, 12, 5, 8, 15};

    preenchaVetor(vector); // Substitui os menores que 10 por 7

    std::cout << "Vetor após aplicar preenchaVetor(): ";
    for (int num : vector)
    {
        std::cout << num << ' ';
    }
    return 0;
}

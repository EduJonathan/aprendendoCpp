#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::fill(): Preenche um intervalo completo com um valor específico.
 * - std::fill_n(): Preenche um número definido de elementos com um valor específico..
 */

/**
 * @brief Substitui os valores menores que 10 por 7 no vetor.
 *
 * Utiliza `std::for_each` com uma função lambda e `std::fill` para preencher apenas posições que
 * atendem à condição `valor < 10`.
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

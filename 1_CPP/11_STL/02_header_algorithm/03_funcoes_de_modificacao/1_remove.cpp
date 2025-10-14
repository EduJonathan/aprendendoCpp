#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::remove(begin, end, value)
 *   → Move os elementos ≠ `value` para frente; não altera o tamanho. Use `.erase()` para remover de fato.
 *
 * - std::remove_if(begin, end, pred)
 *   → Igual ao `remove`, mas remove com base em uma condição (`pred`).
 *
 * - std::remove_copy(begin, end, dest, value)
 *   → Copia para `dest` os elementos ≠ `value`. Não altera o original.
 *
 * - std::remove_copy_if(begin, end, dest, pred)
 *   → Copia para `dest` os elementos que **não** satisfazem a condição `pred`.
 */

/**
 * @brief Função que remove caracteres maiúsculos de um vetor de caracteres.
 *
 * A função `removerCaractere()` utiliza `std::remove_if` para remover todos os caracteres
 * maiúsculos (A-Z) de um vetor de caracteres. Após a remoção, a função usa `.erase()` para
 * realmente excluir os elementos indesejados.
 *
 * @param vetorCaractere Vetor de caracteres do qual os caracteres maiúsculos serão removidos.
 */
void removerCaractere(std::vector<char> &vetorCaractere)
{
    // Remove caracteres maiúsculos
    vetorCaractere.erase(std::remove_if(vetorCaractere.begin(), vetorCaractere.end(), [](char c)
    {
        return c >= 'A' && c <= 'Z'; // Condição para remover caracteres maiúsculos

        // Final do vetor para apagar a parte removida
    }), vetorCaractere.end());
}

int main(int argc, char **argv)
{
    // Vetor de inteiros
    std::vector<int> vec = {1, 2, 3, 2, 4, 2, 5};

    // Remove todos os elementos iguais a 2
    auto new_end = std::remove(vec.begin(), vec.end(), 2);
    vec.erase(new_end, vec.end()); // Remove os elementos do final do vetor

    for (int num : vec)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    std::cout << "-------------------------------------" << '\n';

    // Vetor de inteiros
    std::vector<int> numeros = {1, 2, 3, 4, 3, 5};

    // Remove todos os elementos iguais a 3
    numeros.erase(std::remove(numeros.begin(), numeros.end(), 3), numeros.end());

    for (int num : numeros)
    {
        std::cout << num << ' ';
    }

    std::cout << "\n-------------------------------------" << '\n';

    // Vetor de caracteres
    std::vector<char> vetorCaractere = {'a', 'B', 'c', 'D', 'e', 'F', 'g'};

    std::cout << "Antes: ";
    for (char c : vetorCaractere)
    {
        std::cout << c << ' ';
    }

    // Remover caracteres maiúsculos
    removerCaractere(vetorCaractere);

    std::cout << "\nDepois: ";
    for (char c : vetorCaractere)
    {
        std::cout << c << ' ';
    }
    return 0;
}

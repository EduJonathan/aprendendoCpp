#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::remove(): Remove elementos de um intervalo movendo-os para o final, sem alterar 
 * o tamanho do contêiner. Para excluir fisicamente os elementos, é necessário usar `.erase()`.
 * 
 * - std::remove_if(): Semelhante ao `std::remove()`, mas permite especificar uma condiçã
 * (usando um predicado) para determinar quais elementos devem ser removidos.
 * 
 * - std::remove_copy(): Cria uma cópia de elementos que não correspondem a um valor
 * específico, deixando os indesejados para trás, sem alterar o contêiner original.
 * 
 * - std::remove_copy_if(): Semelhante ao `std::remove_copy()`, mas permite usar 
 * uma condição personalizada para selecionar quais elementos copiar.
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
    }), vetorCaractere.end() // Final do vetor para apagar a parte removida
    );
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

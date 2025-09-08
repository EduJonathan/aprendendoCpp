#include <iostream>
#include <set>

/**
 * O std::set<T> É um contêiner que armazena elementos únicos em ordem crescente
 * (ou conforme critério definido). Não permite elementos duplicados e não associa valores
 * a chaves, ou seja, armazena apenas o valor do elemento. Além disso, as operações de
 * busca, inserção e remoção possuem uma complexidade logarítmica, O(log n).
 */

/**
 * @brief Realiza a união de dois conjuntos de inteiros.
 *
 * A união de dois conjuntos inclui todos os elementos de ambos, sem duplicação.
 * Caso um número apareça em ambos os conjuntos, ele será incluído apenas uma vez no
 * conjunto resultante.
 *
 * @param set1 O primeiro conjunto de inteiros.
 * @param set2 O segundo conjunto de inteiros.
 * @return std::set<int> O conjunto resultante da união de `set1` e `set2`.
 */
std::set<int> uniao(const std::set<int> &set1, const std::set<int> &set2)
{
    std::set<int> resultado = set1;             // Inicia com os elementos de set1
    resultado.insert(set2.begin(), set2.end()); // Adiciona os elementos de set2
    return resultado;                           // Retorna o conjunto unido
}

/**
 * @brief Verifica se um conjunto é subconjunto de outro.
 *
 * Um conjunto `set1` é subconjunto de `set2` se todos os elementos de `set1`
 * estiverem presentes em `set2`. Esta função realiza essa verificação para
 * determinar se `set1` é um subconjunto de `set2`.
 *
 * @param set1 O conjunto de inteiros a ser verificado como subconjunto.
 * @param set2 O conjunto de inteiros onde se verifica se `set1` é subconjunto.
 * @return true Se `set1` for subconjunto de `set2`.
 * @return false Se `set1` não for subconjunto de `set2`.
 */
bool isSubconjunto(const std::set<int> &set1, const std::set<int> &set2)
{
    // Verifica se cada elemento de set1 está presente em set2
    for (int num : set1)
    {
        if (set2.find(num) == set2.end()) // Se não encontrar o número em set2
        {
            return false; // Não é subconjunto
        }
    }

    return true; // Todos os elementos de set1 estão em set2
}

int main(int argc, char **argv)
{
    // Exemplo 1: União de dois conjuntos
    std::set<int> set1 = {1, 2, 3};
    std::set<int> set2 = {3, 4, 5};

    std::set<int> resultado = uniao(set1, set2);

    // Exibe o resultado da união
    std::cout << "União de set1 e set2: ";
    for (int num : resultado)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    std::cout << "----------------------------------------" << '\n';

    // Exemplo 2: Verificação de subconjunto
    std::set<int> Set1 = {1, 2, 3};
    std::set<int> Set2 = {1, 2, 3, 4, 5};

    // Verifica se Set1 é subconjunto de Set2
    std::cout << (isSubconjunto(Set1, Set2) ? "Set1 é subconjunto de Set2" : "Set1 não é subconjunto de Set2") << '\n';

    // Verifica se set1 é subconjunto de set2
    std::cout << (isSubconjunto(set1, set2) ? "set1 é subconjunto de set2" : "set1 não é subconjunto de set2") << '\n';

    return 0;
}

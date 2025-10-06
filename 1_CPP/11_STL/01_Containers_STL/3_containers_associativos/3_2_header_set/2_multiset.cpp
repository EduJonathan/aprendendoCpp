#include <iostream>
#include <vector>
#include <map>
#include <set>

/**
 * std::multiset<T> é similar ao std::set, mas permite valores duplicados.
 * Mantém os elementos ordenados e oferece operações eficientes (O(log n)).
 * Ideal para armazenar múltiplas ocorrências mantendo a ordem.
 */

/**
 * @brief Remove todas as ocorrências de um valor específico de um multiset.
 *
 * A função utiliza o método `erase` para remover todas as instâncias de um valor
 * presente no `std::multiset<int>`.
 *
 * @param s O `std::multiset<int>` do qual o valor será removido.
 * @param valor O valor a ser removido do multiset.
 */
void removerElemento(std::multiset<int> &s, int valor)
{
    s.erase(valor); // Remove todas as ocorrências do valor no multiset
}

/**
 * @brief Agrupa os números por sua frequência de ocorrência.
 *
 * A função recebe um vetor de números e agrupa esses números em um `std::map`,
 * onde a chave é a frequência de ocorrência e o valor é um `std::multiset<int>`,
 * que armazena os números com essa frequência. A ordem dos números é mantida
 * dentro de cada grupo devido ao uso do `std::multiset`.
 *
 * @param numeros O vetor de números a ser analisado e agrupado por frequência.
 * @return Um `std::map<int, std::multiset<int>>` onde a chave é a frequência de
 *         ocorrência e o valor é o conjunto dos números que aparecem essa quantidade de vezes.
 */
std::map<int, std::multiset<int>> agruparPorFrequencia(const std::vector<int> &numeros)
{
    std::map<int, std::multiset<int>> agrupado;

    // Contar as frequências dos números e armazená-los em um multiset
    std::multiset<int> frequencias;
    for (int num : numeros)
    {
        frequencias.insert(num);
    }

    // Agrupar os números pela sua frequência de ocorrência
    for (int num : frequencias)
    {
        // Insere os números no mapa com base na frequência
        agrupado[frequencias.count(num)].insert(num);
    }
    return agrupado;
}

int main(int argc, char **argv)
{
    // Criando um multiset com alguns valores
    std::multiset<int> elementos = {1, 2, 2, 3, 4, 4, 5};

    // Exibindo antes da remoção
    std::cout << "Antes de remover 2: ";
    for (int num : elementos)
    {
        std::cout << num << ' '; // Exibe todos os elementos do multiset
    }
    std::cout << '\n';

    // Removendo todas as ocorrências do número 2
    removerElemento(elementos, 2);

    // Exibindo depois da remoção
    std::cout << "Depois de remover 2: ";
    for (int num : elementos)
    {
        std::cout << num << ' '; // Exibe os elementos restantes após remoção
    }
    std::cout << '\n';

    std::cout << "---------------------------------------" << '\n';

    // Vetor de números para agrupar por frequência
    std::vector<int> numeros = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};

    // Agrupando os números por frequência
    std::map<int, std::multiset<int>> agrupado = agruparPorFrequencia(numeros);

    // Exibindo os números agrupados por sua frequência de ocorrência
    for (const auto &grupo : agrupado)
    {
        std::cout << "Frequência " << grupo.first << ": ";
        for (int num : grupo.second)
        {
            std::cout << num << ' '; // Exibe todos os números que têm a mesma frequência
        }
        std::cout << '\n';
    }
    return 0;
}

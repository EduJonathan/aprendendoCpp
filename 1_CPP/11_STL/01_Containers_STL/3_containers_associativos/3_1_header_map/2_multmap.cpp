#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <map>

/**
 * std::multimap<K, V> é semelhante ao std::map, mas permite múltiplos valores
 * para a mesma chave, aceitando chaves duplicadas.
 * 
 * Mantém as chaves ordenadas e oferece operações de inserção, busca e remoção
 * com complexidade O(log n), graças à implementação como árvore balanceada.
 *
 * Ideal para armazenar várias ocorrências associadas a uma mesma chave.
 */

/**
 * @brief Exibe elementos de um `std::multimap` dentro de um intervalo de chaves.
 *
 * Essa função percorre um `std::multimap` e imprime todas as chaves e seus valores,
 * desde que as chaves estejam dentro do intervalo [min, max], onde o valor mínimo (min)
 * é inclusivo e o valor máximo (max) é exclusivo.
 *
 * @param m O `std::multimap` a ser analisado, contendo chaves e valores a serem exibidos.
 * @param min O valor mínimo da chave (inclusivo).
 * @param max O valor máximo da chave (exclusivo).
 */
void elementosNoIntervalo(const std::multimap<int, std::string> &m, int min, int max)
{
    // Encontra o primeiro elemento com chave >= min
    auto itLow = m.lower_bound(min);

    // Encontra o primeiro elemento com chave > max
    auto itHigh = m.upper_bound(max);

    std::cout << "Elementos no intervalo [" << min << ", " << max << "]:" << '\n';

    // Itera sobre o intervalo entre itLow e itHigh, imprimindo os elementos
    for (auto it = itLow; it != itHigh; ++it)
    {
        std::cout << "Chave: " << it->first << " - Valor: " << it->second << '\n';
    }
}

/**
 * @brief Agrupa um conjunto de pessoas por idade em um `std::multimap`.
 *
 * Dado um vetor de pares contendo nomes e idades de pessoas, essa função cria
 * um `std::multimap` onde as idades são as chaves e os nomes são os valores.
 * Assim, as pessoas ficam agrupadas por idade.
 *
 * @param pessoas Um vetor de pares onde cada par contém o nome e a idade de uma pessoa.
 * @return `std::multimap<int, std::string>` Um `multimap` com idades como chaves e nomes como valores.
 */
std::multimap<int, std::string> agruparPorIdade(const std::vector<std::pair<std::string, int>> &pessoas)
{
    std::multimap<int, std::string> grupoPorIdade;

    // Agrupa as pessoas por idade no multimap
    for (const auto &pessoa : pessoas)
    {
        grupoPorIdade.insert({pessoa.second, pessoa.first});
    }

    // O multimap agora contém as idades como chaves e os nomes como valores
    return grupoPorIdade;
}

int main(int argc, char **argv)
{
    // Exemplo de multimap com chaves e valores
    std::multimap<int, std::string> m = {
        {1, "Um"},
        {2, "Dois"},
        {3, "Três"},
        {4, "Quatro"},
        {5, "Cinco"}};

    // Exibe os elementos dentro do intervalo [2, 4]
    elementosNoIntervalo(m, 2, 4);

    std::cout << "---------------------------------" << '\n';

    // Vetor de pessoas com nome e idade
    std::vector<std::pair<std::string, int>> pessoas = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 30},
        {"David", 25},
        {"Eve", 40}};

    // Agrupa as pessoas por idade
    std::multimap<int, std::string> resultado = agruparPorIdade(pessoas);

    // Exibe as pessoas agrupadas por idade
    std::cout << "Pessoas agrupadas por idade:" << '\n';
    for (const auto &par : resultado)
    {
        std::cout << "Idade: " << par.first << " - Nome: " << par.second << '\n';
    }

    return 0;
}

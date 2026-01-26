#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>

/**
 * std::unordered_multimap<K, V> é um container que permite múltiplos valores para
 * a mesma chave, armazenando pares chave-valor em tabela hash sem ordem garantida.
 * 
 * Permite buscas e inserções rápidas, mesmo com chaves duplicadas.
 */

/**
 * @brief Agrupa palavras por seu comprimento.
 *
 * Esta função recebe um vetor de palavras e retorna um `std::unordered_multimap`
 * onde as chaves são os comprimentos das palavras e os valores são as palavras
 * que têm esse comprimento.
 *
 * @param palavras Um vetor de palavras a ser agrupado.
 * @return Um `std::unordered_multimap<std::size_t, std::string>`
 * que mapeia o comprimento das palavras para as próprias palavras.
 */
std::unordered_multimap<std::size_t, std::string> agruparPorComprimento(const std::vector<std::string> &palavras)
{
    std::unordered_multimap<std::size_t, std::string> multimap;

    // Insere as palavras no multimap, agrupando-as por comprimento
    for (const std::string &palavra : palavras)
    {
        multimap.insert({palavra.length(), palavra});
    }
    return multimap;
}

int main(int argc, char **argv)
{
    // Exemplo de uso de unordered_multimap para armazenar chaves duplicadas
    std::vector<std::pair<std::string, int>> dados = {
        {"a", 1},
        {"b", 2},
        {"a", 3},
        {"c", 4},
        {"b", 5},
        {"a", 6}};

    std::unordered_multimap<std::string, int> multimap(dados.begin(), dados.end());

    // Exibe os pares chave-valor no multimap
    std::cout << "Exibindo todos os pares chave-valor do multimap:" << '\n';
    for (const auto &par : multimap)
    {
        std::cout << "Chave: " << par.first << ", Valor: " << par.second << '\n';
    }

    // Busca todos os valores associados a uma chave específica
    std::string chave = "a";
    auto range = multimap.equal_range(chave);

    std::cout << "\nValores associados à chave '" << chave << "': ";
    for (auto it = range.first; it != range.second; ++it)
    {
        std::cout << it->second << ' ';
    }
    std::cout << "\n----------------------------------------\n";

    // Exemplo de vetor de palavras
    std::vector<std::string> palavras = {"casa", "carro", "sol", "lua", "mesa", "cadeira"};

    // Chama a função e obtém o multimap agrupado por comprimento
    std::unordered_multimap<std::size_t, std::string> agrupado = agruparPorComprimento(palavras);

    // Exibe as palavras agrupadas por comprimento
    std::cout << "Exibindo palavras agrupadas por comprimento:" << '\n';
    for (const auto &par : agrupado)
    {
        std::cout << "Comprimento: " << par.first << ", Palavra: " << par.second << '\n';
    }
    return 0;
}

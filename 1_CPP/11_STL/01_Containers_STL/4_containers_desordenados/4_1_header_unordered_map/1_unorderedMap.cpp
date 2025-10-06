#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <unordered_map>

/**
 * std::unordered_map<K, V> é um container que associa chaves únicas a valores
 * sem manter ordem, usando tabela hash para operações médias em O(1).
 *
 * Ideal para acesso rápido quando a ordem dos elementos não importa.
 */

/**
 * @brief Função que calcula a frequência de cada número em um vetor.
 *
 * A função utiliza um `std::unordered_map` para contar a quantidade de vezes que cada
 * número aparece no vetor. Ela retorna um mapa contendo o número como chave e sua
 * frequência como valor.
 *
 * @param numeros Vetor de inteiros a ser analisado.
 * @return std::unordered_map<int, int> Mapa com as frequências de cada número.
 */
std::unordered_map<int, int> frequenciaDeNumeros(const std::vector<int> &numeros)
{
    // Cria um mapa para armazenar a frequência de cada número
    std::unordered_map<int, int> frequencia;

    // Conta a frequência de cada número no vetor
    for (int num : numeros)
    {
        frequencia[num]++;
    }

    // Variáveis para armazenar o número com maior frequência
    int numeroMaisFrequente = 0;
    int maiorFrequencia = 0;

    // Encontra o número com maior frequência
    for (const auto &pair : frequencia)
    {
        if (pair.second > maiorFrequencia)
        {
            maiorFrequencia = pair.second;
            numeroMaisFrequente = pair.first;
        }
    }

    // Imprime o número com maior frequência
    std::cout << "O número com mais frequências é " << numeroMaisFrequente
              << " com uma frequência de " << maiorFrequencia << " vezes." << '\n';

    // Retorna o mapa de frequências
    return frequencia;
}

/**
 * @brief Função que calcula o caractere com maior frequência em uma string.
 *
 * A função utiliza um `std::unordered_map` para contar a frequência de cada caractere na string.
 * Ela retorna o caractere com maior frequência.
 *
 * @param str String de caracteres a ser analisada.
 */
void frequenciaDeCaracteres(const std::string &str)
{
    // Usamos um unordered_map para armazenar a frequência dos caracteres
    std::unordered_map<char, int> frequencia;

    // Conta a frequência de cada caractere na string
    for (char c : str)
    {
        frequencia[c]++; // Incrementa a frequência de cada caractere
    }

    // Variáveis para armazenar o caractere com maior frequência
    char caractereMaisFrequente = '\0';
    int maiorFrequencia = 0;

    // Encontra o caractere com maior frequência
    for (const auto &pair : frequencia)
    {
        if (pair.second > maiorFrequencia)
        {
            maiorFrequencia = pair.second;       // Atualiza a maior frequência
            caractereMaisFrequente = pair.first; // Atualiza o caractere mais frequente
        }
    }

    // Imprime o caractere com maior frequência
    std::cout << "O caractere com mais frequências é '" << caractereMaisFrequente
              << "' com uma frequência de " << maiorFrequencia << " vezes." << '\n';
}

int main(int argc, char **argv)
{
    /** Mapa desordenado para armazenar os níveis e seus respectivos IDs. */
    std::unordered_map<const char *, uint32_t> niveis = {
        {"Nivel Map", 39},
        {"Nivel Boss", 112},
        {"Muito Dificil", 42},
        {"Final", 458}};

    /** Loop para imprimir os níveis e seus respectivos IDs. */
    std::cout << "Níveis e seus IDs:" << '\n';
    for (const auto &[key, value] : niveis)
    {
        std::cout << key << " -> " << value << '\n';
    }

    std::cout << "\n===================================\n";

    // Vetor de números para contar as frequências
    std::vector<int> numeros = {1, 2, 3, 2, 4, 2, 5, 3, 1};

    // Chama a função que retorna o mapa de frequências dos números
    std::unordered_map<int, int> frequencias = frequenciaDeNumeros(numeros);

    std::cout << "===================================\n";

    // Exibe a frequência de cada número
    std::cout << "Frequências dos números no vetor:" << '\n';
    for (const auto &pair : frequencias)
    {
        std::cout << "Número " << pair.first << " aparece " << pair.second << " vezes." << '\n';
    }

    std::cout << "\n===================================\n";

    // Exemplo de string para análise
    std::string str = "abracadabra";

    // Chama a função para encontrar o caractere mais frequente
    frequenciaDeCaracteres(str);

    return 0;
}

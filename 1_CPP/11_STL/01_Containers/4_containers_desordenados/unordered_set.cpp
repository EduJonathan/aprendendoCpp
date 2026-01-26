#include <iostream>
#include <vector>
#include <unordered_set>

/**
 * std::unordered_set<T> armazena elementos únicos de forma não ordenada,
 * usando tabela hash para operações médias em O(1).
 * Ideal para buscas, inserções e remoções rápidas sem garantir ordem.
 */

/**
 * @brief Remove elementos duplicados de uma lista.
 *
 * Esta função recebe um vetor de inteiros e retorna um novo vetor contendo
 * os elementos originais, mas sem duplicatas. A ordem dos elementos é preservada.
 *
 * @param lista Um vetor de inteiros que pode conter duplicatas.
 * @return Um vetor de inteiros com os elementos únicos da lista de entrada.
 */
std::vector<int> remover_duplicatas(const std::vector<int> &lista)
{
    std::unordered_set<int> conjunto; ///< Conjunto para verificar duplicatas.
    std::vector<int> resultado;       ///< Vetor para armazenar os resultados sem duplicatas.

    // Itera sobre a lista e adiciona elementos ao vetor de resultado se não estiverem no conjunto.
    for (int elemento : lista)
    {
        if (conjunto.find(elemento) == conjunto.end())
        {
            conjunto.insert(elemento);     ///< Adiciona o elemento ao conjunto.
            resultado.push_back(elemento); ///< Adiciona o elemento ao vetor de resultado.
        }
    }

    return resultado; ///< Retorna o vetor de elementos sem duplicatas.
}

/**
 * @brief Verifica se um elemento está presente em um conjunto.
 *
 * Esta função verifica se um dado elemento está presente no conjunto fornecido.
 *
 * @param conjunto O conjunto onde a busca será realizada.
 * @param elemento O elemento que será procurado no conjunto.
 * @return true Se o elemento estiver presente no conjunto.
 * @return false Se o elemento não estiver presente no conjunto.
 */
bool contem(const std::unordered_set<int> &conjunto, int elemento)
{
    return conjunto.find(elemento) != conjunto.end(); // Retorna true se o elemento for encontrado.
}

int main(int argc, char **argv)
{
    // Lista com elementos duplicados.
    std::vector<int> lista = {1, 2, 2, 3, 3, 3, 4};

    // Remove duplicatas da lista.
    std::vector<int> sem_duplicatas = remover_duplicatas(lista);

    // Imprime os elementos da lista sem duplicatas.
    std::cout << "Lista sem duplicatas: ";
    for (int elemento : sem_duplicatas)
    {
        std::cout << elemento << ' ';
    }

    std::cout << "\n--------------------------------------" << '\n';

    int elemento = 3; ///< Elemento a ser verificado.

    // Converte sem_duplicatas para unordered_set para checar presença
    std::unordered_set<int> conjunto_sem_duplicatas(sem_duplicatas.begin(), sem_duplicatas.end());

    // Verifica se o elemento está presente no conjunto.
    if (contem(conjunto_sem_duplicatas, elemento))
    {
        std::cout << "Elemento " << elemento << " está presente." << '\n';
    }
    else
    {
        std::cout << "Elemento " << elemento << " não está presente." << '\n';
    }

    return 0;
}

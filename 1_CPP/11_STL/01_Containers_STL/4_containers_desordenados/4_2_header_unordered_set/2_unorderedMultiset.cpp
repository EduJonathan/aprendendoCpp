#include <iostream>
#include <vector>
#include <unordered_set>

/**
 * std::unordered_multiset<T> É um contêiner que armazena elementos com possíveis duplicatas,
 * de forma não ordenada.
 *
 * O std::unordered_multiset é semelhante ao std::unordered_set, mas permite que elementos
 * duplicados sejam armazenados. Ele usa uma tabela hash para armazenar os elementos,
 * permitindo uma busca e inserção rápidas, com complexidade média constante O(1).
 *
 * Características:
 * - Permite múltiplas ocorrências do mesmo valor, ou seja, aceita duplicatas.
 * - Os elementos são armazenados em uma tabela hash, sem garantias de ordem.
 */

/**
 * @brief Verifica se uma lista contém elementos duplicados.
 *
 * Essa função verifica se há elementos duplicados na lista utilizando um `unordered_set`,
 * que armazena elementos únicos. Se um elemento já estiver presente no conjunto, significa
 * que há uma duplicata na lista.
 *
 * @param lista A lista de inteiros a ser verificada.
 * @return Retorna true se houver duplicatas, caso contrário, false.
 */
bool tem_duplicatas(const std::vector<int> &lista)
{
    std::unordered_set<int> conjunto;

    for (int elemento : lista)
    {
        // Se o elemento já estiver no conjunto, significa que é uma duplicata
        if (conjunto.find(elemento) != conjunto.end())
        {
            return true;
        }

        // Adiciona o elemento ao conjunto
        conjunto.insert(elemento);
    }

    return false;
}

/**
 * @brief Cria um unordered_multiset e preenche com valores inteiros (permitindo duplicatas).
 *
 * Esta função cria um `unordered_multiset` e insere alguns valores inteiros, incluindo
 * duplicatas, para demonstrar como funciona o armazenamento de elementos duplicados.
 *
 * @return Retorna o unordered_multiset preenchido.
 */
std::unordered_multiset<int> criarUnorderedMultiset()
{
    // Criando um unordered_multiset e inserindo elementos, incluindo duplicatas
    std::unordered_multiset<int> umset = {10, 20, 10, 30, 40, 20};
    return umset; // Retorna o unordered_multiset preenchido
}

/**
 * @brief Exibe os elementos de um unordered_multiset.
 *
 * Essa função imprime os elementos de um unordered_multiset. A ordem dos elementos não
 * é garantida, pois eles são armazenados em uma tabela hash.
 *
 * @param umset O unordered_multiset a ser exibido.
 */
void exibirUnorderedMultiset(const std::unordered_multiset<int> &umset)
{
    std::cout << "Elementos no unordered_multiset: ";
    for (const int &elem : umset)
    {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    // Teste da função criarUnorderedMultiset
    std::unordered_multiset<int> resultado = criarUnorderedMultiset();

    // Exibe os elementos do unordered_multiset
    exibirUnorderedMultiset(resultado);

    // Lista com alguns elementos duplicados
    std::vector<int> lista = {1, 2, 3, 4, 5, 2};

    // Verifica se a lista contém duplicatas
    if (tem_duplicatas(lista))
    {
        std::cout << "A lista tem duplicatas." << '\n';
    }
    else
    {
        std::cout << "A lista não tem duplicatas." << '\n';
    }
    return 0;
}

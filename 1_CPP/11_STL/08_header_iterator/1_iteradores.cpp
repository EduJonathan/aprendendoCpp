#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <iterator>

/**
 * Iterators (ou iteradores) são objetos que permitem percorrer os elementos de uma coleção
 * (como std::array, std::vector, std::list, std::set, std::multiset, etc.) de forma sequencial e independente da
 * implementação interna do contêiner.
 *
 * Eles funcionam como uma interface genérica para acessar os elementos, sem a necessidade
 * de usar índices numéricos. Isso torna o código mais flexível, reutilizável e compatível
 * com diferentes tipos de estruturas de dados.
 *
 * Em outras palavras, iteradores atuam como “ponteiros abstratos” que podem:
 *   - Avançar ou retroceder pelo contêiner;
 *   - Ler (ou modificar) o valor apontado;
 *   - Ser usados por algoritmos genéricos da biblioteca padrão (como std::sort, std::find, etc.).
 *
 * Assim como ponteiros, eles usam o operador '*' para acessar o valor e '++' para avançar,
 * mas são objetos definidos e controlados pelos contêineres da STL.
 */

int main(int argc, char **argv)
{
    std::array<int, 4> arr = {0, 1, 2, 3};

    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        auto indexBegin = std::distance(arr.begin(), it);
        auto indexEnd = arr.size() - indexBegin - 1; // Representa a distância do final

        /**
         * .begin() => Retorna um iterador para o início do intervalo fornecido.
         * .end() => Retorna um iterador que aponta para a posição após o último elemento.
         *
         * @note Eles não são ponteiros! Por mais que se comportem de maneiras semelhantes
         * como o fato de serem acessados com ('*'), eles são objetos que retornam a um certo intervalo no container.
         *
         * std::distance é útil para calcular a distância/posição relativa de um iterador em relação a outro.
         */

        std::cout << "\nIndex do início: " << indexBegin << " Valor: " << *it
                  << " Distancia para o início: " << indexBegin << '\n';

        std::cout << "Index do final: " << indexEnd << " Valor: " << *it
                  << " Distancia para o final: " << indexEnd << '\n';
    }

    std::cout << "============================================" << '\n';

    std::cout << "\nIterando do final para o começo do vetor: ";

    // Criando um vetor de strings
    std::vector<std::string> palavras{"maçã", "banana", "laranja", "abacaxi", "manga"};

    // Iterando de trás para frente com rbegin() e rend()
    std::cout << '[';
    for (auto it = palavras.rbegin(); it != palavras.rend(); ++it)
    {
        std::cout << *it << ' '; // Imprimindo o valor apontado pelo iterador
    }
    std::cout << ']';

    return 0;
}

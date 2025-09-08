#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <iterator>

/**
 * iterators(ou iteradores): São objetos que permitem percorrer os elementos de
 * uma coleção (como std::array, std::vector, etc.) de forma sequencial, e são uma
 * abstrações poderosa que permite percorrer elementos sem depender de índices numéricos,
 * o que torna o código mais genérico e reutilizável em diferentes tipos de contêineres.
 */

int main(int argc, char **argv)
{
    std::array<int, 4> arr = {0, 1, 2, 3};

    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        auto indexBegin = std::distance(arr.begin(), it);
        auto indexEnd = arr.size() - indexBegin - 1; // Representa a distância do final

        /**
         * begin() => Retorna um iterador para o início do intervalo fornecido.
         * end() => Retorna um iterador que aponta para a posição após o último elemento.
         *
         * @note Eles não são ponteiros! Por mais que se comportem de maneiras semelhantes
         * como o fato de serem acessados com ('*'), eles são objetos que retornam
         * a um certo intervalo no container.
         *
         * std::distance é útil para calcular a distância/posição relativa de um iterador
         * em relação a outro.
         */

        std::cout << "\nIndex do início: " << indexBegin << " Valor: " << *it
                  << " Distancia para o início: " << indexBegin << '\n';

        std::cout << "Index do final: " << indexEnd << " Valor: " << *it
                  << " Distancia para o final: " << indexEnd << '\n';
    }

    std::cout << "============================================" << '\n';

    // Criando um vetor de strings
    std::vector<std::string> palavras{"maçã", "banana", "laranja", "abacaxi", "manga"};
    std::cout << "\nIterando do final para o começo do vetor: ";

    // Iterando de trás para frente com rbegin() e rend()
    std::cout << '[';
    for (auto it = palavras.rbegin(); it != palavras.rend(); ++it)
    {
        std::cout << *it << ' '; // Imprimindo o valor apontado pelo iterador
    }
    std::cout << ']';

    return 0;
}

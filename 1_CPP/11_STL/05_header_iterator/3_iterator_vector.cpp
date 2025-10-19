#include <iostream>
#include <vector>
#include <iterator>

int main(int argc, char **argv)
{
    std::vector<int> vetor(10);          // Por padrão, todos os elementos são inicializados com 0.
    std::vector<int>::iterator iterator; // Um iterador é um objeto que “aponta” para um elemento do vetor, permitindo percorrer seus elementos.

    iterator = vetor.begin(); // Inicializa o iterador apontando para o primeiro elemento do vetor.
    int it = 0;               // Cria uma variável auxiliar it, que será usada para atribuir valores ao vetor.

    for (auto &valor : vetor) // "valor" é uma referência para cada elemento do vetor
    {
        *iterator = it; // Atribui o valor da variável it ao elemento do vetor apontado pelo iterador.
        it++;           // Incrementa o valor de it para a próxima atribuição.iterator++;
    }

    std::cout << "Vetor inicial" << '\n';

    // Imprimindo o vetor
    for (const auto &valor : vetor)
    {
        std::cout << valor << ' ';
    }
    std::cout << "\n\n";

    // Modificando o vetor (dobrando os valores)
    for (auto &valor : vetor)
    {
        valor *= 2;
    }

    std::cout << "Vetor modificado" << '\n';

    // Imprimindo o vetor modificado
    for (const auto &valor : vetor)
    {
        std::cout << valor << ' ';
    }
    std::cout << '\n';
    return 0;
}

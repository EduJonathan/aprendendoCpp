#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

int main(int argc, char **argv)
{
    int array[6] = {1, 2, 3, 4, 5, 6};
    std::vector<int> inteiros(array, array + 6);
    std::ostream_iterator<int> output(std::cout, " ");

    inteiros.push_back(2);
    inteiros.push_back(3);
    inteiros.push_back(4);

    // Exibindo os valores do vetor
    std::copy(inteiros.begin(), inteiros.end(), output);

    try
    {
        // Tentando acessar um índice fora do alcance do vetor
        inteiros.at(100) = 77;
    }
    // Corrigido para captura por referência constante
    catch (const std::out_of_range &foraDeAlcance) 
    {
        std::cout << "\nExceção lançada: " << foraDeAlcance.what() << '\n';
    }

    return 0;
}

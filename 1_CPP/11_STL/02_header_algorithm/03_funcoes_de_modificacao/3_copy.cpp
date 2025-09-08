#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * - std::copy(): Copia elementos de determinados elementos.
 * - std::copy_if(): Copia elementos de determinados elementos que atendem a uma condição.
 * - std::copy_n(): Copia um número específico de elementos de um intervalo.
 */

/**
 * @brief Copia uma lista de strings para outro vetor.
 *
 * Esta função usa `std::copy()` para transferir os elementos de `source`
 * para `destination`. A função pressupõe que `destination` já tem espaço suficiente.
 *
 * @param source Vetor de origem contendo strings.
 * @param destination Vetor de destino com tamanho compatível.
 */
void copy_strings(const std::vector<std::string> &source, std::vector<std::string> &destination)
{
    std::copy(source.begin(), source.end(), destination.begin());
}

int main(int argc, char **argv)
{
    // Exemplo de uso de std::copy
    std::vector<int> source = {1, 2, 3, 4, 5};
    std::vector<int> destination(5); // Espaço já reservado

    std::copy(source.begin(), source.end(), destination.begin());

    std::cout << "std::copy (int): ";

    for (int num : destination)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    std::cout << "---------------------------------------\n";

    // Exemplo de uso de std::copy com strings
    std::vector<std::string> src = {"apple", "banana", "cherry", "date", "elderberry"};
    std::vector<std::string> dest(5); // Espaço já reservado

    copy_strings(src, dest);

    std::cout << "std::copy (string): ";

    for (const std::string &str : dest)
    {
        std::cout << str << ' ';
    }
    std::cout << '\n';

    std::cout << "---------------------------------------\n";

    // Exemplo de std::copy_if
    std::vector<int> pares;
    std::copy_if(source.begin(), source.end(), std::back_inserter(pares), [](int x)
    {
        return x % 2 == 0;
    });

    std::cout << "std::copy_if (pares): ";

    for (int num : pares)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    std::cout << "---------------------------------------\n";

    // Exemplo de std::copy_n
    std::vector<int> primeiros_tres(3);
    std::copy_n(source.begin(), 3, primeiros_tres.begin());

    std::cout << "std::copy_n (3 primeiros): ";

    for (int num : primeiros_tres)
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    return 0;
}

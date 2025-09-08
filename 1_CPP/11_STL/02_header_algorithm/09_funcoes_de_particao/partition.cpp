#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::partition(): Rearranja os elementos de forma que os que satisfazem o predicado 
 * fiquem à frente.
 * 
 * - std::is_partitioned(): Verifica se a partição já está realizada. 
 * - std::partition_point(): Retorna o primeiro elemento que não satisfaz o predicado. 
 * - std::partition_copy(): Copia os elementos com base em um predicado (não usado aqui). 
 * - std::stable_partition(): Realiza particionamento mantendo a ordem relativa dos elementos.
 */

/**
 * @brief Verifica se uma string começa com uma vogal (ignorando letras maiúsculas).
 *
 * @param str A string a ser verificada.
 * @return true Se a string começar com uma vogal.
 * @return false Caso contrário.
 */
bool comecaComVogal(const std::string &str)
{
    if (str.empty())
        return false;

    char primeiroChar = static_cast<char>(std::tolower(static_cast<unsigned char>(str[0])));
    
    return primeiroChar == 'a' || primeiroChar == 'e' || primeiroChar == 'i' ||
           primeiroChar == 'o' || primeiroChar == 'u';
}

int main(int argc, char **argv)
{
    std::vector<std::string> palavras = {"apple", "banana", "orange", "grape", "umbrella", "kiwi", "elephant", "cat"};

    // Particiona: palavras que começam com vogal vêm primeiro
    auto iteradorParticao = std::partition(palavras.begin(), palavras.end(), comecaComVogal);

    std::cout << "Palavras reorganizadas: ";

    for (const auto &palavra : palavras)
    {
        std::cout << palavra << ' ';
    }
    
    std::cout << "\nPrimeira palavra que não começa com vogal: " << *iteradorParticao << '\n';

    // Verificação da partição
    if (std::is_partitioned(palavras.begin(), palavras.end(), comecaComVogal))
    {
        std::cout << "\nO vetor está devidamente particionado.\n";
    }
    else
    {
        std::cout << "\nO vetor não está devidamente particionado.\n";
    }

    std::cout << "=================================================\n";

    std::vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    // Particiona: múltiplos de 5 ou números pares vêm primeiro
    auto it = std::partition(numeros.begin(), numeros.end(), [](int x)
    {
        return (x % 5 == 0) || (x % 2 == 0); 
    });

    std::cout << "Elementos reorganizados: ";

    for (int n : numeros)
    {
        std::cout << n << ' ';
    }

    std::cout << "\nPrimeiro elemento que não atende ao predicado: " << *it << '\n';

    if (std::is_partitioned(numeros.begin(), numeros.end(), [](int x)
    {
        return (x % 5 == 0) || (x % 2 == 0);
    }))
    {
        std::cout << "\nO vetor está devidamente particionado.\n";
    }
    else
    {
        std::cout << "\nO vetor não está devidamente particionado.\n";
    }
    return 0;
}

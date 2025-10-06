#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

/**
 * - std::unique(begin, end)
 *   → Remove elementos consecutivos duplicados no intervalo (begin, end), 
 *   retornando um iterador para o novo fim.
 *
 * - std::unique_copy(begin, end, dest)
 *   → Copia elementos únicos consecutivos do intervalo para `dest`.
 */

/**
 * @brief Compara duas strings ignorando diferenças entre maiúsculas e minúsculas.
 *
 * @param a Primeira string.
 * @param b Segunda string.
 * @return true Se forem iguais (ignorando case).
 * @return false Caso contrário.
 */
bool compararCaseInsensitive(const std::string &a, const std::string &b)
{
    if (a.size() != b.size())
        return false;

    for (std::size_t i = 0ull; i < a.size(); ++i)
    {
        if (std::tolower(static_cast<unsigned char>(a[i])) != 
            std::tolower(static_cast<unsigned char>(b[i])))
        {
            return false;
        }
    }
    return true;
}

/**
 * @brief Remove duplicatas consecutivas de um vetor de strings, ignorando diferenças de capitalização.
 *
 * @param entrada Vetor original.
 * @return std::vector<std::string> Novo vetor com elementos únicos consecutivos.
 */
std::vector<std::string> removerDuplicatasConsecutivasCaseInsensitive(const std::vector<std::string> &entrada)
{
    std::vector<std::string> resultado = entrada;

    auto fimUnico = std::unique(resultado.begin(), resultado.end(),
        [](const std::string &a, const std::string &b)
        {
            return compararCaseInsensitive(a, b);
        });

    resultado.resize(std::distance(resultado.begin(), fimUnico));
    return resultado;
}

int main(int argc, char **argv)
{
    std::vector<int> numeros = {1, 1, 2, 2, 3, 3, 4, 4, 4, 5};

    // Remove duplicatas consecutivas
    auto novoFim = std::unique(numeros.begin(), numeros.end());
    numeros.resize(std::distance(numeros.begin(), novoFim));

    std::cout << "Vetor de inteiros sem duplicatas consecutivas: ";
    for (int num : numeros)
    {
        std::cout << num << ' ';
    }

    std::cout << "\n================================\n";

    /** Exemplo com strings (insensível a maiúsculas/minúsculas) */
    std::vector<std::string> frutas = {"Apple", "apple", "Banana", "banana", "Apple", "orange", "Orange"};

    auto frutasUnicas = removerDuplicatasConsecutivasCaseInsensitive(frutas);

    std::cout << "Strings sem duplicatas consecutivas (case-insensitive): ";
    for (const auto &fruta : frutasUnicas)
    {
        std::cout << fruta << ' ';
    }

    return 0;
}

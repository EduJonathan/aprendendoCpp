#include <iostream>
#include <string>
#include <cctype>
#include <functional>
#include <algorithm>

/**
 * std::lexicographical_compare(begin1, end1, begin2, end2)
 * Compara dois ranges elemento a elemento, como se fossem palavras em um dicionário,
 * retornando true se o primeiro for "menor" que o segundo.
 */

/**
 * @brief Retorna uma lambda que compara caracteres ignorando letras maiúsculas e minúsculas.
 *
 * @return std::function<bool(char, char)> Um comparador que ignora diferenças de caixa (case).
 */
auto getCaseInsensitiveComparator() -> std::function<bool(char, char)>
{
    return [](char a, char b)
    {
        return std::tolower(static_cast<unsigned char>(a)) < std::tolower(static_cast<unsigned char>(b));
    };
}

int main(int argc, char **argv)
{
    std::string str1 = "apple";
    std::string str2 = "banana";

    // Comparação lexicográfica padrão
    if (std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end()))
    {
        std::cout << "\"" << str1 << "\" é lexicograficamente menor que \"" << str2 << "\".\n";
    }
    else
    {
        std::cout << "\"" << str1 << "\" NÃO é lexicograficamente menor que \"" << str2 << "\".\n";
    }

    // Comparação personalizada ignorando letras maiúsculas e minúsculas
    auto caseInsensitiveComparator = getCaseInsensitiveComparator();
    if (std::lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end(), caseInsensitiveComparator))
    {
        std::cout << "\"" << str1 << "\" é lexicograficamente menor que \"" << str2
                  << "\" (ignorando maiúsculas e minúsculas).\n";
    }
    else
    {
        std::cout << "\"" << str1 << "\" NÃO é lexicograficamente menor que \"" << str2
                  << "\" (ignorando maiúsculas e minúsculas).\n";
    }

    return 0;
}

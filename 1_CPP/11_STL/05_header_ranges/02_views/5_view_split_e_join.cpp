#include <iostream>
#include <string>
#include <ranges>

/**
 * std::views::join(): é um *range adaptor* que "achata" um range de ranges em um 
 * único range linear. Ele concatena todos os sub-ranges, produzindo uma única sequência
 * contínua de elementos.
 * Exemplo típico: transformar um `vector<vector<int>>` em um `range` plano de `int`.
 *
 * std::views::split(): é um *range adaptor* que divide um range em sub-ranges, usando um valor
 * delimitador ou um range delimitador como separador. O resultado é um range de sub-ranges.
 * Exemplo típico: dividir uma `std::string` em palavras usando espaço como delimitador.
 */

int main(int argc, char **argv)
{
    std::string setenca{"Eu gosto de C++ e C++ é legal."};

    // Usando std::views::split para dividir a string em palavras
    auto words = setenca | std::views::split(' ');

    // Imprimindo as palavras
    std::cout << "Palavras separadas:\n";
    for (auto word : words)
    {
        std::cout << std::string(word.begin(), word.end()) << '\n';
    }

    // Usando std::views::join para juntar as palavras de volta
    std::stringstream nova_setenca;
    for (auto word : words)
    {
        nova_setenca << std::string(word.begin(), word.end()) << ' ';
    }

    // Removendo o último espaço extra
    std::string final_sentence = nova_setenca.str();
    if (!final_sentence.empty())
    {
        final_sentence.pop_back(); // Remove o espaço extra no final
    }

    // Imprimindo a nova sentença
    std::cout << "\nNova sentença: " << final_sentence << '\n';

    return 0;
}

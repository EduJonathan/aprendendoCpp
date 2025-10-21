#include <iostream>
#include <string>
#include <regex>

/**
 * std::regex_search(): Essa função verifica se há correspondência em qualquer parte da string.
 *
 * @param input A string onde a busca será feita.
 * @param pattern O padrão regex que deve ser correspondido.
 */

/**
 * @brief Verifica se uma string contém uma correspondência com o padrão regex.
 *
 * @param input A string onde a busca será feita.
 * @param pattern O padrão regex em formato string.
 * @return true Se houver uma correspondência.
 * @return false Caso contrário.
 */
bool containsMatch(const std::string &input, const std::string &pattern)
{
    std::regex regexPattern(pattern);              // Criação do padrão regex
    return std::regex_search(input, regexPattern); // Verifica se há correspondência
}

int main(int argc, char **argv)
{
    std::string texto = "Hoje é 25/03/2025 e amanhã será 26/03/2025.";
    
    std::smatch match;
    std::regex pattern(R"(\d{2}/\d{2}/\d{4})");

    /* std::regex_search: Para encontrar padrões dentro de uma string maior.*/
    while (std::regex_search(texto, match, pattern))
    {
        std::cout << "Data encontrada: " << match[0] << '\n';
        texto = match.suffix().str(); // Continua a busca no restante da string
    }

    std::cout << "==============================" << '\n';

    std::string text = "O C++ é uma linguagem poderosa!";
    std::string padrao = R"(C\+\+)"; // Regex para encontrar "C++"

    if (containsMatch(text, padrao))
    {
        std::cout << "Correspondência encontrada!" << '\n';
    }
    else
    {
        std::cout << "Nenhuma correspondência encontrada." << '\n';
    }
    return 0;
}

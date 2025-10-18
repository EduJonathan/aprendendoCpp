#include <iostream>
#include <string>
#include <cctype>
#include <regex>

/**
 * Regex (Regular Expressions/Expressões Regulares): É uma técnica poderosa usada para buscar,
 * validar e manipular strings com padrões específicos. Ele pode ser aplicado em diversas
 * linguagens de programação, incluindo C++, Python, Java, e muitas outras.
 *
 * Quando Utilizar? Validação de entradas do usuário(e-mail, telefone), Extração de informações
 * de um texto, Substituição e manipulação de texto, Busca avançada em arquivos ou logs
 */

/**
 * @brief Converte uma string em CamelCase.
 *
 * Essa função pega uma string contendo palavras separadas por espaços e retorna
 * a mesma string formatada no estilo CamelCase, onde cada palavra tem sua
 * primeira letra em maiúscula e as demais em minúsculas.
 *
 * @param entrada A string de entrada contendo palavras separadas por espaços.
 * @return std::string A string convertida para CamelCase.
 */
std::string transformeParaCamelCase(const std::string &entrada)
{
    std::regex regex_palavras(R"([a-zA-Z]+)");
    std::sregex_iterator iter(entrada.begin(), entrada.end(), regex_palavras);
    std::sregex_iterator end;

    std::string resultado;

    while (iter != end)
    {
        std::string palavra = iter->str();
        
        if (!palavra.empty())
        {
            palavra[0] = std::toupper(palavra[0]);

            for (std::size_t i = 1ull; i < palavra.size(); ++i)
            {
                palavra[i] = std::tolower(palavra[i]);
            }

            resultado += palavra; // Adiciona ao resultado
        }

        ++iter;
    }

    return resultado;
}

int main(int argc, char **argv)
{
    std::string text{"Exercicios regex cpp"};

    /* std::regex_replace - para modificar textos de forma eficiente. */
    // Substitui os espaços por underscores
    std::string result = std::regex_replace(text, std::regex("\\s+"), "_");

    // Adiciona os underscores entre palavras que contêm letras maiúsculas e minúsculas
    result = std::regex_replace(result, std::regex("([a-z])([A-Z])"), "$1_$2");

    // Converte todas as letras para minúsculas
    for (char &caracteres : result)
    {
        caracteres = std::tolower(caracteres);
    }

    // Exibe o resultado final em snake_case
    std::cout << "Snake_case: " << result << '\n';

    std::cout << "================================" << '\n';

    // Teste de conversão para CamelCase
    std::string texto = "exercicio cpp regex";
    std::string camelCase = transformeParaCamelCase(texto);

    std::cout << "Original: " << texto << '\n';
    std::cout << "CamelCase: " << camelCase << '\n';

    return 0;
}

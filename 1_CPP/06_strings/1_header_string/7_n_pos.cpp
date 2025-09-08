#include <iostream>
#include <algorithm>
#include <string>

/**
 * std::string::npos(): Ele é apenas um valor constante especial que representa
 * "nenhuma posição" ou uma posição inválida, indicando quando uma busca não
 * encontrou o que procurava, não é case sensitive.
 */

/**
 * @brief Converte uma string para letras minúsculas.
 *
 * Esta função recebe uma string e retorna uma nova string com todas as letras
 * convertidas para minúsculas.
 *
 * @param str A string que será convertida para minúsculas.
 * @return A string convertida para minúsculas.
 */
std::string toLower(const std::string &str)
{
    // Cria uma cópia da string original
    std::string lowerStr = str;

    // Converte para minúsculas
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);

    // Retorna a string minúscula
    return lowerStr;
}

int main(int argc, char **argv)
{
    // Texto a ser pesquisado
    std::string text = "Hello, world!";
    std::string search = "world"; // Substring a ser procurada

    /**
     * @brief Procura a substring na string original (case-sensitive).
     *
     * Aqui procuramos a substring 'world' na string 'Hello, world!'.
     */
    std::size_t pos = text.find(search); // Procura pela substring 'search' na string 'text'

    // Verifica se a substring foi encontrada
    if (pos != std::string::npos)
    {
        std::cout << "Encontrado '" << search << "' na posição " << pos << '\n'; // Se encontrado, exibe a posição
    }
    else
    {
        std::cout << "Substring não Encontrada" << '\n'; // Caso não encontre a substring
    }

    std::cout << "------------------------------------" << '\n';

    std::string lowerText = toLower(text);     // Converte o texto para minúsculas
    std::string lowerSearch = toLower(search); // Converte a substring para minúsculas

    // Procura a substring convertida para minúsculas na string também convertida
    pos = lowerText.find(lowerSearch);

    // Verifica se a substring foi encontrada
    if (pos != std::string::npos)
    {
        std::cout << "Found '" << search << "' at position " << pos << '\n'; // Exibe a posição se encontrada
    }
    else
    {
        std::cout << "Substring not found" << '\n'; // Caso não encontre a substring
    }

    std::cout << "------------------------------------" << '\n';

    /**
     * @brief Demonstra a busca de uma substring que não existe no texto.
     *
     * Aqui, tentamos encontrar a substring "planet" na string "Hello, world!".
     */
    std::string texto = "Hello, world!";
    std::string subtring = "planet";             // Substring inexistente no texto
    std::size_t position = texto.find(subtring); // Procura pela substring 'subtring' na string 'texto'

    // Verifica se a substring foi encontrada
    if (position != std::string::npos)
    {
        std::cout << "Encontrado '" << search << "' na posição " << pos << '\n'; // Se encontrado, exibe a posição
    }
    else
    {
        std::cout << "Substring não Encontrada" << '\n'; // Caso não encontre a substring
    }
    return 0;
}

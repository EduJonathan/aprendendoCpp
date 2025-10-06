#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/**
 * - std::replace(begin, end, old_value, new_value)
 *   → Substitui todas as ocorrências de `old_value` por `new_value` no intervalo.
 *
 * - std::replace_if(begin, end, pred, new_value)
 *   → Substitui elementos que satisfazem `pred` por `new_value`.
 *
 * - std::replace_copy(begin, end, dest, old_value, new_value)
 *   → Copia elementos para `dest`, substituindo `old_value` por `new_value`.
 *
 * - std::replace_copy_if(begin, end, dest, pred, new_value)
 *   → Copia elementos para `dest`, substituindo os que satisfazem a condição `pred` por `new_value`.
 */

/**
 * @brief Mapeamento de palavras incorretas e suas correções.
 */
std::unordered_map<std::string, std::string> correcaoOrtografica = {
    {"nao", "não"},
    {"maca", "maçã"},
    {"vede", "verde"},
    {"voce", "você"},
    {"ortografico", "ortográfico"}};

/**
 * @brief Aplica correções ortográficas interativas em uma string.
 *
 * Percorre um texto e sugere correções de palavras com base no dicionário
 * `correcaoOrtografica`. O usuário pode optar por aceitar ou rejeitar cada sugestão.
 *
 * @param texto Texto a ser analisado.
 * @return std::string Texto possivelmente corrigido.
 */
std::string corretorOrtografico(std::string &texto)
{
    std::string textoOriginal = texto;

    for (const auto &pair : correcaoOrtografica)
    {
        std::size_t pos = 0ull;

        while ((pos = texto.find(pair.first, pos)) != std::string::npos)
        {
            std::cout << "\nTexto original: \"" << textoOriginal << "\"\n";
            std::cout << "Eu acho que você queria dizer: \"" << texto << "\"\n";
            std::cout << "Sugestão: \"" << pair.first << "\" → \"" << pair.second << "\"\n";

            char resposta = '\0';
            std::cout << "Deseja aplicar a correção? (S/N): ";
            std::cin >> resposta;

            // Se o usuário aceitar, aplica a substituição
            if (resposta == 'S' || resposta == 's')
            {
                texto.replace(pos, pair.first.length(), pair.second);
                std::cout << "Substituído com sucesso.\n";
                pos += pair.second.length(); // Avança após a nova palavra
            }
            else
            {
                std::cout << "Correção ignorada.\n";
                pos += pair.first.length(); // Avança após a palavra antiga
            }
        }
    }

    return texto;
}

int main(int argc, char **argv)
{
    // Exemplo 1: Substituir valores com std::replace
    std::vector<int> numeros = {1, 2, 3, 4, 3, 5};
    std::replace(numeros.begin(), numeros.end(), 3, 9); // Substitui todos os 3 por 9

    std::cout << "Vetor após std::replace: ";
    for (int num : numeros)
    {
        std::cout << num << ' ';
    }

    std::cout << "\n---------------------------------------\n";

    // Exemplo 2: Correção ortográfica interativa
    std::string texto = "Eu gosto de maca, mas nao gosto de vede.";
    std::cout << "Texto original: " << texto << '\n';

    std::string textoCorrigido = corretorOrtografico(texto);

    std::cout << "\nTexto corrigido: " << textoCorrigido << '\n';

    return 0;
}

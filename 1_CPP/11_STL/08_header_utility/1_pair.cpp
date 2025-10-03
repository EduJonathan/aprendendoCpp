#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

/**
 * std::pair<> É uma estrutura de dados do C++ que armazena dois valores relacionados
 * em um único objeto. Esses valores podem ser de tipos diferentes (como um int e uma string)
 * ou do mesmo tipo.
 *
 * Use std::pair quando:
 * - Você precisa armazenar exatamente dois valores relacionados temporariamente.
 * - Os valores são de tipos diferentes.
 * - Não precisa de ordenação ou busca eficiente.
 *
 * Não use quando:
 * - Precisa armazenar mais de dois valores (use std::tuple)
 * - Precisa de busca eficiente (use std::map ou std::unordered_map)
 * - Precisa de ordenação automática (use std::set ou std::map)
 */

/**
 * @brief Função que encontra pares de números em um vetor cuja soma seja igual
 * a uma chave fornecida.
 *
 * Esta função recebe um vetor de inteiros e uma chave `key`. Para cada número no vetor,
 * a função verifica se a diferença entre a chave e o número já foi encontrada anteriormente.
 * Se sim, ela adiciona o par (diferença, número) ao vetor de resultados.
 *
 * @param arr Vetor de inteiros a ser analisado.
 * @param key A soma alvo dos pares.
 * @return Um vetor de pares de inteiros que somam a chave fornecida.
 */
std::vector<std::pair<int, int>> contadorDePares(const std::vector<int> &arr, int key)
{
    std::vector<std::pair<int, int>> vetor;
    std::unordered_map<int, int> u_map;

    // Itera pelo vetor para encontrar pares cuja soma seja igual a 'key'
    for (int num : arr)
    {
        int complement = key - num; // Complemento necessário para atingir a chave

        // Se o complemento estiver no mapa, adicione os pares ao vetor
        if (u_map.find(complement) != u_map.end())
        {
            int count = u_map[complement];

            while (count > 0)
            {
                vetor.push_back({complement, num});
                count--;
            }
        }
        u_map[num]++; // Adiciona o número atual ao mapa
    }
    return vetor;
}

int main(int argc, char **argv)
{
    std::pair<int, std::string> C = {1, "C"};
    std::pair<int, std::string> CPP = {2, "C++"};
    std::pair<int, std::string> JAVA = {3, "Java"};
    std::pair<int, std::string> JAVASCRIPT = {4, "JavaScript"};
    std::pair<int, std::string> PYTHON = {5, "Python"};
    std::pair<int, std::string> RUBY = {6, "Ruby"};

    /* Atenção em dados duplicados */
    std::pair<int, std::string> RUST = {6, "Rust"};

    std::cout << "ID: " << C.first << ", Linguagem: " << C.second << '\n';
    std::cout << "ID: " << CPP.first << ", Linguagem: " << CPP.second << '\n';
    std::cout << "ID: " << JAVA.first << ", Linguagem: " << JAVA.second << '\n';
    std::cout << "ID: " << JAVASCRIPT.first << ", Linguagem: " << JAVASCRIPT.second << '\n';
    std::cout << "ID: " << PYTHON.first << ", Linguagem: " << PYTHON.second << '\n';
    std::cout << "ID: " << RUBY.first << ", Linguagem: " << RUBY.second << '\n';
    std::cout << "ID: " << RUST.first << ", Linguagem: " << RUST.second << '\n';

    std::cout << "==============================================" << '\n';

    // Teste da função contadorDePares com vetor de inteiros
    std::vector<int> vetor = {1, 5, 7, -1, 5, 1, 5, 1, -5};
    int soma = 6; // A chave (soma) que estamos procurando nos pares

    // Chama a função contadorDePares
    std::vector<std::pair<int, int>> pairs = contadorDePares(vetor, soma);

    // Exibe os pares encontrados
    std::cout << "Pares encontrados cuja soma é " << soma << ":\n";
    for (const auto &pair : pairs)
    {
        std::cout << '(' << pair.first << ", " << pair.second << ')' << '\n';
    }
    return 0;
}

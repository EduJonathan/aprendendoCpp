#include <iostream>
#include <vector>
#include <algorithm>

/**
 * - std::find(): Encontra a primeira ocorrência de um valor em um intervalo.
 * - std::find_if(): Encontra a primeira ocorrência de um valor em um intervalo que satisfaça uma condição. 
 * - std::find_if_not(): Encontra a primeira ocorrência de um valor em um intervalo que não satisfaça uma condição. 
 * - std::find_end(): Encontra a última ocorrência de um valor em um intervalo. 
 * - std::find_first_of(): Encontra o primeiro valor que corresponde a um dos valores em um intervalo.
 */

/**
 * @brief Encontra a primeira ocorrência do valor 5 em um vetor.
 *
 * A função utiliza `std::find_if` com uma lambda para procurar o valor 5 no vetor.
 * Se o valor for encontrado, imprime a posição; caso contrário, informa que o valor
 * não foi encontrado.
 *
 * @param vec Vetor de inteiros a ser pesquisado.
 * @return Retorna o vetor como está.
 */
auto encontre_valor(std::vector<int> &vec) -> std::vector<int>
{
    auto it = std::find_if(vec.begin(), vec.end(), [](int value)
    {
        return value == 5;
    });

    if (it != vec.end())
    {
        std::cout << "Valor 5 encontrado na posição: " << std::distance(vec.begin(), it) << '\n';
    }
    else
    {
        std::cout << "Valor não encontrado." << '\n';
    }

    return {vec};
}

/**
 * @brief Preenche um vetor de caracteres a partir de uma string alvo.
 *
 * A função percorre a string alvo e verifica se cada caractere está presente
 * no vetor de caracteres. Caso o caractere seja encontrado no vetor, ele é adicionado
 * a uma string (frase).
 *
 * @param vec Vetor de caracteres onde procuraremos os caracteres da string alvo.
 * @param string_alvo String com os caracteres a serem verificados.
 */
void preenchaVetor(std::vector<char> &vec, const std::string &string_alvo)
{
    // String para armazenar a frase formada
    std::string frase;

    // Lambda que verifica se o caractere está presente no vetor
    auto estaNoVetor = [&vec](char c)
    {
        // Verifica se o caractere está em vec
        return std::find(vec.begin(), vec.end(), c) != vec.end();
    };

    // Percorre a string_alvo e tenta formar a frase com caracteres presentes em vec
    for (char c : string_alvo)
    {
        if (estaNoVetor(c))
        {
            frase += c; // Adiciona o caractere à frase formada
        }
    }

    // Exibe a frase formada
    std::cout << "Frase formada: " << frase << '\n';
}

int main(int argc, char **argv)
{
    // Vetor de inteiros
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Percorrendo o vetor e usando std::find para encontrar números ímpares
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        // Verificar se o número é ímpar
        if (*it % 2 != 0)
        {
            std::cout << "Número ímpar encontrado: " << *it << '\n';
        }
    }

    // Usando std::find para encontrar o valor 3
    auto it = std::find(vec.begin(), vec.end(), 3);

    if (it != vec.end())
    {
        std::cout << "Valor 3 encontrado na posição: " << std::distance(vec.begin(), it) << '\n';
    }
    else
    {
        std::cout << "Valor não encontrado." << '\n';
    }

    // Chamando a função para procurar o valor 5
    encontre_valor(vec);

    std::cout << "=============================" << '\n';

    // Vetor de caracteres
    std::vector<char> v = {'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd'};

    // String alvo que queremos formar
    std::string string_alvo = "Cpp";

    // Chama a função para preencher o vetor e formar a frase
    preenchaVetor(v, string_alvo);
    return 0;
}

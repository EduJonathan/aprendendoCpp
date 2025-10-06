#include <iostream>
#include <set>
#include <string>
#include <map>

/**
 * std::map<K, V> é um container associativo que armazena pares chave-valor com chaves únicas.
 * As chaves são mantidas em ordem e o acesso, inserção e remoção têm complexidade O(log n).
 * 
 * Internamente, é implementado como uma árvore vermelho-preto, garantindo eficiência.
 * 
 * O acesso ao valor é feito via chave, por exemplo, map[k], que insere um valor padrão se a chave não existir.
 */

/**
 * @brief Exibe os elementos de um mapeamento (std::map) de strings para inteiros.
 *
 * Esta função percorre o mapa e imprime cada chave (nome) com o valor associado
 * (número de anos), no formato: "chave tem valor anos".
 *
 * @param m O mapa a ser exibido, onde as chaves são do tipo `std::string` e os valores são `int`.
 */
void mostrarMapeamento(const std::map<std::string, int> &m)
{
    std::cout << "--------------------------\n";
    for (const auto &par : m)
    {
        std::cout << par.first << " tem " << par.second << " anos." << '\n';
    }
    std::cout << "--------------------------\n";
}

/**
 * @brief Converte um multiset de números em um mapa, indicando se cada número é par ou ímpar.
 *
 * Para cada número presente no multiset, verifica se ele é par ou ímpar e o armazena
 * em um mapa, onde as chaves são os números e os valores são as classificações
 * ("Par" ou "Ímpar").
 *
 * @param numeros O multiset contendo os números inteiros a serem analisados.
 * @return Um mapa com os números e suas respectivas classificações ("Par" ou "Ímpar").
 */
std::map<int, std::string> transformarParOuImpar(const std::multiset<int> &numeros)
{
    std::map<int, std::string> resultado;

    // Para cada número no multiset, verifica se é par ou ímpar e armazena no mapa
    for (const int &numero : numeros)
    {
        if (numero % 2 == 0)
        {
            resultado[numero] = "Par";
        }
        else
        {
            resultado[numero] = "Ímpar";
        }
    }
    return resultado;
}

int main(int argc, char **argv)
{
    // Mapa para contar as ocorrências de cada string inserida pelo usuário.
    std::map<std::string, int> Map;

    // Quantidade de strings a serem inseridas (alterável conforme necessidade).
    int n = 3;

    // Laço para ler 'n' strings do usuário e contar as ocorrências.
    for (int i = 0; i < n; ++i)
    {
        std::string str; // Variável para armazenar a string inserida.

        // Solicita a entrada da string e armazena no mapa, incrementando o valor de cada chave.
        std::cout << "Insira a " << i + 1 << "ª string: ";
        std::cin >> str;

        // Se já existir, incrementa o valor; se não, cria com valor 1.
        Map[str] = Map[str] + 1;
    }

    // Exibe o mapa com as contagens de repetições de cada string.
    std::cout << "Contagem das strings inseridas:\n";
    for (const auto &it : Map)
    {
        std::cout << "Elemento '" << it.first << "' : Repetiu " << it.second << " vez(es)\n";
    }

    std::cout << "-------------------------------------" << '\n';

    // Exibe um mapa de idades para algumas pessoas.
    std::map<std::string, int> idades;
    idades["Alice"] = 25;
    idades["Bob"] = 30;
    idades["Charlie"] = 35;

    std::cout << "\nIdades:\n";
    mostrarMapeamento(idades); // Exibe o mapeamento de idades.

    std::cout << "\n-------------------------------------" << '\n';

    // Criando um multiset com números repetidos.
    std::multiset<int> numeros = {1, 2, 3, 4, 5, 2, 4, 6};

    // Converte o multiset para um mapa com informações se o número é "Par" ou "Ímpar".
    std::map<int, std::string> resultado = transformarParOuImpar(numeros);

    // Exibe o resultado da transformação (número -> Par/Ímpar).
    std::cout << "\nResultado de transformação (número -> par/ímpar):\n";
    for (const auto &par : resultado)
    {
        std::cout << "Número: " << par.first << " - " << par.second << '\n';
    }
    return 0;
}

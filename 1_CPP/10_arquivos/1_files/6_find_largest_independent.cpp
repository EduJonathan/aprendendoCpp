#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

/**
 * @brief Verifica se um vértice é removível (não tem vizinhos no conjunto independente).
 *
 * @param vizinhos Lista de vizinhos do vértice.
 * @param cobertura Conjunto de vértices (1 = dentro da cobertura, 0 = fora).
 * @return true Se o vértice pode ser removido.
 * @return false Caso contrário.
 */
bool ehRemovivel(const std::vector<int> &vizinhos, const std::vector<int> &cobertura)
{
    for (int v : vizinhos)
    {
        if (cobertura[v] == 0)
            return false;
    }
    return true;
}

/**
 * @brief Encontra o vértice que maximiza remoções subsequentes.
 *
 * @param listaAdj Lista de adjacência.
 * @param cobertura Conjunto de vértices.
 * @return int Índice do vértice removível, ou -1 se não houver.
 */
int encontrarMaxRemovivel(const std::vector<std::vector<int>> &listaAdj, const std::vector<int> &cobertura)
{
    int verticeRemovivel = -1, maximo = -1;

    for (std::size_t i = 0; i < cobertura.size(); ++i)
    {
        if (cobertura[i] == 1 && ehRemovivel(listaAdj[i], cobertura))
        {
            std::vector<int> temp = cobertura;

            temp[i] = 0;
            int soma = 0;

            for (std::size_t j = 0; j < temp.size(); ++j)
            {
                if (temp[j] == 1 && ehRemovivel(listaAdj[j], temp))
                {
                    ++soma;
                }
            }

            if (soma > maximo)
            {
                maximo = soma;
                verticeRemovivel = static_cast<int>(i);
            }
        }
    }
    return verticeRemovivel;
}

/**
 * @brief Procedimento 1: Remove vértices que não violam o conjunto independente.
 *
 * @param listaAdj Lista de adjacência.
 * @param cobertura Conjunto de vértices.
 * @return std::vector<int> Novo conjunto após remoções.
 */
std::vector<int> procedimento1(const std::vector<std::vector<int>> &listaAdj, std::vector<int> cobertura)
{
    int verticeRemovivel = 0;
    while ((verticeRemovivel = encontrarMaxRemovivel(listaAdj, cobertura)) != -1)
    {
        cobertura[verticeRemovivel] = 0;
    }
    return cobertura;
}

/**
 * @brief Procedimento 2: Aplica trocas para otimizar o conjunto.
 *
 * @param listaAdj Lista de adjacência.
 * @param cobertura Conjunto de vértices.
 * @param k Número máximo de trocas permitidas.
 * @return std::vector<int> Novo conjunto após trocas.
 */
std::vector<int> procedimento2(const std::vector<std::vector<int>> &listaAdj, std::vector<int> cobertura, int k)
{
    int contador = 0;

    for (std::size_t i = 0; i < cobertura.size(); ++i)
    {
        if (cobertura[i] == 1)
        {
            int soma = 0, indice = -1;

            for (std::size_t j = 0; j < listaAdj[i].size(); ++j)
            {
                if (cobertura[listaAdj[i][j]] == 0)
                {
                    indice = j;
                    ++soma;
                }
            }

            if (soma == 1 && indice != -1 && cobertura[listaAdj[i][indice]] == 0)
            {
                cobertura[listaAdj[i][indice]] = 1;
                cobertura[i] = 0;
                cobertura = procedimento1(listaAdj, cobertura);

                if (++contador > k)
                    break;
            }
        }
    }
    return cobertura;
}

/**
 * @brief Calcula o tamanho da cobertura de vértices.
 *
 * @param cobertura Conjunto de vértices.
 * @return int Quantidade de vértices na cobertura.
 */
int tamanhoCobertura(const std::vector<int> &cobertura)
{
    return std::count(cobertura.begin(), cobertura.end(), 1);
}

int main(int argc, char **argv)
{
    std::ifstream entrada("graph.txt");
    std::ofstream saida("sets.txt");

    if (!entrada.is_open() || !saida.is_open())
    {
        std::cerr << "Erro ao abrir arquivos!" << '\n';
        return 1;
    }

    std::cout << "Algoritmo de Conjunto Independente." << '\n';
    int n = 0;
    entrada >> n;

    std::vector<std::vector<int>> matrizAdj(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            entrada >> matrizAdj[i][j];
        }
    }

    // Construção da lista de adjacência
    std::vector<std::vector<int>> listaAdj(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (matrizAdj[i][j] == 1)
            {
                listaAdj[i].push_back(j);
            }
        }
    }

    std::cout << "O grafo possui n = " << n << " vértices." << '\n';

    int alvoConjuntoIndependente = 0, maxCobertura = 0;

    std::cout << "Procurar um Conjunto Independente de tamanho pelo menos k = ";
    std::cin >> alvoConjuntoIndependente;
    maxCobertura = n - alvoConjuntoIndependente;

    bool solucaoEncontrada = false;
    int minCobertura = n + 1, contador = 0;
    std::vector<std::vector<int>> coberturasCandidatas;
    std::vector<int> coberturaInicial(n, 1);

    // Primeira fase: tenta cada vértice
    for (int i = 0; i < n; ++i)
    {
        if (solucaoEncontrada)
            break;

        ++contador;
        std::cout << contador << ". ";
        saida << contador << ". ";

        std::vector<int> cobertura = coberturaInicial;
        cobertura[i] = 0;
        cobertura = procedimento1(listaAdj, cobertura);

        int tamCobertura = tamanhoCobertura(cobertura);
        if (tamCobertura < minCobertura)
            minCobertura = tamCobertura;

        if (tamCobertura <= maxCobertura)
        {
            saida << "Conjunto Independente (" << n - tamCobertura << "): ";

            for (int j = 0; j < n; ++j)
            {
                if (cobertura[j] == 0)
                    saida << j + 1 << ' ';
            }
            saida << '\n';

            std::cout << "Tamanho do Conjunto Independente: " << n - tamCobertura << '\n';
            coberturasCandidatas.push_back(cobertura);
            solucaoEncontrada = true;
            break;
        }

        for (int j = 0; j < n - maxCobertura; ++j)
        {
            cobertura = procedimento2(listaAdj, cobertura, j);
        }

        tamCobertura = tamanhoCobertura(cobertura);
        if (tamCobertura < minCobertura)
            minCobertura = tamCobertura;

        saida << "Conjunto Independente (" << n - tamCobertura << "): ";
        for (int j = 0; j < n; ++j)
        {
            if (cobertura[j] == 0)
                saida << j + 1 << ' ';
        }
        saida << '\n';

        std::cout << "Tamanho do Conjunto Independente: " << n - tamCobertura << '\n';
        coberturasCandidatas.push_back(cobertura);
        if (tamCobertura <= maxCobertura)
        {
            solucaoEncontrada = true;
            break;
        }
    }

    // Segunda fase: interseções entre coberturas
    for (std::size_t p = 0; p < coberturasCandidatas.size(); ++p)
    {
        if (solucaoEncontrada)
            break;

        for (std::size_t q = p + 1; q < coberturasCandidatas.size(); ++q)
        {
            if (solucaoEncontrada)
                break;
            ++contador;

            std::cout << contador << ". ";
            saida << contador << ". ";

            std::vector<int> cobertura = coberturaInicial;

            for (int r = 0; r < n; ++r)
            {
                if (coberturasCandidatas[p][r] == 0 && coberturasCandidatas[q][r] == 0)
                    cobertura[r] = 0;
            }

            cobertura = procedimento1(listaAdj, cobertura);
            int tamCobertura = tamanhoCobertura(cobertura);

            if (tamCobertura < minCobertura)
                minCobertura = tamCobertura;

            if (tamCobertura <= maxCobertura)
            {
                saida << "Conjunto Independente (" << n - tamCobertura << "): ";
                for (int j = 0; j < n; ++j)
                {
                    if (cobertura[j] == 0)
                        saida << j + 1 << ' ';
                }
                saida << '\n';

                std::cout << "Tamanho do Conjunto Independente: " << n - tamCobertura << '\n';
                solucaoEncontrada = true;
                break;
            }

            for (int j = 0; j < maxCobertura; ++j)
            {
                cobertura = procedimento2(listaAdj, cobertura, j);
            }

            tamCobertura = tamanhoCobertura(cobertura);
            if (tamCobertura < minCobertura)
                minCobertura = tamCobertura;

            saida << "Conjunto Independente (" << n - tamCobertura << "): ";

            for (int j = 0; j < n; ++j)
            {
                if (cobertura[j] == 0)
                    saida << j + 1 << ' ';
            }
            saida << '\n';

            std::cout << "Tamanho do Conjunto Independente: " << n - tamCobertura << '\n';
            if (tamCobertura <= maxCobertura)
            {
                solucaoEncontrada = true;
                break;
            }
        }
    }

    if (solucaoEncontrada)
    {
        std::cout << "Encontrado Conjunto Independente de tamanho pelo menos " << alvoConjuntoIndependente << '.' << '\n';
    }
    else
    {
        std::cout << "Não foi possível encontrar Conjunto Independente de tamanho pelo menos "
                  << alvoConjuntoIndependente << '.' << "\nMaior Conjunto Independente encontrado tem tamanho " << n - minCobertura << '.' << '\n';
    }

    entrada.close();
    saida.close();
    return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <sstream>

/**
 * Este código irá ler a base de dados do arquivo lista_alunos.txt, irá organizar os dados com o
 * algoritmo Selection Sort e iremos poder escolher entre 2 algoritmos de buscas sendo a
 * busca linear e a busca binária, para sabermos qual dos dois algoritmos de busca terá melhor
 * desempenho de busca na base de dados, desempenho esse que será realizado pelos metódos da header chrono.
 */

const int MAX_LINHAS = 1;     // Uma linha de nomes
const int MAX_COLUNAS = 1000; // Suporta 798 nomes

/**
 * @brief Troca o conteúdo de duas strings.
 *
 * @param a Referência para a primeira string.
 * @param b Referência para a segunda string.
 */
void swap(std::string &a, std::string &b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

/**
 * @brief Ordena um vetor de strings em ordem crescente utilizando o algoritmo Selection Sort.
 *
 * @param vetor Vetor de strings a ser ordenado.
 * @param tamanho Tamanho do vetor.
 */
void selection_sort(std::string vetor[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; ++i)
    {
        int posicaoDoMenorValor = i;
        for (int j = i + 1; j < tamanho; ++j)
        {
            if (vetor[j] < vetor[posicaoDoMenorValor])
            {
                posicaoDoMenorValor = j;
            }
        }
        if (posicaoDoMenorValor != i)
        {
            swap(vetor[i], vetor[posicaoDoMenorValor]);
        }
    }
}

/**
 * @brief Realiza uma busca linear em um vetor de strings.
 *
 * @param vetor Vetor de strings onde a busca será feita.
 * @param tamanho Tamanho do vetor.
 * @param valorProcurado Valor que se deseja encontrar.
 * @return int Índice do valor encontrado ou -1 se não for encontrado.
 */
int busca_linear(const std::string vetor[], int tamanho, const std::string &valorProcurado)
{
    for (int i = 0; i < tamanho; ++i)
    {
        if (valorProcurado == vetor[i])
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Realiza uma busca binária em um vetor de strings ordenado.
 *
 * @param vetor Vetor de strings ordenado.
 * @param tamanho Tamanho do vetor.
 * @param valorProcurado Valor que se deseja encontrar.
 * @return int Índice do valor encontrado ou -1 se não for encontrado.
 */
int busca_binaria(const std::string vetor[], int tamanho, const std::string &valorProcurado)
{
    int esquerda = 0;
    int direita = tamanho - 1;
    while (esquerda <= direita)
    {
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] == valorProcurado)
        {
            return meio;
        }
        else if (vetor[meio] < valorProcurado)
        {
            esquerda = meio + 1;
        }
        else
        {
            direita = meio - 1;
        }
    }
    return -1;
}

/**
 * @brief Remove aspas duplas de uma string no início e no final.
 *
 * @param str String a ser modificada.
 */
void remover_aspas(std::string &str)
{
    str.erase(0, str.find_first_not_of('"'));
    str.erase(str.find_last_not_of('"') + 1);
}

/**
 * @brief Remove espaços em branco no início e no final de uma string.
 *
 * @param str String a ser modificada.
 */
void limpar_espacos(std::string &str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch)
    {
        return !std::isspace(ch);
    }));

    str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch)
    {
        return !std::isspace(ch);
    }).base(), str.end());
}

int main(int argc, char **argv)
{
    // Caminho absoluto no Windows
    // std::ifstream file("C:\\Users\\EDUARDO_OLIVEIRA\\Documents\\aprendendoCpp\\CPP\\10_arquivos\\2_header_sstream\\lista_alunos.txt");

    // Caminho absoluto no linux
    std::ifstream file("/home/eduardo/Documentos/aprendendoCpp/1_CPP/10_arquivos/2_header_sstream/lista_alunos.txt");
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo." << '\n';
        return 1;
    }

    std::string matriz[MAX_LINHAS][MAX_COLUNAS];
    int linhas = 0;
    int colunas = 0;
    std::string linha;

    while (std::getline(file, linha) && linhas < MAX_LINHAS)
    {
        std::istringstream iss(linha);
        std::string palavra;
        colunas = 0;
        
        while (std::getline(iss, palavra, ',') && colunas < MAX_COLUNAS)
        {
            remover_aspas(palavra);
            limpar_espacos(palavra);
            if (!palavra.empty())
            {
                matriz[linhas][colunas] = palavra;
                colunas++;
            }
        }
        linhas++;
    }
    file.close();

    std::string nomes[MAX_COLUNAS];
    int num_nomes = 0;
    for (int j = 0; j < colunas && num_nomes < MAX_COLUNAS; ++j)
    {
        if (!matriz[0][j].empty())
        {
            nomes[num_nomes] = matriz[0][j];
            num_nomes++;
        }
    }

    std::cout << "Nomes lidos: " << num_nomes << '\n';
    selection_sort(nomes, num_nomes);

    int opcao = 0;
    std::cout << "Escolha qual busca deseja realizar: ";
    std::cout << "\n1 - Para busca Linear\n";
    std::cout << "2 - Para busca Binária\n";
    std::cin >> opcao;
    std::cin.ignore();

    std::string valorProcurado;
    std::cout << "Digite o nome do aluno para ser procurado: ";
    std::getline(std::cin, valorProcurado);
    limpar_espacos(valorProcurado);

    // Medir tempo da busca linear
    auto start_linear = std::chrono::high_resolution_clock::now();
    int resultado_linear = busca_linear(nomes, num_nomes, valorProcurado);
    auto end_linear = std::chrono::high_resolution_clock::now();
    auto duration_linear = std::chrono::duration_cast<std::chrono::microseconds>(end_linear - start_linear).count();

    // Medir tempo da busca binária
    auto start_binaria = std::chrono::high_resolution_clock::now();
    int resultado_binaria = busca_binaria(nomes, num_nomes, valorProcurado);
    auto end_binaria = std::chrono::high_resolution_clock::now();
    auto duration_binaria = std::chrono::duration_cast<std::chrono::microseconds>(end_binaria - start_binaria).count();

    // Exibir resultados
    std::cout << "\nResultados da busca:\n";
    if (resultado_linear != -1)
    {
        std::cout << "Busca Linear: Valor encontrado na posição " << resultado_linear << ": " << nomes[resultado_linear] << '\n';
        std::cout << "Tempo de busca linear: " << duration_linear << " microsegundos\n";
    }
    else
    {
        std::cout << "Busca Linear: Valor não encontrado.\n";
        std::cout << "Tempo de busca linear: " << duration_linear << " microsegundos\n";
    }

    if (resultado_binaria != -1)
    {
        std::cout << "Busca Binária: Valor encontrado na posição " << resultado_binaria << ": " << nomes[resultado_binaria] << '\n';
        std::cout << "Tempo de busca binária: " << duration_binaria << " microsegundos\n";
    }
    else
    {
        std::cout << "Busca Binária: Valor não encontrado.\n";
        std::cout << "Tempo de busca binária: " << duration_binaria << " microsegundos\n";
    }

    return 0;
}

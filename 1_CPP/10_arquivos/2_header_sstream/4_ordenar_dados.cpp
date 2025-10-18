#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

// Este código irá ler a base de dados do arquivo lista_alunos.txt, irá organizar os dados com base no algoritmo Selection Sort

const int MAX_LINHAS = 50;  // Defina o número máximo de linhas da matriz
const int MAX_COLUNAS = 50; // Defina o número máximo de colunas da matriz

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
    int posicaoDoMenorValor = 0;

    for (int i = 0; i < tamanho - 1; ++i)
    {
        posicaoDoMenorValor = i;

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

int main(int argc, char **argv)
{
    // Caminho absoluto no Windows
    // std::ifstream file("C:\\Users\\EDUARDO_OLIVEIRA\\Documents\\aprendendoCpp\\CPP\\10_arquivos\\2_header_sstream\\lista_alunos.txt");

    // Abrindo o arquivo para leitura no linux
    std::ifstream file("/home/eduardo/Documentos/aprendendoCpp/1_CPP/10_arquivos/2_header_sstream/lista_alunos.txt");

    // Verificando se houve erro ao abrir o arquivo
    if (!file.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo." << '\n';
        return 1;
    }

    // Matriz para armazenar os dados do arquivo
    std::string matriz[MAX_LINHAS][MAX_COLUNAS];

    // variáveis serão usadas para rastrear a posição atual na matriz matriz.
    int linhas = 0;
    int colunas = 0;

    // Esta variável será usada para armazenar uma linha de entrada lida de algum lugar,
    // como um arquivo ou entrada do usuário.
    std::string linha;

    // Lendo os dados do arquivo e armazenando na matriz
    while (std::getline(file, linha) && linhas < MAX_LINHAS)
    {
        std::istringstream iss(linha);

        std::string palavra;
        colunas = 0;

        // Modificado para separar as palavras pelo caractere ','
        while (std::getline(iss, palavra, ','))
        {
            // Removendo as aspas duplas das palavras no inicio e no final
            palavra.erase(0, palavra.find_first_not_of('"'));
            palavra.erase(palavra.find_last_not_of('"') + 1);

            matriz[linhas][colunas] = palavra;
            colunas++;
        }
        linhas++;
    }
    file.close(); // Fechando o arquivo após a leitura

    // Ordenando a primeira linha da matriz
    selection_sort(matriz[0], colunas);

    // Exibindo os dados ordenados da primeira linha da matriz
    std::cout << "Dados ordenados:" << '\n';

    for (int i = 0; i < colunas; ++i)
    {
        std::cout << matriz[0][i] << " - Posição:: " << i << '\n';
    }
    std::cout << '\n';

    return 0;
}

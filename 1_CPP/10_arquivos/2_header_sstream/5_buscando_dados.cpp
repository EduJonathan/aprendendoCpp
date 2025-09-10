#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

const int MAX_LINHAS = 50;
const int MAX_COLUNAS = 500;

void swap(std::string &a, std::string &b)
{
    std::string temp = a;
    a = b;
    b = temp;
}

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

void remover_aspas(std::string &str)
{
    str.erase(0, str.find_first_not_of('"'));
    str.erase(str.find_last_not_of('"') + 1);
}

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
    std::ifstream file("C:\\Users\\EDUARDO_OLIVEIRA\\Documents\\aprendendoCpp\\CPP\\10_arquivos\\2_header_sstream\\lista_alunos.txt");
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

    // Copiar nomes da primeira linha para o vetor
    std::string nomes[MAX_COLUNAS];
    int num_nomes = 0;
    for (int j = 0; j < colunas && num_nomes < MAX_COLUNAS; j++)
    {
        if (!matriz[0][j].empty())
        {
            nomes[num_nomes] = matriz[0][j];
            num_nomes++;
        }
    }

    // Ordenar os nomes
    selection_sort(nomes, num_nomes);

    // Escolher o tipo de busca
    int opcao = 0;
    std::cout << "Escolha qual busca deseja realizar: ";
    std::cout << "\n1 - Para busca Linear\n";
    std::cout << "2 - Para busca Binária\n";
    std::cin >> opcao;
    std::cin.ignore(); // Ignora o '\n'

    // Solicitar o nome a ser procurado
    std::string valorProcurado;
    std::cout << "Digite o nome do aluno para ser procurado: ";
    std::getline(std::cin, valorProcurado);
    limpar_espacos(valorProcurado);

    int resultado = -1;
    if (opcao == 1)
    {
        resultado = busca_linear(nomes, num_nomes, valorProcurado);
    }
    else if (opcao == 2)
    {
        resultado = busca_binaria(nomes, num_nomes, valorProcurado);
    }

    if (resultado != -1)
    {
        std::cout << "Valor encontrado na posição " << resultado << ": " << nomes[resultado] << '\n';
    }
    else
    {
        std::cout << "Valor não encontrado." << '\n';
    }

    return 0;
}

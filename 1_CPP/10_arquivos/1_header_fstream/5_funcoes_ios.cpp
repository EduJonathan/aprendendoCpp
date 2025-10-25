#include <iostream>
#include <string>
#include <fstream>

/**
 * @brief Modos de abertura da função `open()` em fluxos de arquivo (`std::ifstream`, `std::ofstream`, `std::fstream`).
 *
 * A função `open()` permite abrir arquivos especificando um ou mais modos de operação:
 *
 * ```cpp
 * arquivo.open("<nome_do_arquivo>", <modo>);
 * ```
 *
 * O parâmetro `<modo>` pode ser um único valor ou uma combinação (usando o operador `|`) dos seguintes flags de abertura:
 *
 * | Modo               | Descrição                                                                                                |
 * |--------------------|----------------------------------------------------------------------------------------------------------|
 * | `std::ios::in`     | Abre o arquivo para **leitura** (entrada). Usado por `std::ifstream` ou `std::fstream`.                  |
 * | `std::ios::out`    | Abre o arquivo para **escrita** (saída). Usado por `std::ofstream` ou `std::fstream`.                    |
 * | `std::ios::binary` | Abre o arquivo em **modo binário**, em vez de texto.                                                     |
 * | `std::ios::ate`    | Move o ponteiro de leitura/escrita para o **final do arquivo** imediatamente após abrir.                 |
 * | `std::ios::app`    | Todas as escritas são feitas **no final do arquivo** (modo de **acréscimo**). Usado apenas para escrita. |
 * | `std::ios::trunc`  | Se o arquivo já existir, **apaga o conteúdo** antes de escrever (modo de truncamento).                   |
 *
 * ### Exemplos
 *
 * ```cpp
 * std::ofstream saida;
 * saida.open("dados.txt", std::ios::out | std::ios::trunc);
 *
 * std::ifstream entrada;
 * entrada.open("dados.txt", std::ios::in);
 *
 * std::fstream arquivo;
 * arquivo.open("dados.bin", std::ios::in | std::ios::out | std::ios::binary);
 * ```
 *
 * @note O modo padrão de `std::ofstream` é `std::ios::out | std::ios::trunc`, enquanto o de `std::ifstream` é `std::ios::in`.
 */

/**
 * @brief Une o conteúdo de dois arquivos em um arquivo de destino.
 *
 * Lê linha por linha dos dois arquivos de entrada e escreve alternadamente no arquivo alvo,
 * com um espaço separando linhas não vazias. Retorna false se houver erro na escrita.
 *
 * @param arquivo1 Primeiro arquivo de entrada.
 * @param arquivo2 Segundo arquivo de entrada.
 * @param alvo Arquivo de saída onde o conteúdo será gravado.
 * @return true se a união for concluída com sucesso, false em caso de erro.
 */
bool unirArquivos(std::ifstream &arquivo1, std::ifstream &arquivo2, std::ofstream &alvo)
{
    std::string linha1, linha2;
    bool success = true;

    while (std::getline(arquivo1, linha1) || std::getline(arquivo2, linha2))
    {
        bool wrote = false;
        if (!linha1.empty())
        {
            alvo << linha1;
            wrote = true;
        }
        if (!linha2.empty())
        {
            if (wrote)
                alvo << ' ';
            alvo << linha2;
            wrote = true;
        }
        if (wrote)
        {
            alvo << '\n';
            if (!alvo)
            {
                success = false;
                break;
            }
        }
        linha1.clear();
        linha2.clear();
    }

    return success && arquivo1.eof() && arquivo2.eof() && alvo.good();
}

/**
 * @brief Função principal: realiza a união de dois arquivos em um arquivo destino.
 *
 * @param argc Quantidade de argumentos.
 * @param argv Vetor de strings com os nomes dos arquivos.
 * @return 0 em caso de sucesso, 1 em caso de erro.
 *
 * @example
 * ./programa entrada1.txt entrada2.txt saida.txt
 */
int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cerr << "Argumentos insuficientes: forneça 2 arquivos de entrada e 1 de saída.\n";
        return 1;
    }

    std::ifstream file1(argv[1]);
    if (!file1.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << argv[1] << '\n';
        return 1;
    }

    std::ifstream file2(argv[2]);
    if (!file2.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo: " << argv[2] << '\n';
        return 1;
    }

    std::ofstream alvo(argv[3], std::ios::out | std::ios::trunc);
    if (!alvo.is_open())
    {
        std::cerr << "Erro ao abrir o arquivo de saída: " << argv[3] << '\n';
        return 1;
    }

    if (unirArquivos(file1, file2, alvo))
    {
        std::cout << "Os arquivos foram concatenados com sucesso.\n";
    }
    else
    {
        std::cerr << "Erro ao concatenar os arquivos.\n";
        return 1;
    }

    return 0;
}

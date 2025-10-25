#include <iostream>
#include <cctype>
#include <fstream>

/**
 * @brief Apontadores de posição em arquivos.
 *
 * Os apontadores são métodos usados para mover ou obter a posição atual do cursor de leitura/escrita dentro de um arquivo.
 *
 * Principais funções:
 * - `fseek()` — move o ponteiro de arquivo (C padrão, <cstdio>).
 * - `seekg()` — move o ponteiro de leitura (get) em streams (`ifstream`).
 * - `seekp()` — move o ponteiro de escrita (put) em streams (`ofstream`).
 * - `tellg()` — retorna a posição atual do ponteiro de leitura.
 * - `tellp()` — retorna a posição atual do ponteiro de escrita.
 * - `SEEK_SET`, `SEEK_CUR`, `SEEK_END` — constantes usadas com `fseek()` para indicar origem do deslocamento.
 */

/**
 * @brief Converte todas as letras minúsculas de um arquivo em maiúsculas.
 *
 * Esta função percorre o conteúdo de um arquivo (já aberto com `std::fstream`)
 * e, sempre que encontra um caractere minúsculo (`islower`), o converte para
 * maiúsculo (`toupper`). A conversão é feita diretamente no arquivo,
 * reposicionando o ponteiro de escrita para sobrescrever o caractere.
 *
 * @param file Referência para o objeto `std::fstream` aberto no modo leitura e escrita.
 * @return int Retorna `0` se o processo ocorreu corretamente,
 * ou `1` caso o arquivo não esteja aberto.
 *
 * @note O arquivo deve ser aberto em modo binário e leitura/escrita,
 *       por exemplo: `std::fstream file("arquivo.txt", std::ios::in | std::ios::out);`
 */
int upper_file(std::fstream &file)
{
    if (!file.is_open())
    {
        std::cerr << "Não foi possível abrir o arquivo" << '\n';
        return 1;
    }

    char caractere = '\0';

    while (file.get(caractere))
    {
        if (std::islower(caractere))
        {
            caractere = std::toupper(caractere);

            file.seekp(-1, std::ios::cur); // Move o ponteiro de escrita para uma posição para trás.
            file.put(caractere);           // Sobrescreve o caractere convertido.
        }
    }

    return 0;
}

int main(int argc, char **argv)
{
    std::ofstream arq1;

    // ios::app - abre o arquivo no final (depois do último caractere)
    arq1.open("nomes.txt", std::ios::app);

    if (arq1.is_open())
    {
        long pos = arq1.tellp();
        std::cout << "Posição atual no arquivo: " << pos << '\n';

        // Insere nomes no final do arquivo (foi aberto com ios::app)
        arq1 << "Eduardo" << '\n';
        arq1 << "Vitór" << '\n';
        arq1.close();
    }
    else
    {
        std::cout << "ERRO: arquivo não foi aberto ou não existe" << '\n';
    }

    std::cout << "--------------------------------------\n";

    std::fstream file(argv[1], std::ios::in | std::ios::out);

    int status = upper_file(file);

    // Verifica o status da conversão
    if (status == 0)
    {
        std::cout << "O conteúdo do \"" << argv[1] << "\" arquivo foi convertido com sucesso" << '\n';
    }
    else
    {
        std::cout << "Falha na conversão" << '\n';
    }

    file.close();

    return 0;
}

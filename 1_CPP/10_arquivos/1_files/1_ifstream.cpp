#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    /**
     * std::ifstream(): Para leitura de arquivos, usada exclusivamente para ler dados
     * de um arquivo.
     */
    std::ifstream arquivo("exemplo.txt");

    if (arquivo.is_open())
    {
        std::string linha;

        while (std::getline(arquivo, linha))
        {
            std::cout << "Conteúdo lido para arquivo " << linha << '\n';
        }
        arquivo.close();
    }
    else
    {
        std::cerr << "Error ao abrir o arquivo";
    }

    std::cout << "--------------------------------------" << '\n';

    /**
     * std::ios::binary: Tanto para leitura quanto para escrita para arquivos ".bin".
     *
     * O modo binário não faz qualquer tipo de conversão de texto (como a conversão de
     * quebras de linha ou conversão de caracteres), e os dados são manipulados como
     * sequência de bytes.
     */
    std::ifstream input_file("arquivo.bin", std::ios::binary);

    if (!input_file)
    {
        std::cerr << "Erro ao abrir o arquivo!" << '\n';
        return 1;
    }

    int numero = 0;
    input_file.read(reinterpret_cast<char *>(&numero), sizeof(numero));

    std::cout << "O número lido foi: " << numero << '\n';
    input_file.close();

    return 0;
}

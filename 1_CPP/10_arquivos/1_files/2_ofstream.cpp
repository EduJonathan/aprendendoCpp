#include <iostream>
#include <fstream>

struct Pessoa
{
    char nome[50];
    int idade;
};

int main(int argc, char **argv)
{
    /**
     * std::ofstream(): Para escrita em arquivos, exclusivamente para escrever dados em um arquivo.
     */
    std::ofstream arquivoSaida("Arquivo.txt");

    if (arquivoSaida.is_open())
    {
        arquivoSaida << "Olá!" << '\n';
        arquivoSaida.close();
    }
    else
    {
        std::cerr << "Erro ao abrir o arquivo para escrita";
    }

    std::cout << "--------------------------------------" << '\n';

    std::ofstream output_file("arquivo.bin", std::ios::binary);

    if (!output_file)
    {
        std::cerr << "Erro ao abrir o arquivo!" << '\n';
        return 1;
    }

    int numero = 12345;

    // Escreve o valor de "numero" como bytes
    output_file.write(reinterpret_cast<char *>(&numero), sizeof(numero));
    output_file.close();

    std::cout << "--------------------------------------" << '\n';

    Pessoa p = {"João", 30};

    // Escreve a estrutura Pessoa em formato binário
    std::ofstream output_file("pessoa.bin", std::ios::binary);

    if (!output_file)
    {
        std::cerr << "Erro ao abrir o arquivo para escrita!" << '\n';
        return 1;
    }

    output_file.write(reinterpret_cast<char *>(&p), sizeof(p));
    output_file.close();

    // Lê a estrutura Pessoa de volta do arquivo
    std::ifstream input_file("pessoa.bin", std::ios::binary);

    if (!input_file)
    {
        std::cerr << "Erro ao abrir o arquivo para leitura!" << '\n';
        return 1;
    }

    Pessoa p2 = {0};
    input_file.read(reinterpret_cast<char *>(&p2), sizeof(p2));
    input_file.close();

    std::cout << "Nome: " << p2.nome << ", Idade: " << p2.idade << '\n';

    return 0;
}

#include <iostream>
#include <iomanip>
#include <fstream>

/**
 * std::ios::binary: Tanto para leitura quanto para escrita para arquivos ".bin".
 *
 * O modo binário não faz qualquer tipo de conversão de texto (como a conversão de
 * quebras de linha ou conversão de caracteres), e os dados são manipulados como
 * sequência de bytes.
 */

struct Pessoa
{
    char nome[50];
    int idade;
};

/**
 * @brief Compara dois arquivos binários byte a byte.
 *
 * Lê os dois arquivos simultaneamente e verifica se possuem o mesmo conteúdo
 * e tamanho. Caso encontre uma diferença, mostra a posição e o valor hexadecimal
 * dos bytes distintos.
 *
 * @param arquivo1 Primeiro arquivo binário aberto (`std::ifstream`).
 * @param arquivo2 Segundo arquivo binário aberto (`std::ifstream`).
 * @return `true` se os arquivos forem idênticos, `false` caso contrário.
 *
 * @note Ambos os arquivos devem ser abertos com `std::ios::binary`.
 */
bool comparar_dois_arquivos_binarios(std::ifstream &arquivo1, std::ifstream &arquivo2)
{
    if (!arquivo1.is_open() || !arquivo2.is_open())
    {
        std::cerr << "Erro: Um ou ambos os arquivos não estão abertos.\n";
        return false;
    }

    char caractere1 = '\0';
    char caractere2 = '\0';
    std::size_t position = 0;
    bool sao_iguais = true;

    while (arquivo1.get(caractere1) && arquivo2.get(caractere2))
    {
        position++;
        if (caractere1 != caractere2)
        {
            sao_iguais = false;
            std::cout << "Os arquivos diferem na posição " << position
                      << ": arquivo1 = 0x" << std::hex << std::setw(2) << std::setfill('0')
                      << (unsigned int)(unsigned char)caractere1
                      << ", arquivo2 = 0x" << std::hex << std::setw(2) << std::setfill('0')
                      << (unsigned int)(unsigned char)caractere2 << "\n";
            break;
        }
    }

    if (sao_iguais && arquivo1.eof() != arquivo2.eof())
    {
        sao_iguais = false;
        std::cout << "Os arquivos têm tamanhos diferentes: "
                  << (arquivo1.eof() ? "arquivo1 terminou primeiro" : "arquivo2 terminou primeiro")
                  << " na posição " << position << "\n";
    }

    if (sao_iguais)
    {
        std::cout << "Os dois arquivos são iguais!\n";
    }

    return sao_iguais;
}

int main(int argc, char **argv)
{
    // Exemplo 1: Escreva um número inteiro no arquivo.bin
    std::ofstream outputFileBinary("arquivo.bin", std::ios::binary);
    if (!outputFileBinary)
    {
        std::cerr << "Erro ao abrir o arquivo para escrita!\n";
        return 1;
    }

    int numero = 12345;
    outputFileBinary.write(reinterpret_cast<const char *>(&numero), sizeof(numero));
    outputFileBinary.close();

    std::cout << "Escreveu o número " << numero << " em arquivo.bin\n";
    std::cout << "--------------------------------------\n";

    // Exemplo 2: Leia o número inteiro do arquivo.bin
    std::ifstream input_file("arquivo.bin", std::ios::binary);
    if (!input_file)
    {
        std::cerr << "Erro ao abrir o arquivo para leitura!\n";
        return 1;
    }

    int number = 0;
    input_file.read(reinterpret_cast<char *>(&number), sizeof(number));
    if (!input_file)
    {
        std::cerr << "Erro ao ler os dados do arquivo!\n";
        input_file.close();
        return 1;
    }

    std::cout << "O número lido foi: " << number << "\n";
    input_file.close();
    std::cout << "--------------------------------------\n";

    // Exemplo 3: Escreva uma estrutura Pessoa em pessoa.bin
    std::ofstream outFile("pessoa.bin", std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Erro ao abrir o arquivo para escrita!\n";
        return 1;
    }

    Pessoa p1 = {"Joao Silva", 30};
    outFile.write(reinterpret_cast<const char *>(&p1), sizeof(p1));
    outFile.close();

    // Exemplo 4: Leia a estrutura Pessoa a partir do arquivo pessoa.bin
    std::ifstream inFile("pessoa.bin", std::ios::binary);
    if (!inFile)
    {
        std::cerr << "Erro ao abrir o arquivo para leitura!\n";
        return 1;
    }

    Pessoa p2 = {0};
    inFile.read(reinterpret_cast<char *>(&p2), sizeof(p2));
    if (!inFile)
    {
        std::cerr << "Erro ao ler os dados do arquivo!\n";
        inFile.close();
        return 1;
    }
    inFile.close();

    std::cout << "Nome: " << p2.nome << ", Idade: " << p2.idade << "\n";
    std::cout << "--------------------------------------\n";

    // Exemplo 5: Comparando 2 arquivos binários
    std::ifstream arquivo1("file1.bin", std::ios::binary);
    std::ifstream arquivo2("file2.bin", std::ios::binary);
    if (!arquivo1 || !arquivo2)
    {
        std::cerr << "Erro ao abrir um ou ambos os arquivos para comparação.\n";
        return 1;
    }

    bool sao_iguais = comparar_dois_arquivos_binarios(arquivo1, arquivo2);
    arquivo1.close();
    arquivo2.close();

    return sao_iguais ? 0 : 1;
}

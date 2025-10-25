#include <iostream>
#include <iomanip>
#include <bitset>
#include <fstream>

/**
 * @brief Função que verfica se o caractere é printável
 *
 * A função caractere_printavel recebe um caractere como entrada e retorna um valor booleano indicando
 * se o caractere é imprimível. Ela verifica se o valor ASCII do caractere está dentro do intervalo de 32 a 255, inclusive.
 *
 * @param caractere Caractere a verificar.
 */
bool caractere_printavel(char caractere)
{
    return (caractere >= 32 && caractere <= 255);
}

int main(int argc, char **argv)
{
    // std::ofstream(): Para escrita em arquivos, exclusivamente para escrever dados em um arquivo,
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

    std::ofstream out_file("nomes.txt");
    if (!out_file.is_open())
    {
        std::cerr << "Erro na abertura do arquivo";
    }

    out_file << "Bruno Gomes" << '\n';
    out_file << "Maria Dantas" << '\n';
    out_file.close();

    std::ofstream out_table_ascii("Ascii_table.txt");

    if (!out_table_ascii)
    {
        std::cerr << "Erro ao abrir o arquivo para escrita\n";
        return 1;
    }

    // Tabela ASCII header
    out_table_ascii << std::left << std::setw(16) << "BINÁRIO"
                    << " | " << std::setw(8) << "OCTAL"
                    << " | " << std::setw(10) << "HEXADECIMAL"
                    << " | " << std::setw(8) << "DECIMAL"
                    << " | " << "CARACTERE\n";

    out_table_ascii << std::string(60, '=') << '\n'; // Irá imprimir o caractere '=' 60 vezes

    for (int i = 0; i < 127; ++i)
    {
        char caracter = static_cast<char>(i);

        out_table_ascii << std::left << std::setw(16) << std::bitset<7>(i) << " | ";  // Valor binário
        out_table_ascii << std::setw(8) << std::oct << std::uppercase << i << " | ";  // Valor octal
        out_table_ascii << std::setw(10) << std::hex << std::uppercase << i << " | "; // Valor hexadecimal
        out_table_ascii << std::setw(8) << std::dec << i << " | ";                    // Valor decimal

        // Caractere
        if (caractere_printavel(caracter))
        {
            out_table_ascii << caracter;
        }
        else
        {
            out_table_ascii << "Não Há Valor";
        }

        out_table_ascii << '\n';
    }

    out_table_ascii.close();

    return 0;
}

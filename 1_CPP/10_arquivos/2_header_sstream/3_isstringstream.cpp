#include <iostream>
#include <iomanip>
#include <bitset>
#include <cctype>
#include <string>
#include <sstream>

// classe std::istringstream: Usa-se para ler dados de uma string (como um fluxo de entrada).

/**
 * @brief Converte uma string numérica (bin, oct, dec, hex) para decimal.
 *
 * @param input Valor de entrada em formato de string.
 * @param value Referência para armazenar o valor convertido.
 * @return true se a conversão for bem-sucedida, false caso contrário.
 */
bool parseInput(const std::string &input, long &value)
{
    std::istringstream iss(input);

    if (input.substr(0, 2) == "0x" || input.substr(0, 2) == "0X")
        iss >> std::hex >> value; // Hexadecimal
    else if (input.substr(0, 2) == "0b" || input.substr(0, 2) == "0B")
    {
        try
        {
            value = std::stol(input.substr(2), nullptr, 2); // Binário
        }
        catch (...)
        {
            return false;
        }
    }
    else if (input[0] == '0' && input.length() > 1 && std::isdigit(input[1]))
        iss >> std::oct >> value; // Octal
    else
        iss >> value; // Decimal

    return !iss.fail();
}

/**
 * @brief Converte para hexadecimal (0xXXXXXXXX).
 *
 * @param value Valor decimal.
 * @return String em formato hexadecimal.
 */
std::string toHex(long value)
{
    std::ostringstream oss;
    oss << "0x" << std::hex << std::uppercase
        << std::setw(8) << std::setfill('0') << value;
    return oss.str();
}

/**
 * @brief Converte para octal (00000000000).
 *
 * @param value Valor decimal.
 * @return String em formato octal.
 */
std::string toOct(long value)
{
    std::ostringstream oss;
    oss << '0' << std::oct
        << std::setw(11) << std::setfill('0') << value;
    return oss.str();
}

/**
 * @brief Converte para binário (0b...).
 *
 * @param value Valor decimal.
 * @return String em formato binário.
 */
std::string toBin(long value)
{
    std::string binary = std::bitset<32>(value).to_string();
    std::size_t first_one = binary.find('1');
    return (first_one == std::string::npos) ? "0b0" : "0b" + binary.substr(first_one);
}

/**
 * @brief Exibe uma tabela com representações em várias bases.
 *
 * @param value Valor decimal.
 */
void printTable(long value)
{
    std::cout << "| REPRESENTAÇÃO  | VALOR                  |\n";
    std::cout << "|----------------|------------------------|\n";
    std::cout << "| Hexadecimal    | " << toHex(value) << " |\n";
    std::cout << "| Octal          | " << toOct(value) << " |\n";
    std::cout << "| Binário        | " << toBin(value) << " |\n";
}

int main(int argv, char **argc)
{
    std::string stringDeNumeros = "457";
    int converterParaNumero;

    // std::isstringstream para converter a string de numeros em um inteiro
    std::istringstream iss(stringDeNumeros);
    iss >> converterParaNumero;

    std::cout << "Números convertido: " << converterParaNumero << '\n';

    std::cout << "----------------------------------------\n";

    std::string dados{"Ana 30 60.40"}; // Nome, idade e peso
    std::string nome;

    int idade = 0;
    double peso = 0.0;

    // std::istringstream irá extrair os valores da string
    std::istringstream outputString(dados);
    outputString >> nome >> idade >> peso;

    std::cout << "Nome: " << nome << ", Idade: " << idade << ", Peso: " << peso << '\n';
    std::cout << "----------------------------------------\n";

    std::string input;
    long value = 0;

    // Solicita a entrada do usuário
    std::cout << "Digite um valor decimal, hexadecimal (ex.: 0xFF), octal (ex.: 0377) ou binário (ex.: 0b11111111): ";
    std::getline(std::cin, input);

    // Parseia a entrada
    if (!parseInput(input, value))
    {
        std::cerr << "Erro: Entrada inválida!" << '\n';
        return 1;
    }

    // Exibe o valor digitado em decimal
    std::cout << "\nValor digitado: " << value << "\n\n";

    // Exibe a tabela
    printTable(value);

    return 0;
}

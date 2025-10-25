#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

// std::osstringstream Usada para escrever dados em uma string(fluxo de dados em saída).

/**
 * @brief Converte um número inteiro para binário.
 *
 * @param value Valor inteiro sem sinal.
 * @return String contendo a representação binária.
 */
std::string toBinary(unsigned int value)
{
    std::string binary;
    if (value == 0)
        return "0";
    while (value > 0)
    {
        binary = (value % 2 == 0 ? "0" : "1") + binary;
        value /= 2;
    }
    return binary;
}

int main(int argc, char **agv)
{
    double pi = 3.14159;

    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << pi;
    std::string strPi = oss.str();

    std::cout << "O valor de pi formatado é: " << strPi << '\n';
    /*
     * Neste exemplo, usamos std::ostringstream para configurar a precisão da
     * conversão de ponto flutuante.
     */

    std::cout << "----------------------------------------\n";

    int numero = 123;
    std::string strNumeroConvertido;

    /* std::ostringstream para converter o inteiro em uma string */
    std::ostringstream outputString;
    outputString << numero;
    strNumeroConvertido = outputString.str();

    std::cout << "String convertida: " << strNumeroConvertido << '\n';
    std::cout << "----------------------------------------\n";

    std::cout << "Digite um valor (UNICODE ou ASCII, ex: U+1F30A ou 'A'): ";
    std::string input;
    std::getline(std::cin, input);

    unsigned int value = 0;
    if (input[0] == 'U' || input[0] == 'u')
    {
        // Entrada Unicode (ex: U+1F30A)
        std::string hexCode = input.substr(2); // Remove "U+"
        std::istringstream iss(hexCode);
        iss >> std::hex >> value;
    }
    else if (input.length() == 1)
    {
        // Entrada ASCII (ex: 'A')
        value = static_cast<unsigned int>(input[0]);
    }
    else
    {
        std::cout << "Entrada inválida!\n";
        return 1;
    }

    // Usando std::ostringstream para formatar as saídas
    std::ostringstream hexStream, octStream;
    hexStream << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << value;
    octStream << std::oct << std::setfill('0') << std::setw(3) << value;

    // Saída formatada
    std::cout << "Valor digitado: " << value << "\n\n";
    std::cout << "| REPRESENTAÇÃO | VALOR\n";
    std::cout << "|---------------|-------\n";
    std::cout << "| Hexadecimal   | " << hexStream.str() << '\n';
    std::cout << "| Octal         | " << octStream.str() << '\n';
    std::cout << "| Binário       | " << toBinary(value) << '\n';

    return 0;
}

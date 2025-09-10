#include <iostream>
#include <iomanip>
#include <sstream>

// std::osstringstream Usada para escrever dados em uma string(fluxo de dados em saída).

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
    return 0;
}

#include <iostream>
#include <string>
#include <sstream>

// classe std::istringstream: Usa-se para ler dados de uma string (como um fluxo de entrada).

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
    return 0;
}

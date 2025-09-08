#include <iostream>
#include <iomanip>
#include <fstream>

struct Ponto
{
    int x;
    int y;
};

/**
 * std::ostream: Base para operações de saída, geralmente usada com ofstream para
 * arquivos ou std::cout para a tela. Serve como a base para várias classes como ofstream,
 * ostringstream, etc., Usada para escrever dados no fluxo de saída.
 * Não é usada diretamente para arquivos, mas sim para fluxo de saída geral.
 */

void imprimeData(std::ostream &os, int dia, int mes, int ano)
{
    // Configurando para garantir dois dígitos para dia e mês e quatro dígitos para o ano
    os << std::setw(2) << std::setfill('0') << dia << '/'
       << std::setw(2) << std::setfill('0') << mes << '/'
       << std::setw(4) << std::setfill('0') << ano;
}

std::ostream &operator<<(std::ostream &os, const Ponto &p)
{
    return os << '(' << p.x << ", " << p.y << ')';
}

int main(int argc, char **argv)
{
    // Exemplo de uso da função imprimeData
    imprimeData(std::cout, 13, 04, 2025); // Saída: 03/04/2025

    std::cout << "\n------------------------" << '\n';

    std::ofstream arq("data.txt");
    if (arq)
    {
        imprimeData(std::cout, 3, 4, 2025); // Saída: 03/04/2025
    }

    std::cout << "\n------------------------" << '\n';

    Ponto point = {4, 5};
    std::cout << point;
    return 0;
}

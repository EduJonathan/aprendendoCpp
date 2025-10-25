#include <iostream>
#include <iomanip>
#include <fstream>
/** */

/**
 * std::ostream: Base para operações de saída, geralmente usada com ofstream para arquivos ou std::cout para a tela.
 * Serve como a base para várias classes como ofstream, ostringstream, etc.
 * Usada para escrever dados no fluxo de saída. Não é usada diretamente para arquivos, mas sim para fluxo de saída geral.
 */

struct Ponto
{
    int x;
    int y;
};

/**
 * @brief Imprime uma data formatada no fluxo de saída.
 *
 * @param os Stream de saída (ex: std::cout ou arquivo).
 * @param dia Dia do mês.
 * @param mes Mês.
 * @param ano Ano.
 *
 * @example
 * imprimeData(std::cout, 5, 9, 2025); // Saída: 05/09/2025
 */
void imprimeData(std::ostream &os, int dia, int mes, int ano)
{
    os << std::setw(2) << std::setfill('0') << dia << '/'
       << std::setw(2) << std::setfill('0') << mes << '/'
       << std::setw(4) << std::setfill('0') << ano;
}

/**
 * @brief Sobrecarga do operador << para imprimir um ponto.
 *
 * @param os Stream de saída.
 * @param p struct da classe Ponto.
 * @return Referência para o stream de saída.
 *
 * @example
 * Ponto p{3, 7};
 * std::cout << p; // Saída: (3, 7)
 */
std::ostream &operator<<(std::ostream &os, const Ponto &p)
{
    return os << '(' << p.x << ", " << p.y << ')';
}

int main(int argc, char **argv)
{
    // Exemplo de uso da função imprimeData, std::cout preenche o parâmetro std::ostream por ser padrão de saída.
    imprimeData(std::cout, 13, 04, 2025); // Saída: 01/04/2025

    std::cout << "\n------------------------" << '\n';

    std::ofstream arq("data.txt");
    if (arq)
    {
        imprimeData(std::cout, 3, 4, 2025); // Saída: 03/04/2025
    }

    std::cout << "\n------------------------" << '\n';

    Ponto point = {4, 5};

    // Devido a chamada do segundo parâmetro em std::ostream &operator<<, ele terá uma saída de fluxo de acordo com o retorno de std::ostream
    std::cout << point << '\n';
    return 0;
}

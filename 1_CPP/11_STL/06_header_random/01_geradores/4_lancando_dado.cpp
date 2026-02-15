#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <random>

/**
 * @brief Lê um número inteiro positivo.
 * 
 * @param mensagem Texto exibido ao usuário.
 * @return Número válido ou -1.
 */
int ler(const std::string &mensagem)
{
    std::string entrada;
    std::cout << mensagem;
    std::getline(std::cin, entrada);

    std::stringstream ss(entrada);
    int valor = 0;
    if (!(ss >> valor) || !ss.eof() || valor <= 0)
    {
        return -1;
    }
    return valor;
}

/**
 * @brief Pergunta se deseja continuar.
 * 
 * @return true para sim, false para não.
 */
bool continuar()
{
    std::string entrada;
    std::cout << "Deseja lançar o dado novamente? (s/n): ";
    std::getline(std::cin, entrada);

    std::transform(entrada.begin(), entrada.end(), entrada.begin(), [](unsigned char c)
    {
        return std::tolower(c);
    });

    return (entrada == "s" || entrada == "sim");
}

/**
 * @brief Exibe tabela simples com todos os lançamentos.
 *
 * @param resultados Vetor com os valores.
 * @param n Número de lados do dado.
 */
void exibir_tabela_simples(const std::vector<int> &resultados, int n)
{
    if (resultados.empty())
    {
        std::cout << "\nNenhum lançamento realizado.\n";
        return;
    }

    const int col1 = 12; // Largura da coluna "Lançamento"
    const int col2 = 10; // Largura da coluna "Resultado"

    std::cout << '\n';

    // Cabeçalho
    std::cout << "+-" << std::string(col1, '-') << "-+-" << std::string(col2, '-') << "-+\n";
    std::cout << "| Lançamento | Resultado |\n";
    std::cout << "+-" << std::string(col1, '-') << "-+-" << std::string(col2, '-') << "-+\n";

    // Linhas de dados
    for (std::size_t i = 0; i < resultados.size(); ++i)
    {
        std::cout << "| " << std::left << std::setw(col1) << i
                  << "| " << std::left << std::setw(col2) << resultados[i] << "|\n";
    }

    // Rodapé
    std::cout << "+-" << std::string(col1, '-') << "-+-" << std::string(col2, '-') << "-+\n";
    std::cout << "Dado: d" << n << " | Total de lançamentos: " << resultados.size() << '\n';
}

int main(int argc, char **argv)
{
    int n = 0;
    do
    {
        n = ler("Quantos lados tem o dado? ");
        if (n <= 0)
        {
            std::cout << "Erro: Insira um número maior que zero.\n";
        }
    } while (n <= 0);

    std::random_device rd;                         // Gerador de números aleatórios
    std::mt19937 gen(rd());                        // Motor Mersenne Twister
    std::uniform_int_distribution<> distrib(1, n); // Distribuição uniforme [1, n]

    std::vector<int> resultados;

    std::cout << "\nLançando dado d" << n << "...\n\n";

    do
    {
        int valor = distrib(gen);
        resultados.push_back(valor);
        std::cout << "Lançamento " << (resultados.size() - 1)
                  << " → " << valor << " (d" << n << ")\n";
    } while (continuar());

    // Exibe tabela simples
    exibir_tabela_simples(resultados, n);

    std::cout << "\nPrograma encerrado. Até logo!\n";
    return 0;
}

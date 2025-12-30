#include <iostream>
#include <iomanip>
#include <array>

/**
 * Apesar de não existir uma implementação direta para matrizes (arrays bidimensionais)
 * na STL (Standard Template Library), podemos utilizar std::array para criar
 * uma matriz de forma mais segura e moderna.
 *
 * A estrutura: std::array<std::array<datatype, Colunas>, Linhas>
 * - O array mais interno define a Coluna (ou seja, o tipo de cada linha).
 * - O array mais externo define a Linha (ou seja, a quantidade de linhas).
 */

int main(int argc, char **argv)
{
    // Matriz com representação mais moderna utilizando com std::array (C++11)
    std::cout << "\tMatriz com std::array" << '\n';
    std::cout << "---------------------------------" << '\n';

    // Definindo uma matriz 3x3 usando std::array e valores já definidos
    // A sintaxe com chaves aninhadas '{{...}, {...}, {...}}' é essencial.
    std::array<std::array<double, 3>, 3> matriz_moderna{
        {{1.1, 1.2, 1.3},
         {2.1, 2.2, 2.3},
         {3.1, 3.2, 3.3}}};

    // Modificando elementos da matriz_moderna
    std::cout << "Modificando: Incrementando cada elemento em 1.0" << '\n';
    for (std::size_t i = 0ull; i < matriz_moderna.size(); ++i) // Percorre as Linhas
    {
        for (std::size_t j = 0ull; j < matriz_moderna[i].size(); ++j) // Percorre as Colunas
        {
            // Usamos o operator[] para acesso eficiente (sem verificação de limites)
            matriz_moderna[i][j] += 1.0;
        }
    }

    std::cout << "---------------------------------" << '\n';

    std::cout << "Matriz 3x3 (após incremento):" << '\n';

    // Exibindo a matriz usando loops baseados em intervalo (Range-based for loop)
    // O uso de std::setw(4) alinha a saída para melhor legibilidade.
    std::cout << std::fixed << std::setprecision(1); // Garante 1 casa decimal

    for (const auto &linha : matriz_moderna)
    {
        for (const auto &elemento : linha)
        {
            std::cout << '\t' << std::setw(4) << elemento;
        }
        std::cout << '\n';
    }

    std::cout << "---------------------------------" << '\n';

    // 1. Definição da Matriz (4 linhas, 4 colunas de inteiros)
    // std::array<Linhas, Colunas>
    // A inicialização padrão com '{}' garante que todos os elementos comecem com 0.
    std::array<std::array<int, 4>, 4> matriz_dinamica = {};

    std::cout << "\tMatriz Dinâmica com std::array (Preenchimento)" << '\n';
    std::cout << "------------------------------------------------" << '\n';

    // 2. Preenchimento da Matriz (Utilizando .size() para segurança)
    std::cout << "Dimensões: "
              << matriz_dinamica.size() << " linhas x "
              << matriz_dinamica[0].size() << " colunas" << '\n';

    for (std::size_t i = 0; i < matriz_dinamica.size(); ++i) // Percorre as Linhas (i)
    {
        for (std::size_t j = 0; j < matriz_dinamica[i].size(); ++j) // Percorre as Colunas (j)
        {
            // O valor é calculado: (Índice da Linha * 10) + Índice da Coluna
            // Exemplo: Elemento [2][3] será preenchido com (2 * 10) + 3 = 23
            matriz_dinamica[i][j] = static_cast<int>(i * 10 + j);
        }
    }

    // 3. Exibição da Matriz (Utilizando loops Range-based for)
    std::cout << "------------------------------------------------" << '\n';
    std::cout << "Matriz 4x4 Preenchida:" << '\n';

    // Configura a largura da saída para 3 caracteres, alinhando visualmente
    for (const auto &linha : matriz_dinamica)
    {
        for (const auto &elemento : linha)
        {
            std::cout << std::setw(3) << elemento;
        }
        std::cout << '\n';
    }

    std::cout << "------------------------------------------------" << '\n';
    return 0;
}

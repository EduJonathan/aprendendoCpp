#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

/**
 * A header <random> foi introduzida no C++11 para fornecer um sistema completo
 * de geração de números aleatórios, muito mais robusto e flexível do que o antigo rand() do C.
 *
 * Detalhes a header <algorithm> só tem funções que podem usar aleatoriedade (como shuffle)
 * quando você passa um motor, sendo assim, não fornecem geração direta de números aleatórios.
 */

const int LIN = 4, COL = 4;

void imprimir(const std::vector<std::vector<int>> &m)
{
    for (int i = 0; i < LIN; ++i)
    {
        for (int j = 0; j < COL; ++j)
            std::cout << std::setw(4) << m[i][j];
        std::cout << '\n';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    // 1. Gerar números aleatórios (0 .. 99)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);

    std::vector<std::vector<int>> mat(LIN, std::vector<int>(COL));
    for (int i = 0; i < LIN; ++i)
        for (int j = 0; j < COL; ++j)
            mat[i][j] = dis(gen);

    std::cout << "Matriz original:\n";
    imprimir(mat);

    // 2. Processar cada coluna
    for (int c = 0; c < COL; ++c)
    {
        std::vector<int> bons;  // divisíveis por 5 ou 7
        std::vector<int> ruins; // os demais

        for (int l = 0; l < LIN; ++l)
        {
            int v = mat[l][c];
            if (v % 5 == 0 || v % 7 == 0)
                bons.push_back(v);
            else
                ruins.push_back(v);
        }

        // 3. Reconstruir a coluna: bons(no caso divisíveis por 5 ou 7) no topo
        int pos = 0;
        for (int v : bons)
            mat[pos++][c] = v;
        for (int v : ruins)
            mat[pos++][c] = v;
    }

    std::cout << "Depois de \"subir\" os divisíveis por 5 ou 7:\n";
    imprimir(mat);

    return 0;
}

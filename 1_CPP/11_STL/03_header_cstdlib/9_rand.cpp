#include <iostream>
#include <climits>
#include <ctime>
#include <cstdlib>

// std::rand(): Para gerar valores aleatórios.

/* Função que irá gerar valores aleatórios entre 0 a 20, que sejam divisível por 2 ou 5 */
int gerarNumeroAleatorio(void)
{
    int number = 0;

    do
    {
        number = std::rand() % 21;
    } while ((number % 2 != 0) && (number % 5 != 0));
    return number;
}

int main(int argc, char **argv)
{
    std::srand(std::time(NULL));
    std::cout << "RANGE DE RAND_MAX" << RAND_MAX << '\n'
              << "RANGE DE INT_MAX" << INT_MAX << '\n'
              << "Valores aleatórios de [0, 1]: "
              << static_cast<double>(std::rand()) / RAND_MAX << '\n';

    std::cout << "----------------------------------------------------" << '\n';

    std::srand(std::time(0)); /* Inicializa o gerador de números aleatórios com o tempo atual */

    int linhas = 5, colunas = 5; /* Linhas e colunas da matriz */
    int matriz[linhas][colunas]; /* Matriz de inteiros. */

    /* Preenche a matriz com números divisíveis por 2 ou 5 */
    for (int i = 0; i < linhas; ++i)
    {
        for (int j = 0; j < colunas; ++j)
        {
            matriz[i][j] = gerarNumeroAleatorio();
        }
    }

    /* Imprime matriz */
    for (int i = 0; i < linhas; ++i)
    {
        for (int j = 0; j < colunas; ++j)
        {
            std::cout << matriz[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}

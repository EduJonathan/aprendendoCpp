#include <iostream>

class Matriz
{
private:
    int matriz[3][3];

public:
    // Função para criar a matriz (inicializar com zeros)
    void criarMatriz(int l, int c)
    {
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                matriz[i][j] = 0;
            }
        }
    }

    // Função para adicionar valores alternados na matriz
    void adicionarValores(void)
    {
        int valor1 = 1;
        int valor2 = 2;

        // Preenche a matriz com valores alternados entre valor1 e valor2
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if ((i + j) % 2 == 0)
                {
                    matriz[i][j] = valor1;
                }
                else
                {
                    matriz[i][j] = valor2;
                }
            }
        }
    }

    // Função para exibir a matriz
    void exibir(void)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::cout << matriz[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }
};

int main(int argc, char **argv)
{
    Matriz m1;
    m1.criarMatriz(3, 3); // Criando a matriz

    // Preenchendo a matriz m1 com valores alternados entre 1 e 2
    m1.adicionarValores();

    std::cout << "Matriz 1:" << '\n';
    m1.exibir(); // Exibindo a matriz

    return 0;
}

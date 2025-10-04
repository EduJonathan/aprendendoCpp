#include <iostream>
#include <new>

class Matriz
{
private:
    int linhas;
    int colunas;
    int **matriz;

public:
    void criarMatriz(int l, int c)
    {
        linhas = l;
        colunas = c;
        matriz = new int *[linhas];

        for (int i = 0; i < linhas; ++i)
        {
            matriz[i] = new int[colunas];
        }
    }

    // Método para preencher a matriz com um valor específico em uma posição (linha, coluna)
    void preencherMatriz(int indice, int linha, int coluna, int valor)
    {
        if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas)
        {
            std::cout << "Índice fora dos limites da matriz." << '\n';
            return;
        }
        matriz[linha][coluna] = valor;
    }

    // Método para adicionar valores alternados entre valor1 e valor2
    void adicionarValores(int valor1, int valor2)
    {
        for (int i = 0; i < linhas; ++i)
        {
            for (int j = 0; j < colunas; ++j)
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

    void somarLinhas(const Matriz &m)
    {
        if (linhas != m.linhas || colunas != m.colunas)
        {
            std::cout << "As matrizes devem ter o mesmo tamanho para serem somadas." << '\n';
            return;
        }

        for (int i = 0; i < linhas; ++i)
        {
            for (int j = 0; j < colunas; ++j)
            {
                matriz[i][j] += m.matriz[i][j];
            }
        }
    }

    void subtrairDiagonalPrincipal(const Matriz &m)
    {
        if (linhas != m.linhas || colunas != m.colunas)
        {
            std::cout << "As matrizes devem ter o mesmo tamanho." << '\n';
            return;
        }

        for (int i = 0; i < linhas && i < colunas; ++i)
        {
            matriz[i][i] -= m.matriz[i][i];
        }
    }

    void exibir(void)
    {
        for (int i = 0; i < linhas; ++i)
        {
            for (int j = 0; j < colunas; ++j)
            {
                std::cout << matriz[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    // Para liberar memória alocada da matriz
    ~Matriz()
    {
        for (int i = 0; i < linhas; ++i)
        {
            delete[] matriz[i];
        }
        delete[] matriz;
    }
};

int main(int argc, char **argv)
{
    Matriz m1;
    m1.criarMatriz(3, 3); // Criando a matriz 3x3

    // Preenchendo a matriz m1 com valores alternados entre 1 e 2
    m1.adicionarValores(1, 2);
    std::cout << "Matriz 1 após preenchimento inicial:\n";
    m1.exibir();

    // Criando a segunda matriz m2
    Matriz m2;
    m2.criarMatriz(3, 3);
    m2.adicionarValores(3, 4);

    std::cout << "Matriz 2:\n";
    m2.exibir();

    // Modificando m1 usando o método preencherMatriz
    m1.preencherMatriz(0, 0, 0, 99); // Mudando a posição (0, 0) para 99
    std::cout << "Matriz 1 após modificação na posição (0, 0):\n";
    m1.exibir();

    // Somando as linhas de m1 com m2
    m1.somarLinhas(m2);
    std::cout << "Após somar linhas de m1 com m2:\n";
    m1.exibir();

    // Subtraindo as diagonais principais de m1 com m2
    m1.subtrairDiagonalPrincipal(m2);
    std::cout << "Após subtrair as diagonais principais:\n";
    m1.exibir();

    return 0;
}

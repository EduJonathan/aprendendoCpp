#include <iostream>
#include <new>
#include <stdexcept>

class Matriz
{
public:
    std::size_t linhas;  // Numero de linhas
    std::size_t colunas; // Numero de colunas
    int **matriz;        // array Dinamicamente alocado 2D

    // Initialize matrix members
    void init()
    {
        linhas = 0;
        colunas = 0;
        matriz = nullptr;
    }

    // Criar a matriz com dimensões especificadas
    void criarMatriz(std::size_t l, std::size_t c)
    {
        if (l == 0 || c == 0)
        {
            throw std::invalid_argument("Dimensões da matriz devem ser positivas.");
        }

        // Liberar a matriz existente, se houver
        for (std::size_t i = 0; i < linhas; ++i)
        {
            delete[] matriz[i];
        }
        delete[] matriz;

        linhas = l;
        colunas = c;
        
        try
        {
            matriz = new int *[linhas];
            for (std::size_t i = 0; i < linhas; ++i)
            {
                matriz[i] = new int[colunas](); // Inicializa com zeros
            }
        }
        catch (const std::bad_alloc &)
        {
            linhas = 0;
            colunas = 0;
            matriz = nullptr;
            throw std::runtime_error("Falha na alocação de memória.");
        }
    }

    // Preencher a matriz com valores alternados
    void adicionarValores(int valor1, int valor2)
    {
        if (!matriz)
        {
            throw std::runtime_error("Matriz não está inicializada.");
        }
        for (std::size_t i = 0; i < linhas; ++i)
        {
            for (std::size_t j = 0; j < colunas; ++j)
            {
                matriz[i][j] = (i + j) % 2 == 0 ? valor1 : valor2;
            }
        }
    }

    // Preencher um valor específico na matriz
    void preencherMatriz(std::size_t linha, std::size_t coluna, int valor)
    {
        if (!matriz)
        {
            throw std::runtime_error("Matriz não está inicializada.");
        }
        if (linha >= linhas || coluna >= colunas)
        {
            throw std::out_of_range("Índice fora dos limites.");
        }
        matriz[linha][coluna] = valor;
    }

    // Somar a matriz com outra matriz
    Matriz &somarLinhas(const Matriz &m)
    {
        if (!matriz || !m.matriz)
        {
            throw std::runtime_error("Um ou ambas as matrizes não estão inicializadas.");
        }
        if (linhas != m.linhas || colunas != m.colunas)
        {
            throw std::invalid_argument("Matrizes devem ter as mesmas dimensões.");
        }
        for (std::size_t i = 0; i < linhas; ++i)
        {
            for (std::size_t j = 0; j < colunas; ++j)
            {
                matriz[i][j] += m.matriz[i][j];
            }
        }
        return *this;
    }

    // Subtrair a diagonal principal de outra matriz
    Matriz &subtrairDiagonalPrincipal(const Matriz &m)
    {
        if (!matriz || !m.matriz)
        {
            throw std::runtime_error("Um ou ambas as matrizes não estão inicializadas.");
        }
        if (linhas != m.linhas || colunas != m.colunas)
        {
            throw std::invalid_argument("Matrizes devem ter as mesmas dimensões.");
        }
        for (std::size_t i = 0; i < linhas && i < colunas; ++i)
        {
            matriz[i][i] -= m.matriz[i][i];
        }
        return *this;
    }

    // Exibir a matriz
    void exibir() const
    {
        if (!matriz)
        {
            std::cout << "Matriz está vazia.\n";
            return;
        }
        for (std::size_t i = 0; i < linhas; ++i)
        {
            for (std::size_t j = 0; j < colunas; ++j)
            {
                std::cout << matriz[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

    // Liberar a memória alocada
    void liberar()
    {
        for (std::size_t i = 0; i < linhas; ++i)
        {
            delete[] matriz[i];
        }
        delete[] matriz;
        matriz = nullptr;
        linhas = 0;
        colunas = 0;
    }
};

int main(int argc, char **argv)
{
    try
    {
        Matriz matriz1;
        matriz1.init();            // Inicialização explícita
        matriz1.criarMatriz(3, 3); // Criar uma matriz 3x3
        matriz1.adicionarValores(1, 2);
        std::cout << "Matriz 1 após preenchimento inicial:\n";
        matriz1.exibir();

        Matriz matriz2;
        matriz2.init();
        matriz2.criarMatriz(3, 3);
        matriz2.adicionarValores(3, 4);
        std::cout << "\nMatriz 2:\n";
        matriz2.exibir();

        matriz1.preencherMatriz(0, 0, 99);
        std::cout << "\nMatriz 1 após modificação na posição (0, 0):\n";
        matriz1.exibir();

        matriz1.somarLinhas(matriz2);
        std::cout << "\nApós somar linhas de matriz1 com matriz2:\n";
        matriz1.exibir();

        matriz1.subtrairDiagonalPrincipal(matriz2);
        std::cout << "\nApós subtrair as diagonais principais:\n";
        matriz1.exibir();

        // Liberar a memória alocada
        matriz1.liberar();
        matriz2.liberar();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
        return 1;
    }
    return 0;
}

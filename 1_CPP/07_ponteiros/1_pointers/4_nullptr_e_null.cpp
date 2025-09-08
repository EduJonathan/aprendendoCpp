#include <iostream>
#include <array>
#include <new>

/**
 * @brief Função que apenas imprime uma mensagem indicando que foi chamada.
 *
 * @param ptr Ponteiro para um inteiro (não é utilizado na função).
 */
void funcao(int *ptr)
{
    std::cout << (ptr == NULL ? "ptr é NULL\n" : "ptr não é NULL\n");
    std::cout << (ptr == nullptr ? "ptr é nullptr\n" : "ptr não é nullptr\n");
}

/**
 * @brief Função para alocar memória dinamicamente para um vetor de inteiros.
 *
 * @param vetorInteiros Ponteiro para o vetor de inteiros.
 * @param size Tamanho do vetor a ser alocado.
 * @return Ponteiro para o vetor de inteiros alocado.
 */
int *alocarInteiros(int *vetorInteiros, std::size_t size)
{
    if (vetorInteiros != NULL)
    {
        delete[] vetorInteiros;
    }

    int *novoVetor = new int[size];

    if (novoVetor == NULL)
    {
        std::cerr << "Falha na alocação de memória!" << '\n';
        exit(EXIT_FAILURE);
    }
    return novoVetor;
}

/**
 * @brief Função para alocar e preencher um vetor de caracteres com letras de 'a' a 'z'.
 *
 * @return std::array<char, 26> Vetor preenchido com letras de 'a' a 'z'.
 */
std::array<char, 26> AlocarCaracteres()
{
    std::array<char, 26> vetorCaracteres;

    for (std::size_t i = 0ull; i < vetorCaracteres.size(); ++i)
    {
        vetorCaracteres[i] = 'a' + static_cast<char>(i); // letras de 'a' a 'z'
    }

    std::cout << "Array preenchido com sucesso!\n";
    return vetorCaracteres;
}

int main(int argc, char **argv)
{
    funcao(NULL);    // Chama a função com NULL
    funcao(nullptr); // Chama a função com nullptr

    std::cout << "-----------------------------------------------\n";

    int *vetorInteiros = NULL;
    vetorInteiros = alocarInteiros(vetorInteiros, 10); // Aloca memória para 10 inteiros

    // Preenche o vetor com valores de 1 a 10
    for (int i = 0; i < 10; ++i)
    {
        vetorInteiros[i] = i + 1; // Preenche o vetor com valores 1 a 10
    }

    // Exibe os valores do vetor
    std::cout << "Elementos do vetor: ";
    for (int i = 0; i < 10; ++i)
    {
        std::cout << vetorInteiros[i] << ' '; // Exibe os valores do vetor
    }
    std::cout << '\n';

    // Libera a memória alocada para evitar vazamento
    delete[] vetorInteiros;

    std::cout << "-----------------------------------------------\n";

    std::array<char, 26> meuVetor = AlocarCaracteres();

    for (char c : meuVetor)
    {
        std::cout << c << ' ';
    }
    std::cout << '\n';

    // Não é necessário liberar memória, o std::array é gerenciado automaticamente
    // A memória estática no stack, é liberada automaticamente

    /**
     * NULLPTR: É preferido em C++ moderno (C++11 e posterior) por ser mais seguro
     * e evitar ambiguidades. nullptr denota o ponteiro literal, garantindo segurança
     * de tipo. Isso significa que ele não pode ser implicitamente convertido em um
     * inteiro, o que ajuda a evitar problemas de ambiguidade em funções sobrecarregadas
     * ou em expressões mais complexas (como classes derivadas, templates ou funções lambda).
     *
     * NULL: Ainda pode ser usado, especialmente em código legado, mas é menos seguro
     * que nullptr. NULL é uma macro tradicional de C/C++ (geralmente definida como
     * 0 em C++, ou ((void*)0) em C), que representa um ponteiro nulo geralmente um
     * macro definido como 0..
     *
     * @note Ambos têm o mesmo propósito: representar um ponteiro nulo. O nullptr tem a
     * vantagem de ser mais seguro, evitar ambiguidades e ser próprio da linguagem C++,
     * enquanto o NULL oferece maior compatibilidade com código legado em C e C++.
     */

    return 0;
}

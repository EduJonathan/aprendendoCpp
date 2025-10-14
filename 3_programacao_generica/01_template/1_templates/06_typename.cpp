#include <iostream>
#include <new>
#include <string>
#include <chrono>
#include <unordered_map>

/**
 * @brief Classe Array que armazena um array dinâmico e oferece funcionalidades
 * de manipulação e exibição.
 *
 * @tparam T Tipo dos elementos armazenados no array.
 *
 * @note Em C++, typename é usada para indicar que um determinado nome (ou tipo)
 * é um tipo dependente de um parâmetro de template. Isso é necessário porque,
 * em alguns contextos, o compilador não consegue determinar se uma variável ou
 * tipo é uma classe, tipo primitivo ou outra coisa, sem a ajuda da palavra-chave typename.
 */
template <typename T>
class Array
{
private:
    T *array;         // Ponteiro para o array dinamicamente alocado.
    std::size_t size; // Tamanho do array.

public:
    /**
     * @brief Construtor da classe Array.
     *
     * @param arr Array de entrada de tipo T que será copiado para o array interno.
     * @param tam Tamanho do array.
     */
    Array(T *arr, std::size_t tam)
    {
        array = new T[tam]; // Aloca memória para o array.
        size = tam;         // Define o tamanho do array.

        for (std::size_t i{0}; i < size; ++i)
        {
            array[i] = arr[i]; // Copia os elementos do array passado como parâmetro.
        }
    }

    /**
     * @brief Destrutor da classe Array.
     *
     * Libera a memória alocada dinamicamente para o array.
     */
    ~Array()
    {
        delete[] array;
    }

    /// @brief Imprime todos os elementos do array.
    void printArray(void)
    {
        for (std::size_t i{0}; i < size; ++i)
        {
            std::cout << i << "º Elemento: " << array[i] << '\n';
        }
    }
};

int contador_recursivo = 0; // Variável global para contar chamadas recursivas.

/**
 * @brief Função recursiva que calcula o n-ésimo número de Fibonacci.
 *
 * @param n O índice do número de Fibonacci a ser calculado.
 * @return O n-ésimo número de Fibonacci.
 */
long fibonacci(long n)
{
    contador_recursivo++; // Incrementa o contador a cada chamada da função.

    if (n <= 1)
        return n; // Retorna n se for 0 ou 1.

    return fibonacci(n - 1) + fibonacci(n - 2); // Chamada recursiva para calcular o Fibonacci.
}

/**
 * @brief Função iterativa que calcula o n-ésimo número de Fibonacci.
 *
 * @param n O índice do número de Fibonacci a ser calculado.
 * @return O n-ésimo número de Fibonacci.
 */
long fibonnaci_iterativo(long n)
{
    contador_recursivo++; // Incrementa o contador a cada chamada da função.

    if (n <= 1)
        return n; // Retorna n se for 0 ou 1.

    long a = 0l, b = 1l;

    for (int i = 2; i <= n; ++i)
    {
        long temp = a + b;
        a = b;    // Atualiza b para o próximo número de Fibonacci.
        b = temp; // Atualiza a para o número anterior.
    }

    return b; // Retorna o n-ésimo número de Fibonacci.
}

int contador_memoizado = 0;           // Variável global para contar chamadas recursivas.
std::unordered_map<long, long> cache; // Mapa para armazenar resultados já calculados.

/**
 * @brief Função que vai calcular o fibonacci de forma memoizada.
 *
 * @param n O índice do número de Fibonacci a ser calculado.
 * @return O n-ésimo número de Fibonacci.
 */
long fibonacci_memoizado(long n)
{
    contador_memoizado++; // Incrementa o contador a cada chamada da função.

    if (n <= 1)
        return n;

    if (cache.find(n) != cache.end())
        return cache[n]; // Retorna o resultado se já estiver no cache.

    // Armazena o resultado no cache.
    cache[n] = fibonacci_memoizado(n - 1) + fibonacci_memoizado(n - 2);

    // Retorna o resultado calculado.
    return cache[n];
}

template <typename TFuncao>
void medir_tempo(TFuncao funcao, int n, const std::string &nome)
{
    auto inicio = std::chrono::high_resolution_clock::now();                            // Marca o início do tempo.
    auto fim = std::chrono::high_resolution_clock::now();                               // Marca o fim do tempo.
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio); // Calcula a duração.
    int resultado = funcao(n);                                                          // Chama a função passada como parâmetro.

    std::cout << "\nMetodo: " << nome << '\n';
    std::cout << "Fibonacci(" << n << ") = " << resultado << '\n';
    std::cout << "Tempo de execução de " << nome << ": " << duracao.count() << " microsegundos\n";

    if (nome == "Recursivo Puro")
    {
        std::cout << "Contador recursivo: " << contador_recursivo << '\n';
    }
    else if (nome == "Memoizado")
    {
        std::cout << "Contador memoizado: " << contador_memoizado << '\n';
    }
    else
    {
        std::cout << "Chamadas recursivas: 0 (iterativo) " << '\n';
    }
}

int main(int argc, char **argv)
{
    int arr[5] = {1, 2, 3, 4, 5};

    Array<int> array(arr, 5); // Cria um objeto Array do tipo int com os elementos do array.
    array.printArray();       // Chama o método print para exibir os elementos do array.

    std::cout << "---------------------------------" << '\n';

    long n = 0l; // Variável para armazenar o número de Fibonacci a ser calculado.

    std::cout << "Digite um valor para calcular o Fibonacci: ";
    std::cin >> n;

    // Reinicia os contadores para cada método.
    contador_recursivo = 0;
    contador_memoizado = 0;
    cache.clear(); // Limpa o cache para evitar resultados acumulados.

    medir_tempo(fibonacci, n, "Recursivo Puro");      // Mede o tempo do método recursivo puro.
    medir_tempo(fibonnaci_iterativo, n, "Iterativo"); // Mede o tempo do método iterativo.
    medir_tempo(fibonacci_memoizado, n, "Memoizado"); // Mede o tempo do método memoizado.
    return 0;
}

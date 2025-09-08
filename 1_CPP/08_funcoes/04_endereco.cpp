#include <iostream>
#include <vector>
#include <algorithm>

/**
 * @brief Função que retorna o número com maior frequência
 *
 * @param numeros Vetor de números
 * @param quantidade Quantidade de números no vetor
 *
 * @note Com o ponteiro '*' passa-se o endereço de memória da variável, e deve-se usar
 * o operador de desreferência (*) dentro da função para acessar ou modificar o valor
 * da variável original, modificando o valor apontado pelo ponteiro.
 */
void frequenciaDeNumeros(int *numeros, std::size_t quantidade)
{
    // Cria um vetor para armazenar a frequência de cada número
    // O tamanho do vetor é arbitrário, por exemplo, assume que os números estão entre 0 e 9
    int maxNumero = 9;                          // Exemplo para números entre 0 e 9
    int *frequencia = new int[maxNumero + 1](); // Alocação dinâmica do vetor de frequências

    // Conta a frequência de cada número
    for (std::size_t i = 0ull; i < quantidade; ++i)
    {
        // Aumenta a contagem para o número específico
        frequencia[numeros[i]]++;
    }

    // Encontra o número com a maior frequência
    int numeroMaisFrequente = 0;
    int maiorFrequencia = 0;

    for (int i = 0; i <= maxNumero; ++i)
    {
        if (frequencia[i] > maiorFrequencia)
        {
            maiorFrequencia = frequencia[i];
            numeroMaisFrequente = i;
        }
    }

    // Imprime o número com maior frequência
    std::cout << "O número com mais frequências é " << numeroMaisFrequente
              << " com uma frequência de " << maiorFrequencia << " vezes." << '\n';

    delete[] frequencia; // Liberar a memória alocada
}

/**
 * @brief Verifica se um número é primo.
 *
 * A função determina se um número inteiro é primo ou não. Um número primo
 * é um número natural maior que 1 que não possui divisores positivos além
 * de 1 e ele mesmo.
 *
 * @param n O número a ser verificado.
 * @return true se o número for primo, false caso contrário.
 */
bool isPrimo(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Encontra os números primos em um array e retorna um novo array
 *        com esses números ordenados em ordem crescente.
 *
 * A função percorre o array de entrada e verifica se cada elemento é primo.
 * Se for, ele é adicionado a um vetor de inteiros. Em seguida, o vetor de
 * inteiros é ordenado em ordem crescente e um novo array é alocado dinamicamente
 * para armazenar os primos ordenados. Por fim, o array resultante é retornado.
 *
 * @param numeros O array de inteiros a ser verificado.
 * @param quantidade A quantidade de elementos no array 'numeros'.
 * @return Um ponteiro para um array de inteiros que contém os números primos
 *         encontrados no array de entrada, ordenados em ordem crescente.
 */
int *numeroPrimosOrdenados(int *numeros, std::size_t quantidade, std::size_t &quantidadePrimos)
{
    // Vetor para armazenar os números primos encontrados
    std::vector<int> primos;

    // Percorrer o array 'numeros' e encontrar os primos
    for (std::size_t i = 0ull; i < quantidade; ++i)
    {
        if (isPrimo(numeros[i]))
        {
            primos.push_back(numeros[i]);
        }
    }

    // Ordenar os primos em ordem crescente
    std::sort(primos.begin(), primos.end());

    // Passar a quantidade de primos encontrados
    quantidadePrimos = primos.size();

    // Alocar memória para o array de primos ordenados
    int *resultado = new int[quantidadePrimos];

    // Copiar os primos ordenados para o array resultante
    for (std::size_t i = 0ull; i < quantidadePrimos; ++i)
    {
        resultado[i] = primos[i];
    }

    return resultado; // Retornar o array resultante
}

int main(int argc, char **argv)
{
    int numeros[] = {1, 1, 2, 2, 2};                               // Exemplo de vetor de números
    std::size_t quantidade = sizeof(numeros) / sizeof(numeros[0]); // Calcula o tamanho do vetor

    frequenciaDeNumeros(numeros, quantidade);

    std::cout << "---------------------------------\n";

    int arrayDeNumeros[] = {9, 4, 8, 1, 2, 0, 3, 6, 11};
    std::size_t quantidades = sizeof(arrayDeNumeros) / sizeof(arrayDeNumeros[0]);
    std::size_t quantidadePrimos = 0ull;

    int *primosOrdenados = numeroPrimosOrdenados(arrayDeNumeros, quantidades, quantidadePrimos);

    // Exibir o array de primos ordenados
    std::cout << "Primos ordenados: ";
    for (std::size_t i = 0ull; i < quantidadePrimos; ++i)
    {
        std::cout << primosOrdenados[i] << ' ';
    }

    // Liberar a memória alocada para o array de primos
    delete[] primosOrdenados;
    return 0;
}

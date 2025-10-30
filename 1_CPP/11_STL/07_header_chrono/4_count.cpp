#include <iostream>
#include <chrono>
#include <cstdlib> // para qsort e bsearch
#include <iomanip> // para std::setw

/**
 * count(): A biblioteca <chrono> é usado para obter o valor numérico de uma duração de tempo.
 * Ele retorna a quantidade de unidades de tempo (como segundos, milissegundos, etc.)
 * armazenadas na duração. Praticamente é um método que retorna o valor bruto da duração.
 *
 * #include <iostream>
 * #include <chrono>
 *
 * int main() {
 * std::chrono::seconds tempo(10); // 10 segundos
 * std::cout << "Tempo: " << tempo.count() << " segundos\n";
 *
 * std::chrono::milliseconds ms(1500);
 * std::cout << ms.count(); // imprime 1500
 * return 0;
 * }
 */

enum class NotacoesAssintoticas
{
    TempoConstante,     // O(1)
    Tempologaritmico,   // O(log n)
    Crescimentolinear,  // O(n)
    TempoIntermediario, // O(n log n)
    TempoQuadratico,    // O(n²)
    Tempoexponencial,   // O(2^n)
    TempoFatorial,      // O(n!)
    TempoOmegaTeta      // ΩΘ
};

// Função de busca linear com medição de tempo e anotação assintótica
void buscarLinear(int array[], std::size_t size, int key, NotacoesAssintoticas notacao = NotacoesAssintoticas::Crescimentolinear)
{
    auto execucao_inicial = std::chrono::steady_clock::now();

    bool encontrado = false;
    std::size_t indice = -1;

    for (std::size_t i = 0; i < size; ++i)
    {
        if (array[i] == key)
        {
            encontrado = true;
            indice = i;
            break; // Encerra ao encontrar (melhor caso)
        }
    }

    auto execucao_final = std::chrono::steady_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(execucao_final - execucao_inicial);

    if (encontrado)
    {
        std::cout << "Valor encontrado: " << key
                  << " na posição: " << indice << '\n';
    }
    else
    {
        std::cout << "Valor " << key << " não encontrado." << '\n';
    }

    std::cout << "Tempo de execução: " << duracao.count() << " microssegundos" << '\n';

    // Exibe a notação assintótica
    std::cout << "Complexidade: ";
    switch (notacao)
    {
    case NotacoesAssintoticas::TempoConstante:
        std::cout << "O(1)";
        break;

    case NotacoesAssintoticas::Tempologaritmico:
        std::cout << "O(log n)";
        break;

    case NotacoesAssintoticas::Crescimentolinear:
        std::cout << "O(n)";
        break;

    case NotacoesAssintoticas::TempoIntermediario:
        std::cout << "O(n log n)";
        break;

    case NotacoesAssintoticas::TempoQuadratico:
        std::cout << "O(n²)";
        break;

    case NotacoesAssintoticas::Tempoexponencial:
        std::cout << "O(2^n)";
        break;

    case NotacoesAssintoticas::TempoFatorial:
        std::cout << "O(n!)";
        break;

    case NotacoesAssintoticas::TempoOmegaTeta:
        std::cout << "Ω(n) / Θ(n)";
        break;
    }
    std::cout << '\n';
}

// Função de comparação para qsort e bsearch
extern "C" int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Função para imprimir a notação assintótica
void imprimirNotacao(NotacoesAssintoticas notacao)
{
    std::cout << "Complexidade assintótica: ";
    switch (notacao)
    {
    case NotacoesAssintoticas::TempoConstante:
        std::cout << "O(1)";
        break;

    case NotacoesAssintoticas::Tempologaritmico:
        std::cout << "O(log n)";
        break;

    case NotacoesAssintoticas::Crescimentolinear:
        std::cout << "O(n)";
        break;

    case NotacoesAssintoticas::TempoIntermediario:
        std::cout << "O(n log n)";
        break;

    case NotacoesAssintoticas::TempoQuadratico:
        std::cout << "O(n²)";
        break;

    case NotacoesAssintoticas::Tempoexponencial:
        std::cout << "O(2^n)";
        break;

    case NotacoesAssintoticas::TempoFatorial:
        std::cout << "O(n!)";
        break;

    case NotacoesAssintoticas::TempoOmegaTeta:
        std::cout << "Ω(n) / Θ(n)";
        break;
    }
    std::cout << '\n';
}

// === ORDENAÇÃO COM qsort ===
void ordenarComQSort(int array[], std::size_t size, NotacoesAssintoticas notacao = NotacoesAssintoticas::TempoIntermediario)
{
    auto inicio = std::chrono::steady_clock::now();

    std::qsort(array, size, sizeof(int), comparar);

    auto fim = std::chrono::steady_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - inicio);

    std::cout << "Array ordenado com std::qsort." << '\n';
    std::cout << "Tempo de ordenação: " << duracao.count() << " microssegundos" << '\n';
    imprimirNotacao(notacao);
}

// === BUSCA BINÁRIA COM bsearch ===
void buscarComBSearch(int array[], std::size_t size, int key, NotacoesAssintoticas notacao = NotacoesAssintoticas::Tempologaritmico)
{
    auto inicio = std::chrono::steady_clock::now();
    auto fim = std::chrono::steady_clock::now();
    auto duracao = std::chrono::duration_cast<std::chrono::nanoseconds>(fim - inicio); // mais preciso para log n
    int *resultado = (int *)std::bsearch(&key, array, size, sizeof(int), comparar);

    if (resultado != nullptr)
    {
        std::size_t indice = std::distance(array, resultado);
        std::cout << "Valor " << key << " encontrado na posição: " << indice << '\n';
    }
    else
    {
        std::cout << "Valor " << key << " não encontrado." << '\n';
    }

    std::cout << "Tempo de busca (bsearch): " << duracao.count() << " nanossegundos" << '\n';
    imprimirNotacao(notacao);
}

/** Você pode pesquisar/explorar outros algoritmos para saber qual sua notação assintôntica. */

int main(int argc, char **argv)
{
    const std::size_t tamanho = 1000;
    int array[tamanho];

    // Preenche o array
    for (std::size_t i = 0; i < tamanho; ++i)
    {
        array[i] = static_cast<int>(i);
    }

    int chave = 777; // Valor a ser buscado

    std::cout << "=== Busca Linear ===" << '\n';
    buscarLinear(array, tamanho, chave);

    const std::size_t size = 10000;
    int *arr = new int[size];

    // Preenche com valores aleatórios
    for (std::size_t i = 0; i < size; ++i)
    {
        arr[i] = static_cast<int>(i * 3 % 7919); // valores "embaralhados"
    }

    int key = 1234; // valor a buscar

    std::cout << std::setw(50) << std::setfill('=') << ' ' << '\n';
    std::cout << "DEMONSTRAÇÃO: qsort + bsearch com Notações Assintóticas" << '\n';
    std::cout << std::setw(50) << std::setfill('=') << ' ' << '\n'
              << std::setfill(' ');

    // 1. Ordenar com qsort → O(n log n)
    ordenarComQSort(arr, size, NotacoesAssintoticas::TempoIntermediario);

    std::cout << '\n';

    // 2. Buscar com bsearch → O(log n)
    buscarComBSearch(arr, size, key, NotacoesAssintoticas::Tempologaritmico);

    delete[] arr;
    return 0;
}

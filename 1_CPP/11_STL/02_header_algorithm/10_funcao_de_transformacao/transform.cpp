#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

/**
 * - std::transform(): Aplica uma função a cada elemento de um container.
 * - std::accumulate(): Realiza a soma acumulada dos elementos.
 * 
 * - (Comentado no cabeçalho) std::transform_reduce, std::transform_inclusive_scan,
 *   std::transform_exclusive_scan: requerem C++17 ou superior.
 */

/**
 * @brief Transforma um vetor elevando ao quadrado cada um de seus elementos.
 *
 * @param v Referência ao vetor de inteiros a ser transformado.
 * @return std::vector<int> Vetor transformado.
 */
std::vector<int> elevarAoQuadrado(std::vector<int> &v)
{
    std::transform(v.begin(), v.end(), v.begin(), [](int x)
    {
        return x * x; 
    });
    
    return v;
}

/**
 * @brief Ordena um vetor em ordem decrescente usando std::transform e std::sort.
 *
 * @param v Referência ao vetor de inteiros a ser ordenado.
 * @return std::vector<int> Vetor ordenado em ordem decrescente.
 */
std::vector<int> ordenarDecrescente(std::vector<int> &v)
{
    std::vector<int> v_invertido(v.size());

    // Inverte o sinal dos elementos
    std::transform(v.begin(), v.end(), v_invertido.begin(), std::negate<int>());

    // Ordena o vetor invertido
    std::sort(v_invertido.begin(), v_invertido.end());

    // Reverte o sinal novamente para restaurar os valores em ordem decrescente
    std::transform(v_invertido.begin(), v_invertido.end(), v.begin(), std::negate<int>());

    return v;
}

/**
 * @brief Converte um array de strings para inteiros e calcula a soma dos elementos.
 *
 * @param foo Array de strings representando números inteiros.
 * @param size Tamanho do array.
 * @return int Soma dos valores convertidos.
 */
int calcularSoma(const char *foo[], std::size_t size)
{
    std::vector<int> numeros(size);

    std::transform(foo, foo + size, numeros.begin(), [](const char *str)
    { 
        return std::atoi(str); 
    });

    return std::accumulate(numeros.begin(), numeros.end(), 0);
}

int main(int argc, char **argv)
{
    // Vetor original
    std::vector<int> v = {5, 7, 3, 2, 1, 8, 6, 10, 11};

    std::cout << "Vetor original: ";
    for (int num : v)
    {
        std::cout << num << ' ';
    }

    // Aplica transformação: eleva ao quadrado
    elevarAoQuadrado(v);

    std::cout << "\nVetor transformado (quadrado de cada elemento): ";
    for (int num : v)
    {
        std::cout << num << ' ';
    }

    std::cout << "\n========================================\n";

    // Ordena em ordem decrescente
    ordenarDecrescente(v);

    std::cout << "\nVetor ordenado (decrescente) com std::transform: ";
    for (int num : v)
    {
        std::cout << num << ' ';
    }

    std::cout << "\n=====================================================\n";

    // Exemplo com array de strings
    const char *foo[] = {"10", "20", "30", "40", "50"};

    int soma = calcularSoma(foo, 5);

    std::cout << "Soma dos valores convertidos: " << soma << '\n';
    return 0;
}

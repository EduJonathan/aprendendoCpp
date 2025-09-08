#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

/*
 * std::iota(param x, param y, param z): Preenchimento de Intervalo, preenche
 * um intervalo com valores consecutivos.
 */

/**
 * @brief Utilizando lambda para preencher um vetor com valores consecutivos,
 * se eles forem divisíveis por 3.
 * 
 * @param inicio Valor inicial do intervalo.
 * @param fim Valor final do intervalo.
 * @return std::vector<int> Vetor preenchido com valores consecutivos divisíveis por 3.
 */
std::vector<int> preencher_consecutivos_div3(int inicio, int fim)
{
    std::vector<int> v(fim - inicio);
    std::iota(v.begin(), v.end(), inicio); // Preenche com valores consecutivos a partir de 'inicio'

    // Filtra os valores que são divisíveis por 3
    v.erase(std::remove_if(v.begin(), v.end(), [](int n)
    {
        return n % 3 != 0;
    }), v.end());

    return v;
}

int main(int argc, char **argv)
{
    std::vector<int> v(10);
    std::iota(v.begin(), v.end(), 1); // Preenche com valores de 1 a 10

    std::cout << "Valores preenchidos com std::iota: ";
    for (int n : v)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    int inicio = 1;
    int fim = 30;
    std::vector<int> div3 = preencher_consecutivos_div3(inicio, fim);
    std::cout << "Valores entre " << inicio << " e " << fim << " divisíveis por 3: ";
    for (int n : div3)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
    return 0;
}

#include <iostream>

/**
 * @brief Troca os valores de duas variáveis.
 *
 * Esta função genérica troca os valores de duas variáveis do mesmo tipo.
 *
 * @tparam T Tipo das variáveis a serem trocadas.
 * @param a Referência para a primeira variável.
 * @param b Referência para a segunda variável.
 */
template <class T>
void troca(T &arg1, T &arg2)
{
    T temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

/**
 * @brief Implementação do algoritmo de ordenação por flutuação (ou bubble sort).
 *
 * Ordena um array de elementos do tipo A em ordem crescente.
 *
 * @param arr Ponteiro para o array a ser ordenado.
 * @param size Tamanho do array.
 */
template <class A>
void bubbleSort(A *arr, std::size_t size)
{
    A temp; /**< Tipo genérico que irá armazenar temporariamente um elemento do array. */

    /** Procedimento de troca para ordenação do array. */
    for (std::size_t i{0ull}; i < size; ++i)
    {
        for (std::size_t j{size - 1}; j > i; --j)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;

                // troca(arr[j - 1], arr[j]); // Alternativa para a troca a função troca genérica.
            }
        }
    }
}

int main(int argc, char **argv)
{
    std::cout << "TIPO INT\n";

    int a = 1, b = 2;
    std::cout << "Antes: a = " << a << ", b = " << b << '\n';
    troca(a, b);
    std::cout << "Depois: a = " << a << ", b = " << b << '\n';

    std::cout << "-------------------------------------\n";

    std::cout << "TIPO DOUBLE\n";

    double c = 1.1, d = 2.2;
    std::cout << "Antes: c = " << c << ", d = " << d << '\n';
    troca(c, d);
    std::cout << "Depois: c = " << c << ", d = " << d << '\n';

    std::cout << "-------------------------------------\n";

    std::cout << "TIPO CHAR\n";

    char e = 'a', f = 'b';
    std::cout << "Antes: e = " << e << ", f = " << f << '\n';
    troca(e, f);
    std::cout << "Depois: e = " << e << ", f = " << f << '\n';

    std::cout << "\n---------------------------------------\n";
    std::cout << "ORDENANDO ARRAYS COM BUBBLE SORT\n";
    std::cout << "\n---------------------------------------\n";

    int arrInteiros[] = {4, 3, 2, 1};
    double arrDouble[] = {1.1, 3.3, 2.2, 5.5};
    char arrCaracteres[] = {'A', 'a', 'C', 'c', 'b', 'B', 'D', 'd', 'E', 'e'};

    std::size_t sizeInt = sizeof(arrInteiros) / sizeof(arrInteiros[0]);
    std::size_t sizeDouble = sizeof(arrDouble) / sizeof(arrDouble[0]);
    std::size_t sizeChars = sizeof(arrCaracteres) / sizeof(arrCaracteres[0]);

    bubbleSort(arrInteiros, sizeInt);
    bubbleSort(arrDouble, sizeDouble);
    bubbleSort(arrCaracteres, sizeChars);

    std::cout << "Inteiros Ordenados: ";
    for (int inteiros = 0; inteiros < sizeInt; ++inteiros)
    {
        std::cout << arrInteiros[inteiros] << ' ';
    }
    std::cout << '\n';

    std::cout << "---------------------------------------" << '\n';

    std::cout << "Doubles Ordenados: ";
    for (int Double = 0; Double < sizeDouble; ++Double)
    {
        std::cout << arrDouble[Double] << ' ';
    }
    std::cout << '\n';

    std::cout << "---------------------------------------" << '\n';

    std::cout << "Caracteres Ordenados: ";
    for (int caracteres = 0; caracteres < sizeChars; ++caracteres)
    {
        std::cout << arrCaracteres[caracteres] << ' ';
    }
    std::cout << '\n';

    std::cout << "---------------------------------------" << '\n';
    return 0;
}

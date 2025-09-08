#include <iostream>

/**
 * RECURSÃO: Consiste quando uma função chama ela mesma, de forma recursiva,
 * e sempre acompanhada de um caso base para condicionar o fim da recursão.
 */

/**
 * @brief Soma os elementos de um array de inteiros de forma recursiva.
 *
 * A função somaDeArrayRecursivo soma os elementos de um array de inteiros de
 * forma recursiva, percorrendo o array de forma reversa (do final para o início).
 *
 * @param array Ponteiro para o array de inteiros a ser somado.
 * @param n Número de elementos no array.
 *
 * @return A soma dos elementos do array.
 */
int somaDeArrayRecursivo(int *array, std::size_t n)
{
    // Caso base: Quando não houver mais elementos para somar
    if (n <= 0)
    {
        return 0;
    }

    // Caso recursivo: Soma o elemento atual com a soma dos elementos restantes
    return array[n - 1] + somaDeArrayRecursivo(array, n - 1);
}

/**
 * @brief Checa se algum dígito repetido é encontrado.
 *
 * A função percorre um array de frequências e retorna verdadeiro se algum dígito
 * aparecer mais de uma vez. A função imprime os dígitos repetidos.
 *
 * @param frequencia Array de frequências dos dígitos.
 *
 * @return Retorna true se houver dígitos repetidos, caso contrário, false.
 */
bool checarDigitosRepetidos(int frequencia[])
{
    bool repetido = false;

    for (int i = 0; i < 10; ++i)
    {
        if (frequencia[i] > 1)
        {
            repetido = true;
            std::cout << "O " << i << " tem " << frequencia[i] << " dígitos repetidos.\n";
        }
    }
    
    return repetido;
}

/**
 * @brief Preenche o array de frequências dos dígitos de um número.
 *
 * A função percorre cada dígito de um número e aumenta sua contagem no array
 * de frequências.
 *
 * @param num Número a ser verificado.
 * @param frequencia Array de frequências dos dígitos.
 */
void digitosRepetidosRecursivo(int num, int frequencia[])
{
    if (num <= 0)
    {
        return;
    }

    int i = num % 10;                                // Obtemos o último dígito
    frequencia[i]++;                                 // Incrementamos a frequência do dígito
    digitosRepetidosRecursivo(num / 10, frequencia); // Chamada recursiva
}

int main(int argc, char **argv)
{
    // Testando soma recursiva
    int array[] = {1, 2, 3, 4, 5};
    std::size_t n = sizeof(array) / sizeof(array[0]);

    int somaDoArray = somaDeArrayRecursivo(array, n);
    std::cout << "Soma do array: " << somaDoArray << '\n';

    std::cout << "-------------------------------------" << '\n';

    int numero = 112233;      // Testando digitos repetidos
    int frequencia[10] = {0}; // Array para contar a frequência de cada dígito

    digitosRepetidosRecursivo(numero, frequencia);
    bool temDigitosRepetidos = checarDigitosRepetidos(frequencia);

    if (!temDigitosRepetidos)
    {
        std::cout << "Não há dígitos repetidos." << '\n';
    }

    std::cout << "-------------------------------------" << '\n';

    int numeros = 123456;      // Testando digitos repetidos
    int frequencias[10] = {0}; // Array para contar a frequência de cada dígito

    digitosRepetidosRecursivo(numeros, frequencias);
    bool digitosRepetidos = checarDigitosRepetidos(frequencias);

    if (!digitosRepetidos)
    {
        std::cout << "Não há dígitos repetidos." << '\n';
    }
    return 0;
}

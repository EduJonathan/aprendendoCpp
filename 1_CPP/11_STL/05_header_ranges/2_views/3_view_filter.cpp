#include <iostream>
#include <array>
#include <ranges>

/**
 * std::views::filter(): É um *range adaptor* que cria uma visualização contendo apenas os
 * elementos de um range que satisfazem um predicado (condição booleana). Os elementos
 * que não atendem à condição são ignorados.
 */

// Função que verifica se um número é primo
bool isPrime(int i)
{
    if (i <= 1)
        return false; // Números menores ou iguais a 1 não são primos

    // Testa divisores de 2 até a raiz quadrada de i
    for (int j = 2; j * j <= i; ++j)
    {
        // Se for divisível por algum número, não é primo
        if (i % j == 0)
        {
            return false;
        }
    }

    // Se não encontrar divisor, é primo
    return true;
}

int main(int argc, char **argv)
{
    std::cout << "Filter even numbers:\n";

    // Função lambda que verifica se um número é par
    auto even = [](int i)
    {
        return i % 2 == 0;
    };

    // Gera uma sequência infinita a partir de 1'000'000
    // Filtra os números pares
    // Pega apenas os 10 primeiros resultados após o filtro
    for (int i : std::views::iota(1'000'000) | std::views::filter(even) | std::views::take(10))
    {
        std::cout << i << ' '; // Imprime os 10 primeiros números pares a partir de 1'000'000
    }

    std::cout << '\n';

    std::cout << "\nFilter odd prime numbers:";
    std::cout.put('\n');

    // Função lambda que verifica se um número é ímpar
    auto odd = [](int i)
    {
        return i % 2 == 1;
    };

    // Gera sequência infinita a partir de 1'000'000
    // Filtra os números ímpares
    // Depois filtra os que são primos (usando a função isPrime)
    // Por fim, pega os 10 primeiros que passaram por ambos os filtros
    for (int i : std::views::iota(1'000'000) | std::views::filter(odd) | std::views::filter(isPrime) | std::views::take(10))
    {
        std::cout << i << ' '; // Imprime os 10 primeiros números ímpares e primos a partir de 1'000'000
    }
    std::cout << '\n';
    return 0;
}

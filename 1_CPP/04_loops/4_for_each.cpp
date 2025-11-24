#include <iostream>
#include <string>
#include <iterator> // Necessário para usar std::begin e std::end

/**
 * FOR vs RANGE-BASED FOR (FOR EACH)
 *
 * FOR:
 *
 * Laço de repetição tradicional que oferece controle total sobre o processo de
 * iteração, através das condicionais. Permite o uso de índices ou iteradores,
 * sendo ideal em situações que exigem:
 *
 * - Acesso a posições específicas;
 * - Pular ou repetir elementos;
 * - Modificar o índice de forma dinâmica;
 * - Comparar elementos adjacentes.
 *
 * for tradicional oferece flexibilidade, no entanto, pode aumentar a complexidade
 * do código e facilitar erros, como o famoso off-by-one (erro de contagem que resulta
 * em pular ou repetir elementos).
 *
 * -------------------------------
 *
 * RANGE-BASED FOR (FOR EACH):
 *
 * Introduzido no C++11, é uma forma mais simples e segura de iterar sobre os
 * elementos de arrays e containers da STL, O conceito central do for-each
 * (range-based for) é: "Para cada elemento presente no conjunto, faça algo".
 *
 * - Elimina a necessidade de índices ou iteradores explícitos;
 * - Reduz o risco de erros comuns de iteração;
 * - Melhora a legibilidade e manutenção do código.
 *
 * RESUMO:
 * - Use o **for tradicional** quando precisar de controle preciso sobre a iteração, sendo mais flexível.
 * - Prefira o **range-based for** para iterações diretas e seguras sobre coleções.
 */

int main(int argc, char **argv)
{
    std::cout << "1. FOR TRADICIONAL: ";

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::size_t array_size = sizeof(array) / sizeof(int);

    // Laço tradicional com índice
    for (std::size_t i = 0ull; i < array_size; ++i)
    {
        std::cout << array[i] << ' ';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "2. FOR EACH: ";

    // Laço range-based (for-each)
    for (const int valor : array)
    {
        std::cout << valor << ' ';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "3. FOR EM STD::STRING: ";

    std::string texto{"Hello World!"};

    // Laço tradicional com índice
    for (std::size_t i = 0ull; i < texto.size(); ++i)
    {
        std::cout << texto[i] << ' ';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "4. FOR EACH (com índice externo):\n";

    int indice = 0; // Variável para armazenar o índice
    for (const char caractere : texto)
    {
        std::cout << "Índice " << indice << ": " << caractere << '\n';
        ++indice; // Incrementando o índice
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "5. FOR EACH:\n";

    std::string nomes[]{"João", "Maria", "Pedro", "Ana", "Carlos"};
    std::size_t i = 0; // Variável para armazenar o índice

    // Usando for-each para percorrer o array de strings
    for (const std::string &nome : nomes)
    {
        std::cout << nome << '\n';
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "6. FOR TRADICIONAL COM ITERADORES:\n";

    // Usando iteradores para percorrer o array de strings e imprimir índice
    for (auto it = std::begin(nomes); it != std::end(nomes); ++it, ++i)
    {
        std::cout << "Índice " << i << ": " << *it << '\n';
        // iterators: São utilizados para percorrer os elementos de um container.
        // std::begin: Retorna um iterador para o primeiro elemento do array de strings.
        // std::end: Retorna um iterador para o fim do array de strings.
    }

    return 0;
}

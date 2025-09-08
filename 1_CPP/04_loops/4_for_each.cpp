#include <iostream>
#include <iterator> // Necessário para usar std::begin e std::end

int main(int argc, char **argv)
{
    std::cout << "1. FOR TRADICIONAL: ";

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};        // Definindo o array de inteiros
    std::size_t array_size = sizeof(array) / sizeof(int); // Calculando o tamanho do array

    // Laço tradicional usando índice para acessar elementos do array
    for (std::size_t i = 0ull; i < array_size; ++i)
    {
        std::cout << array[i] << ' '; // Imprimindo cada elemento do array
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "2. FOR EACH: ";

    // Laço for-each para iterar diretamente sobre os elementos de 'array'
    for (int indice : array)
    {
        std::cout << indice << ' '; // Imprimindo cada elemento do array
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "3. FOR EM STD::STRING: ";

    // Definindo uma string
    std::string string{"Hello World!"};

    // Laço tradicional usando índice para acessar caracteres da string
    for (std::size_t i = 0ull; i < string.size(); ++i)
    {
        std::cout << string[i] << ' '; // Imprimindo cada caractere da string
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "4. FOR EACH:\n";

    // Variável para armazenar o índice
    int index = 0;

    // Usando for-each para percorrer a string e imprimir índice e caractere
    for (char caractere : string)
    {
        std::cout << "Índice " << index << ": " << caractere << '\n'; // Imprimindo índice e caractere
        ++index;                                                      // Incrementando o índice
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "5. FOR TRADICIONAL UTILIZANDO ITERADORES:\n";

    std::string nomes[]{"João", "Maria", "Pedro", "Ana", "Carlos"}; // Array de strings
    std::size_t indice = 0ull;                                      // Variável para armazenar o índice

    // Usando iteradores para percorrer o array de strings e imprimir índice
    for (auto it = std::begin(nomes); it != std::end(nomes); ++it, ++indice)
    {
        std::cout << "Índice " << indice << ": " << *it << '\n';
        // iterators: São utilizados para percorrer os elementos de um container
        // std::begin: Retorna um iterador para o primeiro elemento do array de strings
        // std::end: Retorna um iterador para o fim do array de strings
    }

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "5. FOR EACH:\n";

    // Usando for-each para percorrer o array de strings
    for (std::string names : nomes)
    {
        std::cout << names << ' ' << '\n'; // Imprimindo cada nome do array
    }

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
     * - Use o **for tradicional** quando precisar de controle preciso sobre a iteração,
     * sendo mais flexível.
     * - Prefira o **range-based for** para iterações diretas e seguras sobre coleções.
     */

    return 0;
}

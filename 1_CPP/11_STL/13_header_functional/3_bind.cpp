#include <iostream>
#include <functional>

/**
 * std::bind:
 * ----------
 * Função utilitária que cria **uma nova função** ao "fixar" (ou pré-definir)
 * alguns argumentos de uma função existente, permitindo criar **funções parciais**
 * ou adaptadores para algoritmos.
 *
 * Principais características:
 *  - Pode ser usado com funções normais, ponteiros para funções, lambdas ou functors.
 *  - Permite reordenar argumentos ou deixar alguns em aberto para preenchimento posterior.
 *  - Útil em programação funcional e para integração com algoritmos STL.
 *
 * Exemplo:
 *   #include <functional>
 *   #include <iostream>
 *
 *   int soma(int a, int b) { return a + b; }
 *
 *   auto soma5 = std::bind(soma, 5, std::placeholders::_1);
 *   std::cout << soma5(10);  // saída: 15
 *
 * Explicação do exemplo:
 *  - O primeiro argumento da função `soma` foi fixado como 5.
 *  - O segundo argumento fica em aberto usando `_1`, que será fornecido quando chamarmos `soma5`.
 *
 * Em resumo: `std::bind` cria **funções customizadas ou parciais** a partir de funções existentes,
 * aumentando a flexibilidade de passagem de funções e integração com algoritmos STL.
 */

inline int multiply(int a, int b) { return a * b; }

int main(int argc, char **argv)
{
    auto doubleValue = std::bind(multiply, std::placeholders::_1, 2); // Fixando b = 2
    auto valor = std::bind(multiply, std::placeholders::_1, 3);       // Fixando b = 3
    /*
     * O std::placeholders:: Permite que você marque as posições dos parâmetros
     * para funções criadas com std::bind. Nos ajudando a criar versões parcialmente
     * aplicadas de funções, onde você pode fixar alguns argumentos e deixar outros
     * para serem fornecidos posteriormente.
     *
     * std::placeholders::_1: Refere-se ao primeiro argumento da nova função, _2 ao segundo,
     * e assim por diante.
     */
    std::cout << "10 dobrado é: " << doubleValue(10) << '\n';
    std::cout << "10 dobrado é: " << valor(10) << '\n';

    return 0;
}

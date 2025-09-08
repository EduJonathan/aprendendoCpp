#include <iostream>
#include <functional>

// std::bind(): Cria uma função personalizada ao fixar alguns argumentos de uma função existente.

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

#include <iostream>

/**
 * Se `constexpr` trata-se de uma constante que só é avaliada em tempo de compilação,
 * mas como C++ trata-se de uma evolução da linguagem C, foi herdado então o legado
 * da diretiva `#define` que também define uma constante que ocorre em tempo de compilação,
 * qual a diferença de ambos então?
 *
 * `#define` (também chamado de 'macro') é uma substituição de texto que acontece
 * durante a fase de pré-processamento, antes do código ser de fato compilado.
 * Isso significa que ele não respeita escopo, não possui tipo e não é visível no depurador.
 * Pode levar a erros difíceis de identificar, especialmente em projetos maiores.
 *
 * `constexpr`, por outro lado, é um recurso do compilador introduzido no C++11 e aprimorado
 * nas versões seguintes. Ele permite declarar constantes e até funções que são avaliadas
 * em tempo de compilação, mas com verificação de tipo, respeito ao escopo e melhor suporte
 * a ferramentas de depuração.
 *
 * Assim, sempre que possível, deve-se preferir `constexpr` a `#define` ao trabalhar com constantes.
 *
 * +-----------------------+-----------------------+----------------------------------+
 * | Feature               | #define               | constexpr                        |
 * +-----------------------+-----------------------+----------------------------------+
 * | Segurança de tipo     | Não                   | Sim                              |
 * | Consciência de escopo | Não                   | Sim                              |
 * | Depuração             | Difícil               | Fácil                            |
 * | interpretação         | Substituição de texto | Avaliação em tempo de compilação |
 * | Uso                   | Apenas constantes     | Constantes e funções             |
 * +-----------------------+-----------------------+----------------------------------+
 */

// Exemplo com #define (pré-processador)
#define PI 3.1415926535
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Exemplo com constexpr (C++ moderno)
constexpr double pi = 3.1415926535;
constexpr int max(int a, int b) { return a > b ? a : b; }

int main(int argc, char **argv)
{
    // 1. Verificação de tipo
    double circle1 = PI * 2.0 * 2.0; // OK, mas sem verificação de tipo
    // int bad = PI * "2";           // Erro só aparece após substituição

    double circle2 = pi * 2.0 * 2.0; // Verificação de tipo em tempo de compilação
    // int bad2 = pi * "2";         // Erro imediato: não pode multiplicar double por string

#undef PI

    // 2. Comportamento de escopo
    {
#define PI 3.14                     // Redefine PI em qualquer escopo
        constexpr double pi = 3.14; // Variável local, não afeta a global
    }

    // 3. Uso em templates e metaprogramação
    static_assert(max(1, 2) == 2, "Teste constexpr"); // Funciona
    // static_assert(MAX(1, 2) == 2, "");  // Não funciona com #define

    // 4. Problemas com macros
    int x = 5, y = 10;
    std::cout << "MAX macro: " << MAX(++x, y) << '\n'; // Problema: incremento duplo!
    x = 5;
    std::cout << "max constexpr: " << max(++x, y) << '\n'; // Comportamento correto

    // 5. Depuração
    std::cout << "PI (macro): " << PI << '\n';     // No debugger, vemos o valor substituído
    std::cout << "pi (constexpr): " << pi << '\n'; // No debugger, vemos a variável pi

    return 0;
}

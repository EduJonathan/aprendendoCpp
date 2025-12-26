#include <iostream>
#include <iomanip>
#include <cassert> // Para static_assert, verifica condições no tempo de compilação, gera erro se a condição específica for falsa.

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
 * | Interpretação         | Substituição de texto | Avaliação em tempo de compilação |
 * | Uso                   | Apenas constantes     | Constantes e funções             |
 * +-----------------------+-----------------------+----------------------------------+
 */

// Exemplo com #define (pré-processador)
#define PI 3.1415926535
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Exemplo com constexpr (C++ moderno)
constexpr double pi = 3.1415926535;

// Função constexpr (C++11 em diante) para encontrar o máximo entre dois valores
constexpr int max(int a, int b) { return a > b ? a : b; }

int main(int argc, char **argv)
{
    std::cout << "--- Comparando #define e constexpr ---\n\n";

    // 1. Verificação de tipo
    double circle1 = PI * 2.0 * 2.0; // OK, sem verificação de tipo no pré-processamento
    // double bad = PI * "2";       // O erro só aparece na compilação, após substituição

    double circle2 = pi * 2.0 * 2.0; // Verificação de tipo em tempo de compilação
    // double bad2 = pi * "2";      // Erro imediato do compilador: não pode multiplicar double por string

    std::cout << std::left << std::setw(25) << "circle1 (macro PI):" << circle1 << '\n';
    std::cout << std::left << std::setw(25) << "circle2 (constexpr pi):" << circle2 << "\n\n";

#undef PI

    // 2. Comportamento de escopo
    std::cout << "--- Teste de Escopo ---\n";
    {
#define PI 3.14                           // Redefine PI GLOBALMENTE, apesar do escopo
        constexpr double pi_local = 3.14; // Variável LOCAL, não afeta a global

        std::cout << std::left << std::setw(25) << "PI (Macro dentro do escopo): " << PI << '\n';
        std::cout << std::left << std::setw(25) << "pi (Constexpr local):" << pi_local << '\n';
    }

    // O novo valor (3.14) persiste!
    std::cout << std::left << std::setw(25) << "PI (Macro fora do escopo):" << PI << "\n\n";

    // 3. Uso em templates e metaprogramação
    static_assert(max(1, 2) == 2, "Teste constexpr function OK"); // Funciona em tempo de compilação

    // Macro não pode ser usado em static_assert (requer expressão constante)
    /* static_assert(MAX(1, 2) == 2, ""); */

    // 4. Problemas com macros (Efeitos colaterais)
    std::cout << "--- Problema Com a Macro ---\n";

    int x = 5, y = 10;
    std::cout << std::left << std::setw(25) << "Antes (x, y): " << x << ", " << y << '\n';
    std::cout << std::left << std::setw(25) << "MAX macro (MAX(++x, y)): " << MAX(++x, y) << '\n';
    std::cout << std::left << std::setw(25) << "Depois (x): " << x << '\n'; // x é incrementado duas vezes (valor 7)!

    x = 5;
    std::cout << '\n';
    std::cout << std::left << std::setw(25) << "Antes (x, y): " << x << ", " << y << '\n';
    std::cout << std::left << std::setw(25) << "max constexpr (max(++x, y)): " << max(++x, y) << '\n';

    // x é incrementado apenas uma vez (valor 6), comportamento correto
    std::cout << std::left << std::setw(25) << "Depois (x): " << x << "\n\n";

    // 5. Depuração
    std::cout << "--- Depuração ---\n";
    std::cout << std::left << std::setw(25) << "PI (macro): " << PI << '\n';
    std::cout << std::left << std::setw(25) << "pi (constexpr): " << pi << '\n';
    // Observação: pi (constexpr) é uma variável real e pode ser inspecionada no depurador.
    // PI (macro) é apenas um token e pode ser invisível ou difícil de rastrear.

    return 0;
}

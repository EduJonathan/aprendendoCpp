#include <iostream>
#include <iomanip>

/**
 * Inicialização de Variáveis em C++:
 *
 * Em C++, há 3 formas principais de inicializar variáveis:
 *
 * 1. Inicialização por Atribuição (C++98):
 *    - Herdada da linguagem C.
 *    - Sintaxe: tipo nome_variavel = valor;
 *    - Pode chamar o construtor de cópia ou de movimento.
 *    - Em versões antigas do C++, podia gerar cópias desnecessárias,
 *      mas compiladores modernos otimizam isso muito bem.
 *    - Funciona em praticamente todos os compiladores.
 *
 * Exemplos:
 *      int x = 10;
 *      double d = 3.14;
 *      std::string s = "hello";
 *
 * ----------------------------------
 *
 * 2. Inicialização Direta (C++98):
 *   - Sintaxe: tipo nome_variavel(valor);
 *   - Chama diretamente o construtor do tipo.
 *   - Muito usada para tipos que possuem construtores (ex.: std::string, std::vector).
 *   - Para tipos built-in, funciona igual à inicialização por atribuição.
 *     (Obs: ainda permite narrowing!)
 *
 * Exemplos:
 *      int x(10);
 *      double d(3.14);
 *      std::string s("hello");
 *      std::vector<int> v(10, 5); // 10 elementos com valor 5
 *
 * ----------------------------------
 *
 * 3. Inicialização Uniforme (C++11):
 *   - A forma mais segura: proíbe narrowing conversions.
 *   - Funciona com todos os tipos: built-in, classes, agregados, containers.
 *   - Ideal para inicializar structs sem construtor.
 *   - Ajuda a evitar ambiguidades de construtores.
 *
 * Exemplos:
 *      int x{10};
 *      double d{3.14};
 *      std::string s{"hello"};
 *      std::vector<int> v{1, 2, 3, 4, 5}; // lista de valores
 *      std::vector<int> w(10, 5);         // forma tradicional ainda válida
 *      std::array<int, 5> arr{1, 2, 3, 4, 5};
 *
 * @note Narrowing conversion é quando um valor é convertido para um tipo
 *       que não pode representá-lo completamente, causando perda de dados.
 *       Ex.: converter float para int.
 */

int main(int argc, char **argv)
{
    std::cout << "==================================\n";
    std::cout << ">> INICIALIZAÇÃO TRADICIONAL (C++98) <<\n";
    std::cout << "==================================\n";

    int variavel_copia = 4;     // copia (copy initialization)
    int variavel_direta(5);     // direta com parênteses
    float real = 3.14f;         // float de precisão simples
    int converter_copia = real; // narrowing permitido → silenciosamente vira 3

    std::cout << std::left << std::setw(25) << "variavel_copia (=): " << variavel_copia << '\n';
    std::cout << std::left << std::setw(25) << "variavel_direta (()): " << variavel_direta << '\n';
    std::cout << std::left << std::setw(25) << "real (float): " << std::fixed << std::setprecision(2) << real << '\n';
    std::cout << std::left << std::setw(25) << "converter_copia: " << converter_copia << "  ← narrowing silencioso!\n\n";

    std::cout << "==================================\n";
    std::cout << ">> INICIALIZAÇÃO UNIFORME (C++11+) <<\n";
    std::cout << "==================================\n";

    int a{4};
    float b{5.7f};

    std::cout << std::left << std::setw(25) << "a {4}: " << a << '\n';
    std::cout << std::left << std::setw(25) << "b {5.7f}: " << std::fixed << std::setprecision(2) << b << '\n';

    // Estes 3 dão ERRO de compilação com {} → exatamente o que queremos!
    // int  c{b};          // ERRO: narrowing float → int
    // int  d{5.7};        // ERRO: narrowing double → int
    // char ch{300};       // ERRO: valor fora do range de char

    std::cout << "\n========================================\n";
    std::cout << ">> QUANDO PRECISAR DE NARROWING DELIBERADO <<\n";
    std::cout << "========================================\n";

    double e = 2.71828;

    // Conversão intencional e explícita → tudo bem!
    int cast_b{static_cast<int>(b)};
    int cast_e{static_cast<int>(e)};

    std::cout << std::left << std::setw(30) << "static_cast<int>(b)  (5.7f → int): " << cast_b << '\n';   // 5
    std::cout << std::left << std::setw(30) << "static_cast<int>(e) (2.71828 → int): " << cast_e << '\n'; // 2
    return 0;
}

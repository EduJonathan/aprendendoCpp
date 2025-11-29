#include <iostream>
#include <type_traits>
#include <chrono>
#include <ratio>

/**
 * <ratio> – Frações exatas em tempo de compilação
 *
 * O header <ratio> da Biblioteca Padrão do C++ fornece a classe template std::ratio<Num, Den>
 * que representa uma fração racional em tempo de compilação, com redução automática
 * para a sua forma irredutível e normalização do sinal (o denominador é sempre positivo).
 *
 * Principais características:
 *  • Todos os cálculos são resolvidos em compile-time → zero custo em runtime.
 *  • Máxima precisão: não há arredondamento nem perda de precisão de ponto flutuante.
 *  • A fração é sempre armazenada na forma canônica (mínimos termos, denominador > 0).
 *
 * Tipos e operações disponíveis (todos são alias de std::ratio<...>):
 *
 * Aritméticas:                 Resultado
 *    std::ratio_add<R1, R2>       → R1 + R2
 *    std::ratio_subtract<R1, R2>  → R1 − R2
 *    std::ratio_multiply<R1, R2>  → R1 × R2
 *    std::ratio_divide<R1, R2>    → R1 ÷ R2
 *
 * Comparações (retornam std::true_type ou std::false_type):
 *    std::ratio_equal<R1, R2>     → R1 == R2
 *    std::ratio_not_equal<R1, R2> → R1 != R2
 *    std::ratio_less<R1, R2>      → R1 <  R2
 *    std::ratio_less_equal<R1,R2> → R1 ≤  R2
 *    std::ratio_greater<R1, R2>   → R1 >  R2
 *    std::ratio_greater_equal<R1,R2> → R1 ≥ R2
 *
 * Cada especialização std::ratio<Num, Den> possui dois membros constexpr públicos:
 *    static constexpr intmax_t num;  // numerador já reduzido
 *    static constexpr intmax_t den;  // denominador já reduzido e positivo
 *
 * Uso mais comum: definir unidades de tempo com <chrono>
 *    std::milli  → std::ratio<1, 1000>
 *    std::micro  → std::ratio<1, 1'000'000>
 *    std::ratio<7, 1000> pode representar 7 milissegundos, etc.
 *
 * Exemplo rápido:
 *    using R = std::ratio_multiply<std::ratio<1,2>, std::ratio<3,5>>; // 3/10
 *    std::cout << R::num << '/' << R::den; // imprime 3/10
 */

// Definições simples
using OneHalf = std::ratio<1, 2>;  // 1/2
using OneThird = std::ratio<1, 3>; // 1/3
using TwoFifth = std::ratio<2, 5>; // 2/5
using ThreeQuarters = std::ratio<3, 4>;

// Operações aritméticas (tudo resolvido em compile-time)
using Calc = std::ratio_add<
    std::ratio_multiply<OneHalf, std::ratio<3>>,      // (1/2) * 3 = 3/2
    std::ratio_multiply<ThreeQuarters, std::ratio<4>> // (3/4) * 4 = 3/1
    >;                                                // → 3/2 + 3/1 = 3/2 + 6/2 = 9/2

// Soma direta de duas frações
using Sum = std::ratio_add<OneThird, TwoFifth>;       // 1/3 + 2/5
using Diff = std::ratio_subtract<TwoFifth, OneThird>; // 2/5 - 1/3
using Prod = std::ratio_multiply<OneHalf, TwoFifth>;  // 1/2 * 2/5
using Div = std::ratio_divide<TwoFifth, OneHalf>;     // (2/5) / (1/2)

// Comparações (retornam std::true_type / std::false_type)
using IsEqual = std::ratio_equal<OneHalf, std::ratio<2, 4>>; // true  (ambos 1/2)
using IsLess = std::ratio_less<OneThird, OneHalf>;           // true

int main(int argc, char **argv)
{
    std::cout << std::boolalpha;

    std::cout << "=== Exemplos básicos ===\n";
    std::cout << "OneHalf   = " << OneHalf::num << '/' << OneHalf::den << '\n';   // 1/2
    std::cout << "OneThird  = " << OneThird::num << '/' << OneThird::den << '\n'; // 1/3
    std::cout << "TwoFifth  = " << TwoFifth::num << '/' << TwoFifth::den << '\n'; // 2/5

    std::cout << "\n=== Cálculo complexo (3/2 + 3/1) ===\n";
    std::cout << "Resultado = " << Calc::num << '/' << Calc::den << " = "
              << (static_cast<double>(Calc::num) / Calc::den) << '\n'; // 9/2

    std::cout << "\n=== Operações aritméticas ===\n";
    std::cout << "1/3 + 2/5 = " << Sum::num << '/' << Sum::den << '\n';   // 11/15
    std::cout << "2/5 - 1/3 = " << Diff::num << '/' << Diff::den << '\n'; // 1/15
    std::cout << "1/2 * 2/5 = " << Prod::num << '/' << Prod::den << '\n'; // 1/5
    std::cout << "(2/5)/(1/2) = " << Div::num << '/' << Div::den << '\n'; // 4/5

    std::cout << "\n=== Comparações ===\n";
    std::cout << "1/2 == 2/4 ? " << IsEqual::value << '\n'; // true
    std::cout << "1/3 <  1/2 ? " << IsLess::value << '\n';  // true

    std::cout << "\nDica prática: std::ratio é muito usado com <chrono>\n";

    using Milli = std::milli; // std::ratio<1, 1000>
    using Micro = std::micro; // std::ratio<1, 1000000>
    std::cout << "1 milli = " << Milli::num << '/' << Milli::den << '\n';
    std::cout << "1 micro = " << Micro::num << '/' << Micro::den << '\n';

    // Exemplo real com std::chrono
    using Seconds = std::chrono::duration<double>;
    using Millis = std::chrono::duration<double, std::milli>;
    static_assert(std::is_same<std::chrono::milliseconds::period, std::milli>::value);

    return 0;
}

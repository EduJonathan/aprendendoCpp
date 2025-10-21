#include <iostream>
#include <functional>

/**
 * Biblioteca <functional>:
 * ------------------------
 * Contém objetos conhecidos como **functors** ou **funções-objeto**,
 * que permitem realizar operações genéricas em tempo de execução.
 *
 * Esses objetos podem ser usados com algoritmos da STL ou de forma direta,
 * fornecendo **flexibilidade** e **abstração funcional**.
 *
 * --------------------------------------
 * Functors para operações matemáticas:
 *
 * std::plus<T>       : realiza adição (a + b)
 * std::minus<T>      : realiza subtração (a - b)
 * std::multiplies<T> : realiza multiplicação (a * b)
 * std::divides<T>    : realiza divisão (a / b)
 * std::modulus<T>    : calcula o módulo (a % b)
 *
 * --------------------------------------
 * Functors para operadores lógicos:
 *
 * std::logical_and<T> : operação AND lógico (a && b)
 * std::logical_or<T>  : operação OR lógico (a || b)
 * std::logical_not<T> : negação lógica (!a)
 *
 * --------------------------------------
 * Functors para comparação:
 *
 * std::equal_to<T>        : verifica igualdade (a == b)
 * std::not_equal_to<T>    : verifica desigualdade (a != b)
 * std::greater<T>         : maior que (a > b)
 * std::less<T>            : menor que (a < b)
 * std::greater_equal<T>   : maior ou igual (a >= b)
 * std::less_equal<T>      : menor ou igual (a <= b)
 *
 * --------------------------------------
 * Functors para operadores bitwise:
 *
 * std::bit_and<T> : AND bit a bit (a & b)
 * std::bit_or<T>  : OR bit a bit (a | b)
 * std::bit_xor<T> : XOR bit a bit (a ^ b)
 * std::bit_not<T> : NOT bit a bit (~a)
 *
 * --------------------------------------
 * Observações:
 * - Todos esses functors são templates e aceitam tipos genéricos compatíveis.
 * - Podem ser usados diretamente ou em conjunto com algoritmos STL como std::transform, std::accumulate, etc.
 */

void operadoresLogicos(bool condicional1, bool condicional2)
{
    std::logical_and<bool> logicalAnd; // Usando o functor para realizar a operação "AND"
    std::logical_or<bool> logicalOR;   // Usando o functor para realizar a operação "OR"
    std::logical_not<bool> logicalNOT; // Usando o functor para realizar a operação "NOT"

    std::cout << "Resultado de " << condicional1 << " && " << condicional2 << " = " << logicalAnd(condicional1, condicional2) << '\n';
    std::cout << "Resultado de " << condicional1 << " || " << condicional2 << " = " << logicalOR(condicional1, condicional2) << '\n';
    std::cout << "Resultado de " << condicional1 << " !" << condicional2 << " = " << logicalNOT(!condicional1) << '\n';
    std::cout << "Resultado de " << condicional1 << " !" << condicional2 << " = " << logicalNOT(condicional2) << '\n';
}

void operadoreBitwises(int valor1, int valor2)
{
    std::bit_and<int> And;
    std::bit_or<int> Or;
    std::bit_xor<int> Xor;
    std::bit_not<int> Not;

    std::cout << "Resultado de " << valor1 << " & " << valor2 << " = " << And(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " | " << valor2 << " = " << Or(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " ^ " << valor2 << " = " << And(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " ~ " << valor2 << " = " << Not(valor1) << '\n';
}

void operadoresComparativos(int valor1, int valor2)
{
    std::equal_to<int> equalTo;           // Usando o functor para realizar a operação "=="
    std::not_equal_to<int> notEqualTo;    // Usando o functor para realizar a operação "!="
    std::greater<int> greater;            // Usando o functor para realizar a operação ">"
    std::less<int> less;                  // Usando o functor para realizar a operação "<"
    std::greater_equal<int> greaterEqual; // Usando o functor para realizar a operação ">="
    std::less_equal<int> lessEqual;       // Usando o functor para realizar a operação "<="

    std::cout << "Resultado de " << valor1 << " == " << valor2 << " = " << equalTo(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " != " << valor2 << " = " << notEqualTo(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " > " << valor2 << " = " << greater(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " < " << valor2 << " = " << less(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " >= " << valor2 << " = " << greaterEqual(valor1, valor2) << '\n';
    std::cout << "Resultado de " << valor1 << " <= " << valor2 << " = " << lessEqual(valor1, valor2) << '\n';
}

int main(int argc, char **argv)
{
    std::plus<int> add;
    std::cout << "Soma de 5 + 3 = " << add(5, 3) << '\n';

    std::minus<double> sub;
    std::cout << "Soma de 10.4 - 3.6 = " << sub(10.4, 3.6) << '\n';

    std::multiplies<int> mult;
    std::cout << "Soma de 5 * 6 = " << mult(5, 6) << '\n';

    std::divides<float> div;
    std::cout << "Soma de 100 / 5 = " << div(100, 5) << '\n';

    std::modulus<int> mod;
    std::cout << "Soma de 5 % 5 = " << mod(5, 5) << '\n';

    std::cout << "========================================" << '\n';
    operadoresLogicos(true, false);

    std::cout << "========================================" << '\n';
    operadoreBitwises(5, 3);

    std::cout << "========================================" << '\n';
    operadoresComparativos(8, 4);
    return 0;
}

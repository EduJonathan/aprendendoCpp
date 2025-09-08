#include <iostream>
#include <functional>

/**
 * A biblioteca functional possui objetos que nos ajudam a realizar operações em tempo
 * de execução, ou seja suas operações ocorrem durante a execução do programa.
 * Esses objetos são conhecidos como "functors" ou "funções objeto".
 *
 * E neste código veremos alguns exemplos de como usar esses functors para realizar
 * operações matemáticas, lógicas e bitwise.
 *
 * std::plus<type>: Realiza adição(+).
 * std::minus<type>: Realiza subtração(-).
 * std::multiplies<type>: Realiza multiplicação(*).
 * std::divides<type>: Realiza divisão(/).
 * std::modulus<type>: Calcula o módulo(%).
 *
 * --------------------------------------
 *
 * Existem os objetos para operadores lógicos
 *
 * std::logical_and<type>: Operação &&
 * std::logical_or<type>: Operação ||
 * std::logical_not<type>: Operação !
 *
 * --------------------------------------
 *
 * E os objetos de comparação
 *
 * std::equal_to<type>: Operação ==
 * std::not_equal_to<type>: Operação !=
 * std::greater<type>: Operação >
 * std::less<type>: Operação <
 * std::greater_equal<type>: Operação >=
 * std::less_equal<type>: Operação <=
 *
 * --------------------------------------
 *
 * E os objetos para operadores bitwise
 *
 * std::bit_and<type>: Operação &
 * std::bit_or<type>: Operação |
 * std::bit_xor<type>: Operação ^
 * std::bit_not<type>: Operação ~
 */

void operadoresLogicos(bool condicional1, bool condicional2)
{
    std::logical_and<bool> logicalAnd; // Usando o functor para realizar a operação "AND"
    std::logical_or<bool> logicalOR;   // Usando o functor para realizar a operação "OR"
    std::logical_not<bool> logicalNOT; // Usando o functor para realizar a operação "NOT"

    std::cout << "Resultado de logical_And: " << logicalAnd(condicional1, condicional2) << '\n';
    std::cout << "Resultado de logical_or: " << logicalOR(condicional1, condicional2) << '\n';
    std::cout << "Resultado de logical_not: " << logicalNOT(!condicional1) << '\n';
    std::cout << "Resultado de logical_not: " << logicalNOT(condicional2) << '\n';
}

void operadoreBitwises(int valor1, int valor2)
{
    std::bit_and<int> And;
    std::bit_or<int> Or;
    std::bit_xor<int> Xor;
    std::bit_not<int> Not;

    std::cout << "Resultado de And: " << And(valor1, valor2) << '\n';
    std::cout << "Resultado de Or: " << Or(valor1, valor2) << '\n';
    std::cout << "Resultado de Xor: " << And(valor1, valor2) << '\n';
    std::cout << "Resultado de Not: " << Not(valor1) << '\n';
}

void operadoresComparativos(int valor1, int valor2)
{
    std::equal_to<int> equalTo;           // Usando o functor para realizar a operação "=="
    std::not_equal_to<int> notEqualTo;    // Usando o functor para realizar a operação "!="
    std::greater<int> greater;            // Usando o functor para realizar a operação ">"
    std::less<int> less;                  // Usando o functor para realizar a operação "<"
    std::greater_equal<int> greaterEqual; // Usando o functor para realizar a operação ">="
    std::less_equal<int> lessEqual;       // Usando o functor para realizar a operação "<="

    std::cout << "Resultado de equalTo: " << equalTo(valor1, valor2) << '\n';
    std::cout << "Resultado de notEqualTo: " << notEqualTo(valor1, valor2) << '\n';
    std::cout << "Resultado de greater: " << greater(valor1, valor2) << '\n';
    std::cout << "Resultado de less: " << less(valor1, valor2) << '\n';
    std::cout << "Resultado de greaterEqual: " << greaterEqual(valor1, valor2) << '\n';
    std::cout << "Resultado de lessEqual: " << lessEqual(valor1, valor2) << '\n';
}

int main(int argc, char **argv)
{
    std::plus<int> add;
    std::cout << "Soma de 5 e 3: " << add(5, 3) << '\n';

    std::minus<double> sub;
    std::cout << "Soma de 10.4 e 3.6: " << sub(10.4, 3.6) << '\n';

    std::multiplies<int> mult;
    std::cout << "Soma de 5 e 6: " << mult(5, 6) << '\n';

    std::divides<float> div;
    std::cout << "Soma de 100 e 5: " << div(100, 5) << '\n';

    std::modulus<int> mod;
    std::cout << "Soma de 5 e 5: " << mod(5, 5) << '\n';

    std::cout << "========================================" << '\n';
    operadoresLogicos(true, false);

    std::cout << "========================================" << '\n';
    operadoreBitwises(5, 3);

    std::cout << "========================================" << '\n';
    operadoresComparativos(8, 4);
    return 0;
}

#include <iostream>

/**
 * Operadores lógicos usados para combinar ou inverter expressões booleanas (true/false).
 *
 * OPERADORES LÓGICOS:
 * && (e/and), (E lógico): Verdadeiro se **ambos** os operandos forem verdadeiros.
 * || (ou/or), (OU lógico): Verdadeiro se **pelo menos um** dos operandos for verdadeiro.
 * ! (não/not), (NÃO lógico): Inverte o valor lógico de uma expressão
 *
 * TABELA VERDADE
 * +------------------------------------------------------------------+
 * | valor1 | valor2 | valor1 && valor2 | valor1 || valor2 | !valor1  |
 * +------------------------------------------------------------------+
 * | false  | false  | false            | false            | true     |
 * +------------------------------------------------------------------+
 * | false  | true   | false            | true             | true     |
 * +------------------------------------------------------------------+
 * | true   | false  | false            | true             | false    |
 * +------------------------------------------------------------------+
 * | true   | true   | true             | true             | false    |
 * +------------------------------------------------------------------+
 */

int main(int argc, char **argv)
{
    std::cout << "\nOPERADORES LÓGICOS\n";
    std::cout << "\n-----------------------------------------------\n";

    // Declarando variáveis booleanas
    bool condicao1 = true;
    bool condicao2 = false;

    std::cout << "condicao1 && condicao2 : " << (condicao1 && condicao2) << '\n'; // false
    std::cout << "condicao1 || condicao2 : " << (condicao1 || condicao2) << '\n'; // true
    std::cout << "!condicao1 : " << (!condicao1) << '\n';                         // false

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "\nEXPRESSÕES COM OPERADORES LÓGICOS\n";

    std::cout << "((condicao1 && condicao2) || (!condicao1)) : " << ((condicao1 && condicao2) || (!condicao1)) << '\n';

    bool expressao = ((!(!condicao1) && !condicao2) || (!condicao1));
    std::cout << "((!(condicao1) && !condicao2) || (!condicao1)) : " << expressao << '\n';
    return 0;
}

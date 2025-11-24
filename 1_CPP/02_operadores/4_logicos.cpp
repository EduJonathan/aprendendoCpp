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
 * +--------+--------+-------------------------------------+----------+
 * | valor1 | valor2 | valor1 && valor2 | valor1 || valor2 | !valor1  |
 * +--------+--------+------------------+------------------+----------+
 * | false  | false  | false            | false            | true     |
 * +--------+--------+------------------+------------------+----------+
 * | false  | true   | false            | true             | true     |
 * +--------+--------+------------------+------------------+----------+
 * | true   | false  | false            | true             | false    |
 * +--------+--------+------------------+------------------+----------+
 * | true   | true   | true             | true             | false    |
 * +--------+--------+------------------+------------------+----------+
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

    std::cout << "\n-----------------------------------------------\n";

    // 1. Declaração e Inicialização de Variáveis
    bool condicao_a = true;
    bool condicao_b = false;
    int idade = 25;
    int limite = 18;

    // 2. Expressão Booleana
    // A expressão verifica se (condicao_a é verdadeira E condicao_b é falsa) OU (idade é maior que o limite)
    bool resultado_logico = (condicao_a && !condicao_b) || (idade > limite);

    // 3. Imprimindo o Resultado com std::boolalpha
    std::cout << "--- Análise Lógica ---\n\n";

    // O manipulador std::boolalpha garante que a saída dos valores booleanos seja "true" ou "false" em vez de 1 ou 0.
    std::cout << std::boolalpha;

    std::cout << "Condição A: " << condicao_a << '\n';
    std::cout << "Condição B: " << condicao_b << '\n';
    std::cout << "Idade > Limite (25 > 18): " << (idade > limite) << '\n';

    std::cout << "-----------------------\n";
    std::cout << "Resultado Final da Expressão: " << resultado_logico << '\n';

    return 0;
}

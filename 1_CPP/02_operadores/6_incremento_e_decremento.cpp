#include <iostream>

/**
 * Os operadores de incremento (++) e decremento (--) em C++.
 *
 * - incremento (++var): Adiciona +1 a variável
 * - decremento (--var): Subtrai -1 a variável
 *
 * @note Assim como em C, o uso desses operadores pode ser feito de
 * forma pré-fixada (antes da variável) ou pós-fixada (depois da variável).
 * A diferença está no momento em que o incremento/decremento ocorre
 * em relação à avaliação da expressão, podendo ter um impacto significativo.
 */

int main(int argc, char **argv)
{
    std::cout << "\tINCREMENTO E DECREMENTO\n";
    std::cout << "-----------------------------------------------\n";

    int incremento = 10;
    int preIncremento = 0;
    int posIncremento = 0;

    std::cout << "Valor inicial de incremento : " << incremento << '\n';
    std::cout << "Pré-incremento (++incremento) : " << ++incremento << '\n'; // 11
    std::cout << "Pós-incremento (incremento++) : " << incremento++ << '\n'; // ainda 11, depois vira 12

    preIncremento = ++incremento; // incremento vira 13, depois atribuído
    posIncremento = incremento++; // atribuído 13, depois vira 14

    std::cout << "Valor de incremento atual : " << incremento << '\n';                // 14
    std::cout << "Valor de preIncremento (++incremento) : " << preIncremento << '\n'; // 13
    std::cout << "Valor de posIncremento (incremento++) : " << posIncremento << '\n'; // 13

    std::cout << "\n-----------------------------------------------\n";

    int decremento = 10;
    int preDecremento = 0;
    int posDecremento = 0;

    std::cout << "Valor inicial de decremento : " << decremento << '\n';
    std::cout << "Pré-decremento (--decremento) : " << --decremento << '\n'; // 9
    std::cout << "Pós-decremento (decremento--) : " << decremento-- << '\n'; // ainda 9, depois vira 8

    preDecremento = --decremento; // vira 7, atribui 7
    posDecremento = decremento--; // atribui 7, depois vira 6

    std::cout << "Valor de decremento atual : " << decremento << '\n';                // 6
    std::cout << "Valor de preDecremento (--decremento) : " << preDecremento << '\n'; // 7
    std::cout << "Valor de posDecremento (decremento--) : " << posDecremento << '\n'; // 7

    std::cout << "\n-----------------------------------------------\n";

    int expressao = (preDecremento++) + (posIncremento--); // 7 + 13

    std::cout << "Resultado de (preDecremento++ + posIncremento--): " << expressao << '\n'; // 20

    std::cout << "Valores após a expressão:\n";
    std::cout << "preDecremento : " << preDecremento << '\n'; // 8
    std::cout << "posIncremento : " << posIncremento << '\n'; // 12

    std::cout << "\n-----------------------------------------------\n";

    int valor1 = 10, valor2 = 20, exp = 0;

    exp = (++valor1) + (++valor2); // 11 + 21 = 32
    std::cout << "Resultado de (++valor1 + ++valor2): " << exp << '\n';
    std::cout << "valor1 : " << valor1 << ", valor2: " << valor2 << '\n';

    exp = (valor1--) + (valor2--); // 11 + 21 = 32 (depois valor1 = 10, valor2 = 20)
    std::cout << "Resultado de (valor1-- + valor2--): " << exp << '\n';
    std::cout << "valor1 : " << valor1 << ", valor2: " << valor2 << '\n';

    std::cout << "\n-----------------------------------------------\n";
    std::cout << "CURIOSIDADE: INCREMENTANDO NO MESMO std::cout\n";

    int i = 1;

    // Atenção! Comportamento indefinido — evita-se usar a mesma variável sendo modificada
    // múltiplas vezes sem ordem garantida entre as operações.
    std::cout << "Saída de i, ++i, i++: (COMPORTAMENTO INDEFINIDO E CONFUSO!)\n";
    std::cout << "Exemplo (NÃO RECOMENDADO): i = 1 -> " << i << ++i << i++ << "?\n";
    return 0;
}

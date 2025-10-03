#include <iostream>

/**
 * Operadores condicinais são utilizados para comparar valores, sendo eles:
 *
 * OPERADORES CONDICIONAIS:
 *
 * +------------+-------------------+
 * | OPERADORES |   OPERAÇÃO        |
 * +------------+-------------------+
 * | >          | (maior que)       |
 * +------------+-------------------+
 * | <          | (menor que)       |
 * +------------+-------------------+
 * | >=         | (maior ou igual)  |
 * +------------+-------------------+
 * | <=         | (menor ou igual)  |
 * +------------+-------------------+
 * | ==         | (igualdade)       |
 * +------------+-------------------+
 * | !=         | (diferença)       |
 * +------------+-------------------+
 */

int main(int argc, char **argv)
{
    int numero1 = 25, numero2 = 15;

    std::cout << "O valor de numero1: " << numero1
              << " é maior que o valor de numero2 : " << (numero1 > numero2) << '\n';

    std::cout << "O valor de numero1: " << numero1
              << " é menor que o valor de numero2 : " << (numero1 < numero2) << '\n';

    std::cout << "O valor de numero1: " << numero1
              << " é maior ou igual que o valor de numero2 : " << (numero1 >= numero2) << '\n';

    std::cout << "O valor de numero1: " << numero1
              << " é menor ou igual que o valor de numero2 : " << (numero1 <= numero2) << '\n';

    std::cout << "O valor de numero1: " << numero1
              << " é igual ao valor de numero2 : " << (numero1 == numero2) << '\n';

    std::cout << "O valor de numero1: " << numero1
              << " é diferente ao valor de numero2 : " << (numero1 != numero2) << '\n';
    return 0;
}

#include <iostream>
#include <iomanip>
#include <cmath> // Biblioteca padrão para calcular funções matemáticas, como o módulo(%)

/**
 * Os operadores aritméticos utilizados para realizar operações matemáticas, sendo eles:
 *
 * +------------------------+-----------------------------------+
 * | OPERADORES ARITMÉTICOS | OPERADORES SHORTCURTS ARITMÉTICOS |
 * +------------------------+-----------------------------------+
 * | + (soma)               | += (short soma)                   |
 * +------------------------+-----------------------------------+
 * | - (subtração)          | -= (short subtração)              |
 * +------------------------+-----------------------------------+
 * | * (multiplicação)      | *= (short multiplicação)          |
 * +------------------------+-----------------------------------+
 * | / (divisão)            | /= (short divisão)                |
 * +------------------------+-----------------------------------+
 * | % (resto da divisão)   | %= (short resto da divisão)       |
 * +------------------------+-----------------------------------+
 */

int main(int argc, char **argv)
{
    std::cout << "-----------------------------------------\n";
    std::cout << "\tOPERADORES ARITMÉTICOS\n";
    std::cout << "-----------------------------------------\n";

    // Declarando variáveis
    double numero1 = 10.0;
    double numero2 = 5.0;

    // Imprimindo os valores das variáveis modificadas com os operadores aritméticos
    std::cout << "numero1 + numero2: " << (numero1 + numero2) << '\n';           // Resultado: 15
    std::cout << "numero1 - numero2: " << (numero1 - numero2) << '\n';           // Resultado: 5
    std::cout << "numero1 * numero2: " << (numero1 * numero2) << '\n';           // Resultado: 50
    std::cout << "numero1 / numero2: " << (numero1 / numero2) << '\n';           // Resultado: 2
    std::cout << "numero1 % numero2: " << ((int)numero1 % (int)numero2) << '\n'; // Resultado: 0

    std::cout << "\n-----------------------------------------\n";

    // Exibindo os resultados com 2 casas decimais
    std::cout << std::fixed << std::setprecision(2);

    std::cout << "numero1 + numero2: " << (numero1 + numero2) << '\n';
    std::cout << "numero1 - numero2: " << (numero1 - numero2) << '\n';
    std::cout << "numero1 * numero2: " << (numero1 * numero2) << '\n';
    std::cout << "numero1 / numero2: " << (numero1 / numero2) << '\n';
    std::cout << "numero1 % numero2: " << (static_cast<int>(numero1) % static_cast<int>(numero2)) << '\n';

    // Usando fmod() para calcular o módulo com números de ponto flutuante(std::fmod) de <cmath>
    double resultado_modulo = std::fmod(numero1, numero2);

    // Exibindo o resultado com 2 casas decimais
    std::cout << "numero1 % numero2: " << std::fixed << std::setprecision(5) << resultado_modulo << '\n';

    std::cout << "\n-----------------------------------------" << '\n';
    std::cout << "\tEXPRESSÕES ARITMÉTICAS\n";
    std::cout << "-----------------------------------------" << '\n';

    std::cout << "Expressão: 5 + 3 * 2 = " << (5 + 3 * -2) << '\n';  // Resultado: -1
    std::cout << "Expressão: (5 + 3) * 2 = " << (5 + 3) * 2 << '\n'; // Resultado: 16

    std::cout << "\n-----------------------------------------" << '\n';
    std::cout << "\tSHORTCUTS";
    std::cout << "\n-----------------------------------------" << '\n';

    int valor1 = 78;
    int dividendo = 39, divisor = 2;

    valor1 += 2;                                    // valor1 = valor1 + 2;
    std::cout << "valor1 += 2: " << valor1 << '\n'; // 80

    valor1 -= 8;                                    // valor1 = valor1 - 8;
    std::cout << "valor1 -= 8: " << valor1 << '\n'; // 70

    valor1 *= 2;                                    // valor1 = valor1 * 2;
    std::cout << "valor1 *= 2: " << valor1 << '\n'; // 156

    dividendo /= divisor;                                       // dividendo = dividendo / divisor;
    std::cout << "dividendo /= divisor: " << dividendo << '\n'; // 19.5

    divisor %= 2;                                     // divisor = divisor % 2;
    std::cout << "divisor %= 2: " << divisor << '\n'; // 0
    return 0;
}

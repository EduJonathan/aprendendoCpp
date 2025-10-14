#include <iostream>
#include <iomanip>
#include <cassert>
#include <type_traits>

/**
 * @brief Classe que realiza operações aritméticas básicas
 * (soma, subtração, multiplicação e divisão) sobre dois números.
 *
 * Esta classe é genérica e pode ser usada com qualquer tipo numérico,
 * como `int`, `float`, `double`, etc.
 *
 * @tparam _Type Tipo dos números (por exemplo, int, double).
 *
 * Dentro do template, temos uma classe `Calculator` que recebe dois números
 * e realiza as operações aritméticas. O template permite que a classe seja
 * usada com qualquer tipo numérico, como `int`, `float`, `double`, etc.
 */
template <class _Type>
class Calculator
{
private:
    _Type num1; ///< Primeiro número
    _Type num2; ///< Segundo número

public:
    // Garante que o tipo seja apenas int, float ou double
    static_assert(
        std::is_same<_Type, int>::value ||
            std::is_same<_Type, float>::value ||
            std::is_same<_Type, double>::value,
        "Tipo inválido! Apenas int, float e double são suportados.");

    /**
     * @brief Construtor da classe Calculator.
     *
     * Inicializa os dois números a serem utilizados nas operações.
     *
     * @param n1 Primeiro número para as operações.
     * @param n2 Segundo número para as operações.
     */
    Calculator(_Type number1, _Type number2) : num1(number1), num2(number2) {}

    /**
     * @brief Exibe os resultados das operações aritméticas.
     *
     * Exibe a soma, subtração, multiplicação e divisão dos dois números.
     * Se a divisão for por zero, exibe uma mensagem de erro.
     */
    void exibirValores()
    {
        std::cout << std::fixed << std::setprecision(5);

        std::cout << "A soma dos valores é: " << somar() << '\n';
        std::cout << "A subtracao dos valores é: " << subtrair() << '\n';
        std::cout << "A multiplicacao dos valores é: " << multiplicar() << '\n';

        if (num2 != 0)
        {
            std::cout << "A divisao dos valores é: " << dividir() << '\n';
        }
        else
        {
            std::cout << "Erro: Divisao por zero!" << '\n';
        }
    }

    /**
     * @brief Realiza a soma dos dois números.
     *
     * @return O resultado da soma.
     */
    _Type somar() { return num1 + num2; }

    /**
     * @brief Realiza a subtração entre os dois números.
     *
     * @return O resultado da subtração.
     */
    _Type subtrair() { return num1 - num2; }

    /**
     * @brief Realiza a multiplicação entre os dois números.
     *
     * @return O resultado da multiplicação.
     */
    _Type multiplicar() { return num1 * num2; }

    /**
     * @brief Realiza a divisão entre os dois números.
     *
     * @return O resultado da divisão.
     * @throws std::invalid_argument Caso o divisor seja zero.
     */
    _Type dividir()
    {
        if (num2 == 0)
        {
            throw std::runtime_error("Divisão por zero não é permitida!");
        }
        return num1 / num2;
    }
};

int main(int argc, char **argv)
{
    std::cout << "Resultados dos inteiros:\n";
    Calculator<int> calcInt(10, 5);
    calcInt.exibirValores();

    std::cout << "\n------------------------------------\n";

    std::cout << "Resultados dos floats:\n";
    Calculator<float> calcFloat(20.4f, 5.6f);
    calcFloat.exibirValores();

    std::cout << "\n------------------------------------\n";

    std::cout << "Resultados dos doubles (divisao por zero):\n";
    Calculator<double> calcDoubleZero(10.0, 0.0);
    calcDoubleZero.exibirValores();

    std::cout << "\n------------------------------------\n";

    // Descomente a linha abaixo para testar erro de compilação com tipo inválido
    // Calculator<char> calcChar('b', 'A'); // Gera erro no tempo de compilação
    // Calculator<char> calcChar('1', '2'); // Gera erro no tempo de compilação
    return 0;
}

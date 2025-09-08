#include <iostream>
#include <memory>

/**
 * A sobrecarga dos operadores bitwise (|, &, ^, ~, <<, >>) é usada para manipulação
 * de bits e operações de fluxo de dados. Esses operadores são úteis principalmente para
 * classes que representam dados binários, flags ou qualquer tipo de manipulação em nível
 * de bit, como máscaras e operações lógicas bit a bit.
 *
 * - `|` (OR bit a bit): Realiza uma operação "OU" bit a bit.
 * - `&` (AND bit a bit): Realiza uma operação "E" bit a bit.
 * - `^` (XOR bit a bit): Realiza uma operação "OU exclusivo" bit a bit.
 * - `~` (NOT bit a bit): Realiza uma operação "não" bit a bit, invertendo todos os bits.
 * - `<<` (deslocamento à esquerda): Desloca os bits para a esquerda.
 * - `>>` (deslocamento à direita): Desloca os bits para a direita.
 *
 * Essas sobrecargas permitem criar comportamentos personalizados para objetos que envolvem
 * manipulação de dados binários, como a construção de operações para a manipulação de flags,
 * criptografia, e outras operações que necessitam do controle direto de bits.
 */

class Complex
{
public:
    double real, imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Sobrecarga do operador + (membro da classe)
    Complex operator+(const Complex &outro) const
    {
        return Complex(real + outro.real, imag + outro.imag);
    }

    // Sobrecarga do operador -
    Complex operator-(const Complex &outro) const
    {
        return Complex(real - outro.real, imag - outro.imag);
    }

    // Sobrecarga do operador *
    Complex operator*(const Complex &outro) const
    {
        return Complex(real * outro.real - imag * outro.imag, real * outro.imag + imag * outro.real);
    }

    // Sobrecarga do operador <<
    friend std::ostream &operator<<(std::ostream &os, const Complex &complex)
    {
        os << '(' << complex.real << ", " << complex.imag << ')';
        return os;
    }
};

int main(int argc, char **argv)
{
    std::unique_ptr<Complex> valor1 = std::make_unique<Complex>(1.0, 2.0);
    std::unique_ptr<Complex> valor2 = std::make_unique<Complex>(3.0, 4.0);

    Complex soma = *valor1 + *valor2;      // Usa operator+
    Complex subtracao = *valor1 - *valor2; // Usa operator-
    Complex produto = *valor1 * *valor2;   // Usa operator*

    std::cout << "Soma: " << soma << '\n';
    std::cout << "Subtração: " << subtracao << '\n';
    std::cout << "Produto: " << produto << '\n';

    return 0;
}

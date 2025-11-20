#include <iostream>
#include <new>

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
    // Alocação de objetos usando new
    Complex *valor1 = new Complex(1.0, 2.0);
    Complex *valor2 = new Complex(3.0, 4.0);

    // Realizando operações com os operadores sobrecarregados
    Complex soma = *valor1 + *valor2;      // Usa operator+
    Complex subtracao = *valor1 - *valor2; // Usa operator-
    Complex produto = *valor1 * *valor2;   // Usa operator*

    // Exibindo os resultados
    std::cout << "Soma: " << soma << '\n';
    std::cout << "Subtração: " << subtracao << '\n';
    std::cout << "Produto: " << produto << '\n';

    // Liberação de memória usando delete
    delete valor1;
    delete valor2;

    return 0;
}

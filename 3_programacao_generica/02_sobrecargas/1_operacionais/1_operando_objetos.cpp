#include <iostream>
#include <stdexcept>

template <typename T>
class Numero
{
private:
    T valor;

public:
    // Construtor
    Numero(T v) : valor(v) {}

    // Sobrecarga do operador de soma
    Numero operator+(const Numero &other)
    {
        return Numero(this->valor + other.valor);
    }

    // Sobrecarga do operador de subtração
    Numero operator-(const Numero &other)
    {
        return Numero(this->valor - other.valor);
    }

    // Sobrecarga do operador de multiplicação
    Numero operator*(const Numero &other)
    {
        return Numero(this->valor * other.valor);
    }

    // Sobrecarga do operador de divisão
    Numero operator/(const Numero &other)
    {
        if (other.valor == 0)
        {
            throw std::invalid_argument("Divisão por zero não permitida!");
        }
        return Numero(this->valor / other.valor);
    }

    // Sobrecarga do operador de módulo
    Numero operator%(const Numero &other)
    {
        if (other.valor == 0)
        {
            throw std::invalid_argument("Módulo por zero não permitido!");
        }
        return Numero(this->valor % other.valor);
    }

    // Método para exibir o valor
    void exibir() const
    {
        std::cout << valor << '\n';
    }
};

int main(int argc, char **argv)
{
    Numero<int> num1(10);
    Numero<int> num2(5);

    // Usando os operadores sobrecarregados
    Numero<int> soma = num1 + num2;
    Numero<int> subtracao = num1 - num2;
    Numero<int> multiplicacao = num1 * num2;
    Numero<int> divisao = num1 / num2;
    Numero<int> modulo = num1 % num2;

    // Exibindo os resultados
    std::cout << "Soma: ";
    soma.exibir();

    std::cout << "Subtração: ";
    subtracao.exibir();

    std::cout << "Multiplicação: ";
    multiplicacao.exibir();

    std::cout << "Divisão: ";
    divisao.exibir();

    std::cout << "Módulo: ";
    modulo.exibir();

    return 0;
}

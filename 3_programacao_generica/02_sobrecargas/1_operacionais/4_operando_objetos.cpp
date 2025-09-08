#include <iostream>
#include <memory>
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
    // Testando com inteiros
    using std::unique_ptr;

    unique_ptr<Numero<int>> n1 = std::make_unique<Numero<int>>(10);
    unique_ptr<Numero<int>> n2 = std::make_unique<Numero<int>>(5);

    // Soma
    Numero<int> soma = *n1 + *n2;
    soma.exibir(); // 15

    // Subtração
    Numero<int> subtracao = *n1 - *n2;
    subtracao.exibir(); // 5

    // Multiplicação
    Numero<int> multiplicacao = *n1 * *n2;
    multiplicacao.exibir(); // 50

    // Divisão
    Numero<int> divisao = *n1 / *n2;
    divisao.exibir(); // 2

    // Módulo
    Numero<int> modulo = *n1 % *n2;
    modulo.exibir(); // 0

    // Testando com floats
    unique_ptr<Numero<float>> n3 = std::make_unique<Numero<float>>(10.5f);
    unique_ptr<Numero<float>> n4 = std::make_unique<Numero<float>>(3.2f);

    // Soma
    Numero<float> somaFloat = *n3 + *n4;
    somaFloat.exibir(); // 13.7

    // Divisão
    Numero<float> divisaoFloat = *n3 / *n4;
    divisaoFloat.exibir(); // 3.28125

    return 0;
}

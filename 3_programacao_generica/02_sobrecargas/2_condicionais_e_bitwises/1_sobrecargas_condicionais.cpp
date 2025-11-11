#include <iostream>

class Inteiro
{
private:
    int valor;

public:
    // Construtor
    Inteiro(int v) : valor(v) {}

    // Sobrecarga do operador ==
    bool operator==(const Inteiro &outro) const
    {
        return valor == outro.valor;
    }

    // Sobrecarga do operador !=
    bool operator!=(const Inteiro &outro) const
    {
        return valor != outro.valor;
    }

    // Sobrecarga do operador <
    bool operator<(const Inteiro &outro) const
    {
        return valor < outro.valor;
    }

    // Sobrecarga do operador >
    bool operator>(const Inteiro &outro) const
    {
        return valor > outro.valor;
    }

    // Sobrecarga do operador <=
    bool operator<=(const Inteiro &outro) const
    {
        return valor <= outro.valor;
    }

    // Sobrecarga do operador >=
    bool operator>=(const Inteiro &outro) const
    {
        return valor >= outro.valor;
    }

    // Sobrecarga do operador &&
    bool operator&&(const Inteiro &outro) const
    {
        return valor != 0 && outro.valor != 0;
    }

    // Sobrecarga do operador ||
    bool operator||(const Inteiro &outro) const
    {
        return valor != 0 || outro.valor != 0;
    }

    // Sobrecarga do operador !
    bool operator!() const
    {
        return valor == 0;
    }

    // Método para exibir o valor
    void mostrar() const
    {
        std::cout << "Valor: " << valor << '\n';
    }

    // Método para retornar o valor
    int getValor() const { return valor; }
};

int main(int argc, char **argv)
{
    // Criando objetos diretamente na stack
    Inteiro a(10);
    Inteiro b(20);
    Inteiro c(0);

    // Comparações com == e !=
    if (a == b)
    {
        std::cout << "a é igual a b\n";
    }
    else
    {
        std::cout << "a não é igual a b\n";
    }

    if (a != c)
    {
        std::cout << "a não é igual a c\n";
    }

    // Comparações com <, >, <=, >=
    if (a < b)
    {
        std::cout << "a é menor que b\n";
    }

    if (b > a)
    {
        std::cout << "b é maior que a\n";
    }

    if (a <= b)
    {
        std::cout << "a é menor ou igual a b\n";
    }

    if (b >= a)
    {
        std::cout << "b é maior ou igual a a\n";
    }

    // Operadores lógicos: &&, ||, !
    if (a && b)
    {
        std::cout << "a e b são diferentes de zero\n";
    }

    if (a || c)
    {
        std::cout << "pelo menos um de a ou c é diferente de zero\n";
    }

    if (!c)
    {
        std::cout << "c é zero\n";
    }

    std::cout << "---------------------------" << '\n';

    // Comparando os três valores para encontrar o maior
    Inteiro maior = a;

    if (b > maior)
    {
        maior = b;
    }

    if (c > maior)
    {
        maior = c;
    }

    std::cout << "O maior valor é: " << maior.getValor() << '\n';
    return 0;
}

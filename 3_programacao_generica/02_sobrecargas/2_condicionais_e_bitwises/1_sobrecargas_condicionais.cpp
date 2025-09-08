#include <iostream>
#include <new>

/**
 * A sobrecarga dos operadores (==, !=, <, >, <=, >=, &&, ||, !) permite realizar
 * comparações e operações lógicas de forma personalizada em objetos de classes.
 * Esses operadores são frequentemente usados para facilitar a manipulação e comparação
 * de valores encapsulados em objetos, tornando o código mais legível e intuitivo.
 *
 * Quando sobrecarregados, esses operadores permitem:
 *
 * - Comparar objetos utilizando os operadores tradicionais de comparação (==, !=, <, >, <=, >=).
 * - Realizar operações lógicas booleanas (&&, ||, !) entre objetos, tratando-os como valores lógicos.
 *
 * Exemplo de uso:
 *
 * Inteiro a(10), b(20), c(0);
 * if (a == b) { ... }  // Comparação de igualdade
 * if (a < b) { ... }   // Comparação de menor que
 * if (a && b) { ... }  // Operação lógica E
 *
 * Isso facilita a manipulação de números inteiros ou qualquer outro
 * tipo de dado encapsulado em objetos, tornando a sintaxe mais natural.
 */

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
};

int main(int argc, char **argv)
{
    Inteiro
        *a = new Inteiro(10),
        *b = new Inteiro(20),
        *c = new Inteiro(0);

    // Comparações com == e !=
    if (*a == *b)
    {
        std::cout << "a é igual a b\n";
    }
    else
    {
        std::cout << "a não é igual a b\n";
    }

    if (*a != *c)
    {
        std::cout << "a não é igual a c\n";
    }

    // Comparações com <, >, <=, >=
    if (*a < *b)
    {
        std::cout << "a é menor que b\n";
    }

    if (*b > *a)
    {
        std::cout << "b é maior que a\n";
    }

    if (*a <= *b)
    {
        std::cout << "a é menor ou igual a b\n";
    }

    if (*b >= *a)
    {
        std::cout << "b é maior ou igual a a\n";
    }

    // Operadores lógicos: &&, ||, !
    if (*a && *b)
    {
        std::cout << "a e b são diferentes de zero\n";
    }

    if (*a || *c)
    {
        std::cout << "pelo menos um de a ou c é diferente de zero\n";
    }

    if (!*c)
    {
        std::cout << "c é zero\n";
    }

    delete a;
    delete b;
    delete c;

    return 0;
}

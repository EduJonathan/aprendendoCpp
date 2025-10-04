#include <iostream>

/**
 * Explicit em C++: É utilizado para evitar conversões implícitas automáticas
 * principalmente em construtores ou funções de conversão(casting), fazendo
 * com que o programador tenha que fazer a conversão de forma explícita(ou seja, usando
 * o operador de conversão).
 *
 * Se aplica em construtores de uma única classe ou em operadores de conversão, garantindo
 * que não ocorram conversões automáticas indesejadas.
 *
 * Quando utilizar explicit:
 * - Em construtores que aceitam um único argumento, para evitar conversões implícitas.
 * - Em operadores de conversão, para evitar conversões automáticas que podem levar a erros.
 * - Evitar conversões que podem causar erros sutis ou comportamentos inesperados.
 */

// Exemplo de uso de explicit em construtores
class Valor
{
private:
    int numero;

public:
    // Construtor sem explicit
    Valor(int v) : numero(v) {}

    // Construtor explicit
    explicit Valor(double n) : numero(static_cast<int>(n)) {}

    void exibirValor() const
    {
        std::cout << "Valor: " << numero << '\n';
    }
};

// Uso de operadores de conversão
class Numero
{
    int valor;

public:
    Numero(int v) : valor(v) {}

    // Operador de conversão explicit
    explicit operator int() const
    {
        return valor;
    }
};

int main(int argc, char **argv)
{
    Valor valor1 = 10; // Conversão implícita permitida: int -> Numero(funciona, sem explicit)
    valor1.exibirValor();

    // Valor v2 = 5.5; // Erro: conversão implícita não permitida devido ao explicit
    Valor valor2(5.5); // Correto: conversão explícita
    valor2.exibirValor();

    Numero valor3(42);

    /* int n = valor3; */      // Erro: conversão implícita não permitida
    /* int n = (int)valor3; */ // Erro: conversão implícita não permitida

    int n = static_cast<int>(valor3); // Correto: conversão explícita
    std::cout << "Número convertido: " << n << '\n';
    return 0;
}

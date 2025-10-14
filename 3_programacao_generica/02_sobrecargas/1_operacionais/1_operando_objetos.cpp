#include <iostream>
#include <stdexcept>

/**
 * Sobrecarga de operadores é o processo de redefinir o comportamento de operadores
 * como (+, -, *, /, %) para que funcionem com objetos de classes que você criou.
 * Isso é feito ao implementar funções especiais que definem como o operador deve agir.
 *
 * Os operadores aritméticos são comumente sobrecarregados para realizar operações
 * matemáticas em objetos, como somar dois vetores ou dividir valores em uma classe.
 *
 * Sintaxe: Geralmente, a sobrecarga é feita com uma função chamada operatorX,
 * onde X é o operador a ser sobrecarregado (ex.: operator+ para +).
 *
 * Tipos de sobrecarga:
 * - Membro da classe: Definido dentro da classe, onde o primeiro operando é o objeto
 *   da classe (this).
 * - Função não-membro (geralmente friend): Definido fora da classe, útil quando o
 *   primeiro operando não é um objeto da classe.
 *
 * Restrições:
 * - Nem todos os operadores podem ser sobrecarregados (ex.: ::, ., sizeof, typeid não podem).
 * - A precedência e associatividade dos operadores não podem ser alteradas.
 * - Pelo menos um operando deve ser de um tipo definido pelo usuário.
 *
 * USO:
 * 1. Operações intuitivas: Use quando a operação faz sentido semanticamente, como somar vetores
 * ou concatenar strings.
 *
 * 2. Consistência com tipos nativos: Sobrecarregue operadores para que objetos se comportem
 * como tipos embutidos (ex.: int, double).
 *
 * 3. Simplificar sintaxe: Facilite o uso de objetos em expressões naturais, como `obj1 + obj2`
 * em vez de `obj1.somar(obj2)`.
 *
 * 4. Integração com bibliotecas: Use em bibliotecas para oferecer interfaces consistentes com a STL
 * (ex.: sobrecarregar << para std::cout).
 *
 * 5. Personalização de comportamento: Aplique em classes que representam entidades matemáticas,
 * coleções ou estruturas complexas.
 */

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

#include <iostream>

/**
 * A sobrecarga dos operadores de incremento (`operator++`) e decremento (`operator--`) permite
 * que um objeto seja incrementado ou decrementado de forma customizada, alterando seu estado
 * de acordo com a operação. Esses operadores podem ser sobrecarregados para comportamentos
 * tanto de **incremento pré-fixado** (que incrementa o valor antes de usá-lo) quanto
 * de **incremento pós-fixado** (que usa o valor original antes de incrementá-lo).
 *
 * **Incremento e Decremento Pré-fixado**:
 *
 * - No **incremento pré-fixado** (`++obj`), a operação é realizada antes do
 *   valor ser utilizado. Em outras palavras, o valor do objeto é alterado
 *   antes de ser acessado.
 *
 * - No **decremento pré-fixado** (`--obj`), a operação é realizada antes do
 *   valor ser utilizado. O valor do objeto é alterado imediatamente.
 *
 * **Incremento e Decremento Pós-fixado**:
 *
 * - No **incremento pós-fixado** (`obj++`), o valor original do objeto é
 *   retornado antes de ser incrementado. Ou seja, o objeto é modificado depois
 *   que o valor original foi utilizado.
 *
 * - No **decremento pós-fixado** (`obj--`), o valor original do objeto é
 *   retornado antes de ser decrementado. O objeto é modificado após o uso do
 *   valor original.
 *
 * A principal diferença entre o incremento e decremento **pré-fixado** e **pós-fixado**
 * está no momento em que o valor do objeto é alterado em relação à operação.
 *
 * Exemplo de incremento pré-fixado (`operator++`) e pós-fixado (`operator++(int)`):
 *
 * // Pré-fixado:
 * Distancia d1(100);
 * ++d1;  // A distância é incrementada antes de ser acessada
 *
 * // Pós-fixado:
 * Distancia d2(100);
 * d2++;  // A distância é incrementada após ser acessada
 *
 * A sobrecarga do operador `operator++` e `operator--` é útil quando você precisa de
 * operações personalizadas ao manipular o valor de um objeto. Além disso, esses operadores
 * podem ser usados em loops, como o `for`, onde o comportamento de incremento e decremento é esperado.
 *
 * Quando usar:
 * - Quando você deseja modificar o valor de um objeto de forma repetitiva ou contínua.
 * - Quando a operação de incremento ou decremento deve ser feita de uma forma customizada.
 * - Quando você deseja um comportamento consistente ao usar operadores de incremento ou
 *   decremento em seus objetos.
 *
 * Lembre-se de que a sobrecarga dos operadores de incremento e decremento deve ser
 * feita de maneira clara, de modo que o comportamento seja intuitivo e fácil de entender.
 * Em particular, deve-se garantir que os operadores pós-fixados retornem o valor
 * original do objeto antes da modificação.
 */

class Contador
{
private:
    int contador;

public:
    Contador() : contador(0) {}

    int get_contador() const
    {
        return contador;
    }

    void operator++()
    {
        ++contador;
        std::cout << "Incremento pré-fixado chamado. Novo valor: " << contador << '\n';
    }

    void operator++(int)
    {
        contador++;
        std::cout << "Incremento pós-fixado chamado. Novo valor: " << contador << '\n';
    }
};

int main(int argc, char **argv)
{
    Contador contador1, contador2;

    std::cout << "Contador1 inicial: " << contador1.get_contador() << '\n';
    std::cout << "Contador2 inicial: " << contador2.get_contador() << '\n';

    ++contador1;
    ++contador2;
    contador2++;

    std::cout << "Contador1 inicial: " << contador1.get_contador() << '\n';
    std::cout << "Contador2 inicial: " << contador2.get_contador() << '\n';

    return 0;
}

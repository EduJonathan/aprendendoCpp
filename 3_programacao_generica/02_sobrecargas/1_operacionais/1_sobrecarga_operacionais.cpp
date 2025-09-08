#include <iostream>
#include <cmath>
#include <new>

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

class Vetor
{
public:
    double x, y;
    Vetor(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    // Sobrecarga do operador + (membro da classe)
    Vetor operator+(const Vetor &outro) const
    {
        return Vetor(x + outro.x, y + outro.y);
    }

    // Sobrecarga do operador -
    Vetor operator-(const Vetor &outro) const
    {
        return Vetor(x - outro.x, y - outro.y);
    }

    // Norma (magnitude do vetor)
    double norma(void) const
    {
        return std::sqrt(x * x + y * y);
    }
};

int main(int argc, char **argv)
{
    Vetor *posicaoAtual = new Vetor(1.0, 2.0);
    Vetor *posicaoDestino = new Vetor(3.0, 4.0);
    Vetor resultado = *posicaoAtual + *posicaoDestino; // Usa operator+
    std::cout << "Resultado: (" << resultado.x << ", " << resultado.y << ")\n";

    // Calcula o vetor diferença (destino - atual)
    Vetor diferenca = *posicaoDestino - *posicaoAtual;

    // A distância é o comprimento desse vetor
    double distancia = diferenca.norma();

    std::cout << "Distância faltando: " << distancia << " unidades\n";
    return 0;
}

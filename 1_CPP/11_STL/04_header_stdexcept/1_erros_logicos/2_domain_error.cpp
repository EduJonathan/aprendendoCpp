#include <iostream>
#include <cmath>
#include <stdexcept>

/**
 * std::domain_error:
 * ------------------
 * Exceção lançada quando um argumento fornecido a uma função está
 * **fora do domínio válido** definido para essa operação.
 *
 * É usada principalmente em contextos matemáticos, quando uma função
 * recebe valores que não fazem sentido dentro de seu domínio — por exemplo:
 *  - Calcular a raiz quadrada de um número negativo.
 *  - Calcular o logaritmo de um número não positivo.
 *  - Definir um raio negativo para um círculo (caso prático deste projeto).
 *
 * Em resumo: `std::domain_error` sinaliza que o **valor de entrada é inválido**
 * para a **lógica matemática ou conceitual** da função, e não apenas um erro de tipo
 * ou sintaxe.
 */

/**
 * @brief Função que calcula a área de um círculo dado o raio.
 *
 * @param raio O raio do círculo.
 * @return A área do círculo.
 * @throw std::domain_error Se o raio for negativo.
 */
inline double calcularAreaCirculo(double raio)
{
    if (raio < 0)
    {
        throw std::domain_error("Erro: o raio não pode ser negativo.");
    }

    return 3.14 * raio * raio;
}

int main(int argc, char **argv)
{
    try
    {
        double raio = -5.0; // Valor inválido para o raio (negativo)
        double area = calcularAreaCirculo(raio);
        std::cout << "Área do círculo: " << area << '\n';
    }
    catch (const std::domain_error &e)
    {
        std::cerr << "Erro de domínio: " << e.what() << '\n';
    }

    return 0;
}

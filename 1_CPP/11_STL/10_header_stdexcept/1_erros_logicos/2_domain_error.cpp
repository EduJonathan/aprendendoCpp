#include <iostream>
#include <stdexcept>
#include <cmath>

/**
 * std::domain_error(): Exceção lançada quando um argumento passado a uma função está
 * fora do domínio definido para essa função. Essa exceção é perfeita para erros que
 * envolvem cálculos em um domínio válido de operações matemáticas, como valores negativos
 * para raízes quadradas, logaritmos ou, como no nosso caso, raios de círculos.
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

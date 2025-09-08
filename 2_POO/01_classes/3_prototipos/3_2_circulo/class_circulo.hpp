#ifndef CLASS_CIRCULO_HPP
#define CLASS_CIRCULO_HPP

/**
 * @class Circulo
 *
 * @brief Representa um círculo e fornece métodos para calcular sua área e obter o raio.
 */
class Circulo
{
private:
    double radius; /**< Raio do círculo. */

public:
    /**
     * @brief Define o raio do círculo.
     *
     * @param raio O valor do raio a ser definido para o círculo.
     */
    void setCirculo(double raio);

    /**
     * @brief Obtém o valor do raio do círculo.
     *
     * @return O valor do raio do círculo.
     */
    double getRaio() const;

    /**
     * @brief Calcula a área do círculo.
     *
     * @return O valor da área do círculo.
     */
    double calcularArea() const;

    /**
     * @brief Imprime a área do círculo.
     */
    void imprimirCirculo() const;
};

#endif

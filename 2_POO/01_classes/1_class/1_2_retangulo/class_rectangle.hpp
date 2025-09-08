#ifndef CLASS_RECTANGLE_HPP
#define CLASS_RECTANGLE_HPP

/**
 * @brief Classe base que define a largura e altura de uma forma geométrica.
 *
 * A classe `Rectangle` é uma classe base para uma forma geométrica como um retângulo,
 * que possui dimensões (atributos) de largura (`largura`) e altura (`altura`).
 * Esta classe fornece métodos para definir essas dimensões e calcular a área.
 */
class Rectangle
{
private:
    double largura; ///< Largura da forma geométrica
    double altura;  ///< Altura da forma geométrica

public:
    /**
     * @brief Define a largura da forma.
     *
     * Este método define o valor da largura da forma.
     *
     * @param widht O valor a ser atribuído à largura.
     *
     * @note set(Define): É um método especial que representa a configuração
     * de um atributo. Com o set podemos alterar/definir valores para atributos.
     * Neste método, estamos definindo o valor da largura da forma do retângulo.
     */
    void setWidht(double widht);

    /**
     * @brief Define a altura da forma.
     *
     * Este método define o valor da altura da forma.
     *
     * @param height O valor a ser atribuído à altura.
     */
    void setHeight(double height);

    /**
     * @brief Calcula a área do retângulo.
     *
     * Este método calcula a área de um retângulo, multiplicando a largura pela altura.
     *
     * @return O valor da área do retângulo.
     *
     * @note get(Pegar/Obter): É um método especial que representa a obtenção
     * do valor de um atributo. Neste caso, estamos pegando o valor da área do retângulo.
     */
    double getAreaDoRetangulo(void) const;
};

#endif

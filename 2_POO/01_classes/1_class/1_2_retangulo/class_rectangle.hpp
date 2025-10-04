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
     * @brief Metódo que define a largura e altura do objeto.
     *
     * Este metódo configura os valores widht(largura) e height(altura)
     *
     * @param widht O valor a ser atribuído à largura.
     * @param height O valor a ser atribuído à altura.
     *
     * @note set(Definir): É um método que representa a configuração de um atributo.
     * Com a nomeação set fica entendido que podemos alterar/definir valores para atributos.
     * Neste método, estamos definindo o valor da largura e altura da forma do retângulo.
     */
    void setDimensoes(double widht, double height);

    /**
     * @brief Calcula a área do retângulo.
     *
     * Este método calcula a área de um retângulo, multiplicando a largura pela altura.
     *
     * @return O valor da área do retângulo.
     *
     * @note get(Pegar/Obter): É um método que representa a obtenção do valor de um atributo.
     * Fica entedido que com ele possamos obter o retorno/informação do estado atual do objeto.
     * Neste caso, estamos pegando o valor da área do retângulo.
     */
    double getAreaDoRetangulo(void) const;
};

#endif

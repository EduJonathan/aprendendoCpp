#ifndef CLASS_RGB_HPP
#define CLASS_RGB_HPP

#include "classCor.hpp"
#include "classHexadecimal.hpp"

/**
 * @brief Classe que representa uma cor no formato RGB.
 */
class RGB : public Cor
{
private:
    int r, g, b;
    static void validar(int valor);

public:
    /**
     * @brief Construtor da classe RGB.
     *
     * @param r Valor vermelho (0-255)
     * @param g Valor verde (0-255)
     * @param b Valor azul (0-255)
     * @throws std::out_of_range Se qualquer componente estiver fora do intervalo.
     */
    RGB(int r, int g, int b);

    // Construtor a partir de Hexadecimal
    explicit RGB(const Hexadecimal &hex);

    void exibir() const override;
    std::string comoString() const override;

    /**
     * @brief Converte a cor para hexadecimal.
     *
     * @return String com valor hexadecimal.
     */
    std::string paraHex() const;

    int getR() const;
    int getG() const;
    int getB() const;
};

#endif

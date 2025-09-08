#ifndef CLASS_HEXADECIMAL_HPP
#define CLASS_HEXADECIMAL_HPP

#include "classCor.hpp"
#include <tuple>
#include <string>

/**
 * @brief Classe que representa uma cor em formato hexadecimal.
 */
class Hexadecimal : public Cor
{
private:
    std::string hex;

public:
    /**
     * @brief Construtor da classe Hexadecimal.
     *
     * @param hex String hexadecimal (ex: "FF0000").
     * @throws std::invalid_argument Se a string não tiver 6 caracteres.
     */
    Hexadecimal(const std::string &hex);

    void exibir() const override;
    std::string comoString() const override;

    /**
     * @brief Converte hexadecimal para RGB.
     *
     * @return Tupla com os valores (r, g, b).
     */
    std::tuple<int, int, int> paraRGB() const;
};

#endif

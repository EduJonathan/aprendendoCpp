#ifndef CLASS_COR_HPP
#define CLASS_COR_HPP

#include <string>

/**
 * @brief Classe base abstrata para representar uma cor.
 */
class Cor
{
public:
    /**
     * @brief Irá exibir a cor em formato específico.
     */
    virtual void exibir() const = 0;

    /**
     * @brief Retorna a representação da cor como string(hexadecimal).
     *
     * @return String representando a cor.
     */
    virtual std::string comoString() const = 0;

    /**
     * @brief Destrutor virtual.
     */
    virtual ~Cor() = default;
};

#endif

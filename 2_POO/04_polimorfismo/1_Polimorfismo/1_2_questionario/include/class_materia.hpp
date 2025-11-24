#ifndef CLASS_MATERIA_HPP
#define CLASS_MATERIA_HPP

#include <string>

class Materia
{
public:
    virtual void questionario() = 0;
    virtual double calcularPorcentagem() const = 0;
    virtual std::string getNome() const = 0;
    virtual int getAcertos() const = 0;
    virtual int getTotalQuestoes() const = 0;
    virtual ~Materia() = default;
};

#endif

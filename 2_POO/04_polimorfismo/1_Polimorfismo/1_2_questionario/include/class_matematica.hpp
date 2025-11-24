#ifndef CLASS_MATEMATICA_HPP
#define CLASS_MATEMATICA_HPP

#include "class_materia.hpp"

class Matematica : public Materia
{
private:
    int acertos;
    int totalQuestoes;

public:
    Matematica();
    void questionario() override;
    double calcularPorcentagem() const override;
    std::string getNome() const override;
    int getAcertos() const override;
    int getTotalQuestoes() const override;
};

#endif

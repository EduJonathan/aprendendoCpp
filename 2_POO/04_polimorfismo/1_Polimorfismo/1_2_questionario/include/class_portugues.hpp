#ifndef CLASS_PORTUGUES_HPP
#define CLASS_PORTUGUES_HPP

#include "class_materia.hpp"

class Portugues : public Materia
{
private:
    int acertos;
    int totalQuestoes;

public:
    Portugues();
    void questionario() override;
    double calcularPorcentagem() const override;
    std::string getNome() const override;
};

#endif

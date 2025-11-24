#ifndef CLASS_PROGRAMACAO_HPP
#define CLASS_PROGRAMACAO_HPP

#include "class_materia.hpp"

class Programacao : public Materia
{
private:
    int acertos;
    int totalQuestoes;

public:
    Programacao();
    void questionario() override;
    double calcularPorcentagem() const override;
    std::string getNome() const override;
    int getAcertos() const override;
    int getTotalQuestoes() const override;
};

#endif

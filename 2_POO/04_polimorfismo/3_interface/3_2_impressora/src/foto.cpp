// Foto.cpp
#include "../class/classe_foto.hpp"
#include <utility>

Foto::Foto(std::string resolucao) : resolucao(std::move(resolucao)) {}

std::string Foto::descricao() const
{
    return "Foto (" + resolucao + ')';
}

int Foto::paginas() const
{
    return 1;
}

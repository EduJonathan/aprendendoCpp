// Documento.cpp
#include "../class/classe_documento.hpp"
#include <utility>

Documento::Documento(std::string titulo, int paginas) : titulo(std::move(titulo)), numPaginas(paginas) {}

std::string Documento::descricao() const
{
    return "Documento: " + titulo;
}

int Documento::paginas() const
{
    return numPaginas;
}

// Documento.hpp
#ifndef DOCUMENTO_HPP
#define DOCUMENTO_HPP

#include "../interface/interface_imprimir.hpp"
#include <string>

class Documento : public IImprimivel
{
private:
    std::string titulo;
    int numPaginas;

public:
    Documento(std::string titulo, int paginas);
    std::string descricao() const override;
    int paginas() const override;
};

#endif

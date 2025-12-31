// Foto.hpp
#ifndef FOTO_HPP
#define FOTO_HPP

#include "../interface/interface_imprimir.hpp"
#include <string>

class Foto : public IImprimivel
{
private:
    std::string resolucao;

public:
    explicit Foto(std::string resolucao);
    std::string descricao() const override;
    int paginas() const override;
};

#endif

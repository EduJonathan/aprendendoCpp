// IImprimivel.hpp
#ifndef IIMPRIMIVEL_HPP
#define IIMPRIMIVEL_HPP

#include <string>

class IImprimivel
{
public:
    virtual std::string descricao() const = 0;
    virtual int paginas() const = 0;
    virtual ~IImprimivel() = default;
};

#endif

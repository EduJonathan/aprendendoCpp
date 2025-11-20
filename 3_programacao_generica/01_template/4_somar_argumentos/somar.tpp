#ifndef SOMAR_TPP
#define SOMAR_TPP

#include "template_soma.hpp"

template <typename... Args>
auto sum(Args... args)
{
    return (args + ...); // Fold expression (C++17)
}

#endif

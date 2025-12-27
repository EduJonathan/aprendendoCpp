#pragma once

#include <iostream>
#include <stdexcept>
#include <cstddef>

class Str
{
private:
    char *buffer;
    std::size_t strLength;
    std::size_t bufferLength;

    void reserve(std::size_t newCapacity);

public:
    // Construtores
    Str();
    explicit Str(const char *cstr);
    Str(const Str &other);
    Str(Str &&other) noexcept;

    // Destrutor
    ~Str();

    // Operadores de atribuição
    Str &operator=(const Str &other);
    Str &operator=(Str &&other) noexcept;

    // Concatenação
    Str &operator+=(const Str &other);
    Str operator+(const Str &other) const;

    // Acesso por índice
    char &operator[](std::size_t k);
    const char &operator[](std::size_t k) const;

    // Métodos úteis
    std::size_t length() const;
    const char *c_str() const;
    bool empty() const;
    void clear();
};

// Operadores externos
std::ostream &operator<<(std::ostream &out, const Str &str);
std::istream &operator>>(std::istream &in, Str &str);

// Nome diferente para evitar conflito com std::getline
std::istream &getline_str(std::istream &in, Str &str);

// Comparações
bool operator==(const Str &lhs, const Str &rhs);
bool operator!=(const Str &lhs, const Str &rhs);
bool operator<(const Str &lhs, const Str &rhs);
bool operator<=(const Str &lhs, const Str &rhs);
bool operator>(const Str &lhs, const Str &rhs);
bool operator>=(const Str &lhs, const Str &rhs);

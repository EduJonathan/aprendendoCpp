#include "string.hpp"
#include <cstring>
#include <algorithm>

// Sempre garante que o buffer final seja válido
void Str::reserve(std::size_t newCapacity)
{
    if (newCapacity <= bufferLength)
        return;

    std::size_t target = std::max(newCapacity, bufferLength * 2);
    char *newBuffer = new char[target];

    if (buffer)
        std::strcpy(newBuffer, buffer);
    else
        newBuffer[0] = '\0';

    delete[] buffer;
    buffer = newBuffer;
    bufferLength = target;
}

// Construtor padrão
Str::Str() : buffer(new char[1]), strLength(0), bufferLength(1)
{
    buffer[0] = '\0';
}

// Construtor a partir de const char*
Str::Str(const char *cstr)
{
    if (!cstr)
        cstr = "";

    strLength = std::strlen(cstr);
    bufferLength = strLength + 1;
    buffer = new char[bufferLength];
    std::strcpy(buffer, cstr);
}

// Construtor de cópia (preserva capacidade)
Str::Str(const Str &other) : strLength(other.strLength), bufferLength(other.bufferLength)
{
    buffer = new char[bufferLength];
    std::strcpy(buffer, other.buffer);
}

// Construtor de movimento (estado válido após mover)
Str::Str(Str &&other) noexcept : buffer(other.buffer), strLength(other.strLength), bufferLength(other.bufferLength)
{
    other.buffer = new char[1];
    other.buffer[0] = '\0';
    other.strLength = 0;
    other.bufferLength = 1;
}

// Destrutor
Str::~Str()
{
    delete[] buffer;
}

// Atribuição por cópia
Str &Str::operator=(const Str &other)
{
    if (this != &other)
    {
        char *newBuffer = new char[other.bufferLength];
        std::strcpy(newBuffer, other.buffer);

        delete[] buffer;
        buffer = newBuffer;
        strLength = other.strLength;
        bufferLength = other.bufferLength;
    }
    return *this;
}

// Atribuição por movimento
Str &Str::operator=(Str &&other) noexcept
{
    if (this != &other)
    {
        delete[] buffer;

        buffer = other.buffer;
        strLength = other.strLength;
        bufferLength = other.bufferLength;

        other.buffer = new char[1];
        other.buffer[0] = '\0';
        other.strLength = 0;
        other.bufferLength = 1;
    }
    return *this;
}

// operator+=
Str &Str::operator+=(const Str &other)
{
    std::size_t newLength = strLength + other.strLength;
    reserve(newLength + 1);

    std::strcpy(buffer + strLength, other.buffer);
    strLength = newLength;

    return *this;
}

// operator+
Str Str::operator+(const Str &other) const
{
    Str result(*this);
    result += other;
    return result;
}

// Acesso por índice
char &Str::operator[](std::size_t k)
{
    if (k >= strLength)
        throw std::out_of_range("Str index out of bounds");
    return buffer[k];
}

const char &Str::operator[](std::size_t k) const
{
    if (k >= strLength)
        throw std::out_of_range("Str index out of bounds");
    return buffer[k];
}

// Métodos úteis
std::size_t Str::length() const { return strLength; }
const char *Str::c_str() const { return buffer; }
bool Str::empty() const { return strLength == 0; }

void Str::clear()
{
    strLength = 0;
    buffer[0] = '\0';
}

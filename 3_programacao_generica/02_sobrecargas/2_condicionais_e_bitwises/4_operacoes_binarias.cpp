#include <iostream>
#include <bitset>
#include <stdexcept>
#include <limits>

/**
 * Implementar uma classe BitInt que realiza operações aritméticas básicas
 * (adição, subtração, multiplicação e divisão) exclusivamente por meio de
 * manipulação binária, sem utilizar operadores aritméticos diretos do C++
 * (+ - * /). A classe também demonstra operadores bit a bit e manipulação
 * de memória com alocação dinâmica (new/delete).
 */

class BitInt
{
    int value;

public:
    constexpr BitInt(int v = 0) : value(v) {}

    // Conversão para int
    constexpr operator int() const { return value; }

    // Operadores bit a bit
    constexpr BitInt operator&(const BitInt &o) const noexcept { return BitInt(value & o.value); }
    constexpr BitInt operator|(const BitInt &o) const noexcept { return BitInt(value | o.value); }
    constexpr BitInt operator^(const BitInt &o) const noexcept { return BitInt(value ^ o.value); }
    constexpr BitInt operator~() const noexcept { return BitInt(~value); }

    BitInt operator<<(int s) const
    {
        if (s < 0 || s >= std::numeric_limits<int>::digits)
        {
            throw std::out_of_range("Invalid shift amount");
        }
        return BitInt(value << s);
    }

    BitInt operator>>(int s) const
    {
        if (s < 0 || s >= std::numeric_limits<int>::digits)
        {
            throw std::out_of_range("Invalid shift amount");
        }
        return BitInt(value >> s);
    }

    // Operadores aritméticos
    BitInt operator+(const BitInt &o) const
    {
        BitInt a = *this, b = o;
        while (b.value != 0)
        {
            BitInt carry = a & b;
            a = a ^ b;
            b = carry << 1;

            if ((a.value > 0 && b.value > std::numeric_limits<int>::max() - a.value) ||
                (a.value < 0 && b.value < std::numeric_limits<int>::min() - a.value))
            {
                throw std::overflow_error("Arithmetic overflow in addition");
            }
        }
        return a;
    }

    BitInt operator-(const BitInt &o) const
    {
        return *this + (~o + BitInt(1));
    }

    BitInt operator*(const BitInt &o) const
    {
        BitInt a = *this, b = o, result(0);
        bool neg = (a.value < 0) ^ (b.value < 0);

        // Converte para positivo usando complemento de dois
        if (a.value < 0)
            a = ~a + BitInt(1);
        if (b.value < 0)
            b = ~b + BitInt(1);

        while (b.value != 0)
        {
            if (b.value & 1)
                result += a;
            a = a << 1;
            b = b >> 1;
        }

        return neg ? ~result + BitInt(1) : result;
    }

    BitInt operator/(const BitInt &o) const
    {
        if (o.value == 0)
            throw std::runtime_error("Division by zero");

        BitInt a = *this, b = o;
        bool neg = (a.value < 0) ^ (b.value < 0);

        if (a.value < 0)
            a = ~a + BitInt(1);
        if (b.value < 0)
            b = ~b + BitInt(1);

        // Otimização: divisão por potência de 2
        if ((b.value & (b.value - 1)) == 0 && b.value != 0)
        {
            int shift = 0;
            while (b.value > 1)
            {
                b = b >> 1;
                ++shift;
            }
            BitInt result = a >> shift;
            return neg ? ~result + BitInt(1) : result;
        }

        BitInt q(0);
        while (a.value >= b.value)
        {
            a -= b;
            q += BitInt(1);
        }
        return neg ? ~q + BitInt(1) : q;
    }

    // Operadores de atribuição
    BitInt &operator+=(const BitInt &o)
    {
        *this = *this + o;
        return *this;
    }

    BitInt &operator-=(const BitInt &o)
    {
        *this = *this - o;
        return *this;
    }

    BitInt &operator*=(const BitInt &o)
    {
        *this = *this * o;
        return *this;
    }

    BitInt &operator/=(const BitInt &o)
    {
        *this = *this / o;
        return *this;
    }

    // Operadores de comparação
    bool operator==(const BitInt &o) const { return value == o.value; }
    bool operator!=(const BitInt &o) const { return value != o.value; }
    bool operator<(const BitInt &o) const { return value < o.value; }
    bool operator>(const BitInt &o) const { return value > o.value; }
    bool operator<=(const BitInt &o) const { return value <= o.value; }
    bool operator>=(const BitInt &o) const { return value >= o.value; }

    friend std::ostream &operator<<(std::ostream &os, const BitInt &bi)
    {
        os << bi.value << " (binary: " << std::bitset<32>(bi.value) << ")";
        return os;
    }
};

int main(int argc, char **argv)
{
    try
    {
        // Alocação dinâmica com new
        BitInt *a = new BitInt(5);
        BitInt *b = new BitInt(3);

        std::cout << "a = " << *a << '\n';
        std::cout << "b = " << *b << '\n';
        std::cout << "a + b = " << (*a + *b) << '\n';
        std::cout << "a - b = " << (*a - *b) << '\n';
        std::cout << "a * b = " << (*a * *b) << '\n';
        std::cout << "a / b = " << (*a / *b) << '\n';
        std::cout << "a & b = " << (*a & *b) << '\n';
        std::cout << "a | b = " << (*a | *b) << '\n';
        std::cout << "a ^ b = " << (*a ^ *b) << '\n';
        std::cout << "~a = " << (~(*a)) << '\n';
        std::cout << "a << 1 = " << (*a << 1) << '\n';
        std::cout << "a >> 1 = " << (*a >> 1) << '\n';

        // Liberação de memória com delete
        delete a;
        delete b;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro: " << e.what() << '\n';
    }

    return 0;
}

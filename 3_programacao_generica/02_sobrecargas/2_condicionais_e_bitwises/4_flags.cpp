#include <iostream>
#include <memory>

// Template de classe Flags
template <typename T>
class Flags
{
private:
    T value; // Valor genérico para armazenar as flags

public:
    // Construtor
    Flags(T v = 0) : value(v) {}

    // Sobrecarga do operador | (OR bit a bit)
    std::unique_ptr<Flags> operator|(const Flags &outro) const
    {
        return std::make_unique<Flags>(value | outro.value);
    }

    // Sobrecarga do operador & (AND bit a bit)
    std::unique_ptr<Flags> operator&(const Flags &outro) const
    {
        return std::make_unique<Flags>(value & outro.value);
    }

    // Sobrecarga do operador ^ (XOR bit a bit)
    std::unique_ptr<Flags> operator^(const Flags &outro) const
    {
        return std::make_unique<Flags>(value ^ outro.value);
    }

    // Sobrecarga do operador ~ (NOT bit a bit)
    std::unique_ptr<Flags> operator~() const
    {
        return std::make_unique<Flags>(~value);
    }

    // Sobrecarga do operador << (deslocamento à esquerda)
    std::unique_ptr<Flags> operator<<(int n) const
    {
        return std::make_unique<Flags>(value << n);
    }

    // Sobrecarga do operador >> (deslocamento à direita)
    std::unique_ptr<Flags> operator>>(int n) const
    {
        return std::make_unique<Flags>(value >> n);
    }

    // Função para exibir o valor das flags (como número binário)
    void mostrar() const
    {
        std::cout << "Flags: ";
        for (int i = sizeof(T) * 8 - 1; i >= 0; --i)
        {
            std::cout << ((value >> i) & 1);
            if (i % 4 == 0)
                std::cout << ' ';
        }
        std::cout << '\n';
    }
};

int main(int argc, char **argv)
{
    // Usando unique_ptr para alocar as instâncias de Flags
    auto f1 = std::make_unique<Flags<int>>(0b1100); // Flags com valor binário 1100
    auto f2 = std::make_unique<Flags<int>>(0b1010); // Flags com valor binário 1010

    // Operações bit a bit
    auto orResult = *f1 | *f2;
    auto andResult = *f1 & *f2;
    auto xorResult = *f1 ^ *f2;
    auto notResult = ~(*f1);
    auto leftShiftResult = *f1 << 2;
    auto rightShiftResult = *f1 >> 2;

    // Exibindo resultados
    std::cout << "f1: ";
    f1->mostrar();
    std::cout << "f2: ";
    f2->mostrar();

    std::cout << "f1 | f2: ";
    orResult->mostrar();

    std::cout << "f1 & f2: ";
    andResult->mostrar();

    std::cout << "f1 ^ f2: ";
    xorResult->mostrar();

    std::cout << "~f1: ";
    notResult->mostrar();

    std::cout << "f1 << 2: ";
    leftShiftResult->mostrar();

    std::cout << "f1 >> 2: ";
    rightShiftResult->mostrar();

    return 0;
}

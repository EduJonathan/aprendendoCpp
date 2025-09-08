#include <iostream>
#include <new>

namespace Algebra
{
    class Vetor
    {
    public:
        double x, y;
        Vetor(double x = 0.0, double y = 0.0) : x(x), y(y) {}

        // Sobrecarga de + (membro)
        Vetor operator+(const Vetor &outro) const
        {
            return Vetor(x + outro.x, y + outro.y);
        }

        // Sobrecarga de == (membro)
        bool operator==(const Vetor &outro) const
        {
            return x == outro.x && y == outro.y;
        }

        // Sobrecarga de << (friend)
        friend std::ostream &operator<<(std::ostream &os, const Vetor &v);
    };

    // Definição de << no namespace Algebra
    std::ostream &operator<<(std::ostream &os, const Vetor &v)
    {
        os << '(' << v.x << ", " << v.y << ')';
        return os;
    }
}

int main(int argc, char **argv)
{
    Algebra::Vetor
        *v1 = new Algebra::Vetor(1.0, 2.0),
        *v2 = new Algebra::Vetor(3.0, 4.0),
        *v3 = new Algebra::Vetor(1.0, 2.0);

    Algebra::Vetor soma = *v1 + *v2;
    std::cout << "Soma: " << soma << '\n';             // Saída: (4, 6)
    std::cout << "v1 == v2: " << (*v1 == *v2) << '\n'; // Saída: 0 (false)
    std::cout << "v1 == v3: " << (*v1 == *v3) << '\n'; // Saída: 1 (true)
    return 0;
}

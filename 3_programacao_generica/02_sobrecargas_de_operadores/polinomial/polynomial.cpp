#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial
{
public:
    // Construtor padrão: polinômio zero
    Polynomial() : coeffs(max_degree + 1, 0), degree(0) {}

    // Zera o polinômio
    void zero()
    {
        std::fill(coeffs.begin(), coeffs.end(), 0);
        degree = 0;
    }

    // Operador de soma
    Polynomial operator+(const Polynomial &rhs) const
    {
        Polynomial result;
        result.degree = std::max(degree, rhs.degree);

        for (int i = 0; i <= result.degree; ++i)
        {
            int a = i <= degree ? coeffs[i] : 0;
            int b = i <= rhs.degree ? rhs.coeffs[i] : 0;
            result.coeffs[i] = a + b;
        }

        result.normalize();
        return result;
    }

    // Operador de multiplicação
    Polynomial operator*(const Polynomial &rhs) const
    {
        Polynomial result;
        result.zero();

        result.degree = degree + rhs.degree;
        if (result.degree > max_degree)
        {
            std::cerr << "operator* exceeded MAX_DEGREE (" << max_degree << ")\n";
            result.degree = max_degree;
        }

        for (int i = 0; i <= degree; ++i)
        {
            for (int j = 0; j <= rhs.degree; ++j)
            {
                int k = i + j;
                if (k <= max_degree)
                    result.coeffs[k] += coeffs[i] * rhs.coeffs[j];
            }
        }

        result.normalize();
        return result;
    }

    // Saída formatada
    friend std::ostream &operator<<(std::ostream &os, const Polynomial &p)
    {
        if (p.degree == 0 && p.coeffs[0] == 0)
        {
            os << '0';
            return os;
        }

        bool first = true;
        for (int i = p.degree; i >= 0; --i)
        {
            int coef = p.coeffs[i];
            if (coef == 0)
                continue;

            // sinal
            if (!first)
            {
                os << (coef > 0 ? " + " : " - ");
            }
            else if (coef < 0)
            {
                os << '-';
            }

            int abscoef = std::abs(coef);

            // coeficiente
            if (i == 0)
            {
                os << abscoef; // constante
            }
            else if (abscoef != 1)
            {
                os << abscoef << 'x';
                if (i > 1)
                    os << '^' << i;
            }
            else
            {
                os << 'x';
                if (i > 1)
                    os << '^' << i;
            }

            first = false;
        }

        return os;
    }

    // Deixei público para seu teste, mas idealmente seria friend ou setter.
    std::vector<int> coeffs;
    int degree;

private:
    static constexpr int max_degree = 100;

    // Remove coeficientes de maior grau que sejam zero
    void normalize()
    {
        while (degree > 0 && coeffs[degree] == 0)
            --degree;
    }
};

int main(int argc, char **argv)
{
    // x + 1
    Polynomial x_plus_1;
    x_plus_1.coeffs[0] = 1;
    x_plus_1.coeffs[1] = 1;
    x_plus_1.degree = 1;

    auto q = x_plus_1 + x_plus_1;         // 2x + 2
    auto p_squared = q * q;               // (2x+2)² = 4x² + 8x + 4
    auto final_q = p_squared + p_squared; // 8x² + 16x + 8

    std::cout << "Resultado: " << final_q << '\n';

    return 0;
}

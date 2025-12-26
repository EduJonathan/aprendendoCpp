#include <iostream>
#include <iomanip>
#include <cmath>
#include <numbers>
#include <limits>
#include <optional>
#include <cstdint>
#include <ratio>

// Precisão desejada: 10⁻¹²
using DesiredPrecision = std::ratio<1, 1'000'000'000'000>; // 1e-12
constexpr double EPS = static_cast<double>(DesiredPrecision::num) / DesiredPrecision::den;

constexpr double f(double x) noexcept
{
    return std::log10(x) - std::cos(x);
}

// Método da bisseção com retorno de std::optional
std::optional<double> bisection(double a, double b, int max_iter = 100)
{
    if (a >= b)
        std::swap(a, b);
    if (a <= 0.0)
    {
        std::cerr << "Erro: domínio de log10(x) requer x > 0\n";
        return std::nullopt;
    }

    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0)
    {
        std::cerr << "Erro: f(a) e f(b) têm o mesmo sinal. Não há garantia de raiz no intervalo.\n";
        return std::nullopt;
    }

    std::cout << "Método da Bisseção para log10(x) - cos(x) = 0\n";
    std::cout << "─────────────────────────────────────────────────────────────\n";
    std::cout << std::setw(4) << "it"
              << std::setw(12) << 'a'
              << std::setw(14) << "f(a)"
              << std::setw(14) << 'b'
              << std::setw(14) << "f(b)"
              << std::setw(14) << 'x'
              << std::setw(16) << "f(x)" << '\n';

    std::cout << std::string(80, '-') << '\n';

    double x = 0.0, fx = 0.0;
    for (int iter = 1; iter <= max_iter; ++iter)
    {
        x = (a + b) / 2.0;
        fx = f(x);

        std::cout << std::fixed << std::setprecision(10)
                  << std::setw(4) << iter
                  << std::setw(12) << 'a'
                  << std::setw(14) << "fa"
                  << std::setw(14) << 'b'
                  << std::setw(14) << "fb"
                  << std::setw(14) << 'x'
                  << std::setw(14) << "fx" << '\n';

        if (std::abs(fx) < EPS || std::abs(b - a) < EPS)
        {
            std::cout << "\nConvergência alcançada após " << iter << " iterações.\n";
            std::cout << "Raiz aproximada: " << std::setprecision(12) << x << '\n';
            return x;
        }

        (fx * fa > 0.0 ? a = x, fa = fx : b = x, fb = fx);
    }

    std::cout << "Aviso: número máximo de iterações atingido.\n";
    std::cout << "Melhor aproximação: " << std::setprecision(12) << x << '\n';
    return x;
}

int main(int argc, char **argv)
{
    std::cout << "Resolução numérica de log10(x) - cos(x) = 0\n\n";

    double a = 0.0, b = 0.0;
    std::cout << "Entre com o intervalo inicial [a, b] (ex: 1 3): ";
    std::cin >> a >> b;

    // Validação básica
    if (a <= 0 || b <= 0)
    {
        std::cerr << "Erro: ambos os extremos devem ser positivos (domínio do log10).\n";
        return 1;
    }

    auto root = bisection(a, b);

    if (root)
    {
        std::cout << "\nRaiz final: " << std::setprecision(15) << *root << '\n';
        std::cout << "f(raiz) = " << f(*root) << '\n';
    }

    return 0;
}

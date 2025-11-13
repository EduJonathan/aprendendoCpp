#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <random>

/**
 * std::uniform_real_distribution
 * ------------------------------
 * Gera números reais (decimais) com a mesma probabilidade dentro de um intervalo.
 *
 * Exemplo: se o intervalo é [0.0, 1.0], qualquer valor entre 0 e 1 tem a mesma chance.
 *
 * Ideal para:
 * - Gerar probabilidades aleatórias
 * - Simulações físicas e gráficos aleatórios
 * - Normalizar resultados entre 0 e 1
 */

// Função para avaliar polinômio: p(x) = a_n*x^n + ... + a_0
double evaluate(const std::vector<double> &coef, double x)
{
    double result = 0.0;
    for (int i = 0; i < coef.size(); ++i)
    {
        result += coef[i] * std::pow(x, i);
    }
    return result;
}

// Derivada: p'(x)
double derivative(const std::vector<double> &coef, double x)
{
    if (coef.size() <= 1)
        return 0.0;

    double result = 0.0;
    for (int i = 1; i < coef.size(); ++i)
    {
        result += i * coef[i] * std::pow(x, i - 1);
    }
    return result;
}

// Newton-Raphson
double newton_raphson(const std::vector<double> &coef, double x0, double tol = 1e-4, int max_iter = 100)
{
    double x = x0;
    std::cout << "\n ******************************************************\n";
    std::cout << " ITERATION    X1       FX1       F'X1     |Δx|\n";
    std::cout << " ******************************************************\n";

    for (int iter = 1; iter <= max_iter; ++iter)
    {
        double fx = evaluate(coef, x);
        double fpx = derivative(coef, x);

        if (std::fabs(fpx) < 1e-12)
        {
            std::cout << "Derivada muito pequena! Parando.\n";
            return x;
        }

        double x_new = x - fx / fpx;
        double delta = std::fabs(x_new - x);

        std::cout << std::setw(5) << iter
                  << std::setw(12) << std::fixed << std::setprecision(6) << x
                  << std::setw(12) << fx
                  << std::setw(12) << fpx
                  << std::setw(12) << delta << '\n';

        if (delta < tol)
        {
            return x_new;
        }
        x = x_new;
    }
    std::cout << "Máximo de iterações atingido.\n";
    return x;
}

// Gera polinômio com coeficientes uniformes em [min, max]
std::vector<double> generate_uniform_poly(int degree, double min = -10.0, double max = 10.0)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Gera números reais uniformemente distribuídos em um intervalo `[a, b)` ou `[a, b]`.
    std::uniform_real_distribution<> dis(min, max);

    std::vector<double> coef(degree + 1);
    for (auto &c : coef)
        c = dis(gen);
    return coef;
}

// Gera polinômio com coeficientes binomiais (inteiros não-negativos)
std::vector<double> generate_binomial_poly(int degree, int n_trials = 10, double p = 0.5)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Gera valores inteiros que representam quantos sucessos em `n` tentativas com probabilidade `p`
    std::binomial_distribution<int> dis(n_trials, p);

    std::vector<double> coef(degree + 1);
    for (auto &c : coef)
        c = dis(gen); // valores inteiros >= 0

    // Opcional: tornar alguns negativos
    std::uniform_real_distribution<> sign_dis(0.0, 1.0);
    for (auto &c : coef)
    {
        if (sign_dis(gen) < 0.5)
            c = -c;
    }
    return coef;
}

void print_poly(const std::vector<double> &coef)
{
    std::cout << " O POLINÔMIO É: ";
    bool first = true;
    for (int i = coef.size() - 1; i >= 0; --i)
    {
        if (coef[i] == 0)
            continue;
        if (!first && coef[i] > 0)
            std::cout << " +";
        else if (!first)
            std::cout << ' ';
        if (coef[i] < 0)
            std::cout << '-';

        double abs_c = std::fabs(coef[i]);
        if (abs_c != 1 || i == 0)
            std::cout << abs_c;
        else if (abs_c == 1 && i > 0 && coef[i] < 0)
            std::cout << '-';

        if (i > 0)
        {
            std::cout << 'x';
            if (i > 1)
                std::cout << '^' << i;
        }
        first = false;
    }
    if (first)
        std::cout << '0';
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    std::cout << std::fixed << std::setprecision(6);

    int choice = 0;
    std::cout << "\n=== MÉTODO DE NEWTON-RAPHSON ===\n";
    std::cout << "1. Entrada manual\n";
    std::cout << "2. Polinômio aleatório (uniforme)\n";
    std::cout << "3. Polinômio aleatório (binomial)\n";
    std::cout << "Escolha: ";
    std::cin >> choice;

    std::vector<double> coef;
    int degree = 0;
    double x0 = 0.0;

    if (choice == 1)
    {
        std::cout << "Grau do polinômio: ";
        std::cin >> degree;
        coef.resize(degree + 1);

        for (int i = 0; i <= degree; ++i)
        {
            std::cout << "Coeficiente de x^" << i << ": ";
            std::cin >> coef[i];
        }

        std::cout << "Chute inicial x0: ";
        std::cin >> x0;
    }
    else if (choice == 2)
    {
        std::cout << "Grau do polinômio: ";
        std::cin >> degree;

        coef = generate_uniform_poly(degree, -10, 10);
        print_poly(coef);

        std::cout << "Chute inicial x0 (sugestão: 0): ";
        std::cin >> x0;
    }
    else if (choice == 3)
    {
        std::cout << "Grau do polinômio: ";
        std::cin >> degree;

        int n_trials = 0;

        std::cout << "Parâmetro n da binomial (ex: 10): ";
        std::cin >> n_trials;

        coef = generate_binomial_poly(degree, n_trials, 0.5);
        print_poly(coef);

        std::cout << "Chute inicial x0: ";
        std::cin >> x0;
    }
    else
    {
        std::cout << "Opção inválida!\n";
        return 1;
    }

    double root = newton_raphson(coef, x0);

    std::cout << "\n A RAIZ APROXIMADA É: " << root << '\n';
    std::cout << " f(" << root << ") = " << evaluate(coef, root) << '\n';

    return 0;
}

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

/**
 * @brief Avalia um polinômio no ponto x.
 * O polinômio é representado por um vetor de coeficientes, onde coef[i] é o coeficiente de x^i.
 * O valor do polinômio p(x) = a_n*x^n + ... + a_0 é calculado como p(x) = a_0 + a_1*x + a_2*x^2 + ... + a_n*x^n.
 *
 * @param coef Coeficientes do polinômio, onde coef[i] é o coeficiente de x^i.
 * @param x Ponto onde o polinômio será avaliado.
 * @return Valor do polinômio p(x) no ponto x.
 */
double evaluate(const std::vector<double> &coef, double x)
{
    double result = 0.0;
    for (int i = 0; i < coef.size(); ++i)
    {
        result += coef[i] * std::pow(x, i);
    }
    return result;
}

/**
 * @brief Calcula a derivada de um polinômio no ponto x.
 * O polinômio é representado por um vetor de coeficientes, onde coef[i] é o coeficiente de x^i.
 * A derivada de um polinômio p(x) = a_n*x^n + ... + a_0 é dada por p'(x) = n*a_n*x^(n-1) + ... + 1*a_1.
 *
 * @param coef Coeficientes do polinômio, onde coef[i] é o coeficiente de x^i.
 * @param x Ponto onde a derivada será avaliada.
 * @return Valor da derivada p'(x) no ponto x.
 */
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

/**
 * @brief Método de Newton-Raphson para encontrar raízes de um polinômio.
 *
 * O método de Newton-Raphson é um algoritmo iterativo para encontrar aproximações de raízes de funções reais.
 * Ele utiliza a fórmula: x_{n+1} = x_n - f(x_n) / f'(x_n), onde f é a função e f' é a sua derivada.
 *
 * @param coef Coeficientes do polinômio, onde coef[i] é o coeficiente de x^i.
 * @param x0 Chute inicial para a raiz.
 * @param tol Tolerância para convergência (padrão: 1e-4).
 * @param max_iter Número máximo de iterações (padrão: 100).
 * @return Aproximação da raiz encontrada.
 */
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

/**
 * @brief Gera um polinômio com coeficientes uniformemente distribuídos em um intervalo [min, max].
 *
 * @param degree Grau do polinômio.
 * @param min Valor mínimo para os coeficientes (padrão: -10.0).
 * @param max Valor máximo para os coeficientes (padrão: 10.0).
 * @return Vetor de coeficientes do polinômio, onde coef[i] é o coeficiente de x^i.
 */
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

/**
 * @brief Gera um polinômio com coeficientes seguindo uma distribuição binomial. O número de tentativas `n_trials`
 * e a probabilidade de sucesso `p` podem ser * ajustados para controlar a forma da distribuição dos coeficientes.
 * Ideal para criar polinômios com coeficientes que tendem a ser mais próximos de zero ou mais dispersos,
 * dependendo dos parâmetros escolhidos.
 *
 * @param degree Grau do polinômio.
 * @param n_trials Número de tentativas para a distribuição binomial (ex: 10).
 * @param p Probabilidade de sucesso em cada tentativa (ex: 0.5).
 * @return Vetor de coeficientes do polinômio, onde coef[i] é o coeficiente de x^i, gerados a partir de uma distribuição binomial.
 *
 * Ideal para:
 * - Criar polinômios com coeficientes que tendem a ser mais próximos de zero ou mais dispersos, dependendo dos parâmetros escolhidos.
 * - Simulações onde a distribuição dos coeficientes deve seguir um padrão específico (ex: mais valores próximos de zero).
 */
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

/**
 * @brief Imprime um polinômio no formato legível, por exemplo: "3x^2 - 2x + 1".
 *
 * O polinômio é representado por um vetor de coeficientes, onde coef[i] é o coeficiente de x^i.
 * O formato de saída é construído considerando os sinais, os coeficientes e as potências de x.
 *
 * @param coef Coeficientes do polinômio, onde coef[i] é o coeficiente de x^i.
 */
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

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <random>

/**
 * O gerador ranlux (Random Luxury Generator) foi criado por Martin Lüscher
 * como uma evolução do gerador de congruência linear (LCG),
 * visando eliminar correlações indesejadas e melhorar a qualidade estatística
 * dos números pseudoaleatórios.
 *
 * --------------------
 *
 * Em C++, o ranlux é representado por uma família de motores:
 *   - std::ranlux24_base
 *   - std::ranlux48_base
 *   - std::ranlux24
 *   - std::ranlux48
 *
 * As versões "base" (ranlux24_base e ranlux48_base) são os motores fundamentais,
 * enquanto as versões sem "_base" (ranlux24 e ranlux48) adicionam o conceito de *discard block*,
 * ou seja, descartam uma parte dos números gerados para reduzir ainda mais
 * possíveis correlações entre os valores.
 *
 * --------------------
 *
 * Características principais:
 * - Baseado em um LCG (Linear Congruential Generator) com *luxury level* ajustável.
 * - Gera números pseudoaleatórios de alta qualidade, adequados para simulações
 *   físicas e estatísticas que exigem excelente independência entre valores.
 * - Mais lento do que std::mt19937, porém com melhor “entropia estatística”.
 * - Determinístico: a mesma semente (seed) gera sempre a mesma sequência.
 *
 * --------------------
 *
 * Comparação resumida:
 * - std::mt19937 → rápido, excelente qualidade para jogos e simulações gerais.
 * - std::ranlux → mais lento, ideal para simulações científicas de precisão.
 */

struct Particula
{
    double x, y;   // Posição
    double vx, vy; // Velocidade
};

/**
 * Calcula a força de repulsão entre partículas próximas.
 * A força é aplicada se a distância entre partículas for menor que raio_min.
 *
 * @param particula Vetor de partículas.
 * @param raio_min Distância mínima para aplicar a força de repulsão.
 * @param intensindade Intensidade da força de repulsão.
 */
void forca_repulsao(std::vector<Particula> &particula, double raio_min, double intensidade, double delta_t)
{
    int n = particula.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            double dx = particula[j].x - particula[i].x;
            double dy = particula[j].y - particula[i].y;
            double distancia = std::sqrt(dx * dx + dy * dy);

            if (distancia < raio_min && distancia > 1e-6)
            {
                double forca = intensidade * (raio_min - distancia) / distancia;
                double fx = forca * (dx / distancia);
                double fy = forca * (dy / distancia);

                particula[i].vx -= fx * delta_t;
                particula[i].vy -= fy * delta_t;
                particula[j].vx += fx * delta_t;
                particula[j].vy += fy * delta_t;
            }
        }
    }
}

int main(int argc, char **argv)
{
    const int num_particulas = 5;
    const int num_iteracoes = 20;
    const double delta_t = 0.1;
    const double raio_repulsao = 0.1;
    const double intensidade_repulsao = 0.05;

    std::random_device rd;                                        // Fonte de entropia do sistema
    std::ranlux48_base gerador(rd());                             // Usando ranlux48_base como gerador de números aleatórios
    std::uniform_real_distribution<double> dist_pos(0.0, 1.0);    // Posições iniciais entre 0.0 e 1.0
    std::uniform_real_distribution<double> dist_vel(-0.05, 0.05); // Velocidades iniciais entre -0.05 e 0.05

    // Inicializa partículas com posições e velocidades aleatórias
    std::vector<Particula> particulas(num_particulas);
    for (auto &p : particulas)
    {
        p.x = dist_pos(gerador);
        p.y = dist_pos(gerador);
        p.vx = dist_vel(gerador);
        p.vy = dist_vel(gerador);
    }

    // Simula o movimento das partículas
    for (int iter = 0; iter < num_iteracoes; ++iter)
    {
        forca_repulsao(particulas, raio_repulsao, intensidade_repulsao, delta_t);

        std::cout << "Iteração " << iter + 1 << ":\n";
        for (auto &p : particulas)
        {
            p.x += p.vx * delta_t;
            p.y += p.vy * delta_t;

            // Reflete nas bordas
            if (p.x < 0.0 || p.x > 1.0)
                p.vx = -p.vx;
            if (p.y < 0.0 || p.y > 1.0)
                p.vy = -p.vy;

            std::cout << std::fixed << std::setprecision(3);
            std::cout << "  (" << p.x << ", " << p.y << ")\n";
        }
        std::cout << '\n';
    }
    return 0;
}

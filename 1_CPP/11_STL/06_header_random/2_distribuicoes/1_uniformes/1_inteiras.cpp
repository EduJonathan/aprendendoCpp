#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <random>

/**
 * std::uniform_int_distribution
 * ------------------------------
 * Gera números inteiros com a mesma probabilidade dentro de um intervalo.
 *
 * Exemplo: se o intervalo é [1, 6], todos os valores 1, 2, 3, 4, 5 e 6
 * têm a mesma chance de aparecer — como o lançamento de um dado.
 *
 * Ideal para:
 * - Simulações simples (dados, sorteios, índices aleatórios)
 * - Escolher elementos de um vetor de forma aleatória
 */

// Par de inteiros
using Point = std::pair<int, int>;

/**
 * @brief Calcula o fecho convexo (convex hull) de um conjunto de pontos 2D.
 *
 * Essa função implementa o algoritmo de **Andrew’s monotone chain** para encontrar o fecho convexo
 * de um conjunto de pontos. O fecho convexo é o menor polígono convexo que contém todos os pontos
 * do conjunto. O resultado é retornado como um vetor de pontos ordenados no sentido anti-horário.
 *
 * @param points Vetor de pontos (std::vector<Point>), onde Point é um par (x, y).
 *               Exemplo: `using Point = std::pair<int, int>;`
 *
 * @return std::vector<Point> Vetor de pontos que formam o fecho convexo, em ordem anti-horária.
 *
 * @note
 * - Duplicatas são removidas automaticamente.
 * - Se houver apenas um ponto, ele é retornado diretamente.
 * - O tipo de coordenada usado no cálculo do produto vetorial é `long long` para evitar overflow.
 */
std::vector<Point> convex_hull(std::vector<Point> points)
{
    // Remover duplicatas e ordená-las
    std::sort(points.begin(), points.end());
    points.erase(std::unique(points.begin(), points.end()), points.end());

    if (points.size() <= 1)
        return points;

    // Função auxiliar para calcular produto do vetor
    auto cross = [](const Point &a, const Point &b, const Point &c) -> long long
    {
        return (static_cast<long long>(b.first - a.first) * (c.second - a.second) -
                static_cast<long long>(b.second - a.second) * (c.first - a.first));
    };

    // Função auxiliar para calcular metade do hull (upper or lower)
    auto hull = [&cross](std::vector<Point> &point) -> std::vector<Point>
    {
        std::vector<Point> result;
        for (const auto &p : point)
        {
            // Enquanto houver pelo menos 2 pontos no hull e o último segmento
            // formar uma curva à direita (ou colinear), remover o último ponto
            while (result.size() >= 2 && cross(result[result.size() - 2], result[result.size() - 1], p) <= 0)
            {
                result.pop_back();
            }
            result.push_back(p);
        }
        return result;
    };

    // Calcula hull superior
    std::vector<Point> upper = hull(points);

    // Calcula hull inferior
    std::reverse(points.begin(), points.end()); // Corrigido: reverte o vetor points
    std::vector<Point> lower = hull(points);

    // Combina hulls superior e inferior, evitando duplicatas nos pontos finais
    std::vector<Point> result;
    result.insert(result.end(), upper.begin(), upper.end());

    // Evita duplicar o último ponto do upper
    if (upper.size() > 1)
        result.insert(result.end(), lower.begin() + 1, lower.end() - 1);

    return result;
}

int main(int argc, char **argv)
{
    // Teste com ponto único/duplicado
    std::vector<Point> teste1 = {{0, 0}, {0, 0}};
    std::vector<Point> result1 = convex_hull(teste1);

    if (result1.size() == 1 && result1[0] == std::make_pair(0, 0))
    {
        std::cout << "Teste1 passou" << '\n';
    }
    else
    {
        std::cout << "Teste1 falhou" << '\n';
    }

    // Teste 2 Grade 10x10
    std::vector<Point> teste2;
    for (int i = 0; i < 100; ++i)
    {
        teste2.emplace_back(i / 10, i % 10);
    }
    std::vector<Point> result2 = convex_hull(teste2);
    std::vector<Point> valores = {{0, 0}, {0, 9}, {9, 9}, {9, 0}};

    if (result2 == valores)
    {
        std::cout << "Teste2 passou" << '\n';
    }
    else
    {
        std::cout << "Teste2 falhou" << '\n';
        std::cout << "Result2: ";
        for (const auto &p : result2)
        {
            std::cout << '(' << p.first << ',' << p.second << ") ";
        }
        std::cout << '\n';
    }

    // Teste 3 valores aleatórios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 10000);

    std::vector<Point> teste3;
    for (int i = 0; i < 10000; ++i)
    {
        teste3.emplace_back(dist(gen), dist(gen));
    }

    std::cout << "Tamanho de convex_hull para 10000 pontos aleatórios: " << convex_hull(teste3).size() << '\n';
    return 0;
}

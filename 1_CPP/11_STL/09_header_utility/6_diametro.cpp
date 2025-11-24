#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

typedef std::pair<double, double> point;

/**
 * @brief Retorna verdadeiro se os três pontos fazem uma curva no sentido horário.
 *
 * @param a Primeiro ponto.
 * @param b Segundo ponto.
 * @param c Terceiro ponto.
 */
bool cw(const point &a, const point &b, const point &c)
{
    return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
}

/**
 * @brief Constrói o casco convexo (algoritmo de Monotone Chain).
 *
 * @param points Vetor de pontos.
 * @return Vetor de pontos que formam o casco convexo.
 */
std::vector<point> convex_hull(std::vector<point> points)
{
    int n = points.size();
    if (n <= 1)
        return points;

    std::sort(points.begin(), points.end());
    std::vector<point> hull;

    // Parte inferior
    for (const auto &p : points)
    {
        while (hull.size() >= 2 && !cw(hull[hull.size() - 2], hull[hull.size() - 1], p))
            hull.pop_back();
        hull.push_back(p);
    }

    // Parte superior
    std::size_t t = hull.size() + 1;
    for (int i = n - 2; i >= 0; --i)
    {
        while (hull.size() >= t && !cw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
            hull.pop_back();
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove ponto duplicado
    return hull;
}

/**
 * @brief Calcula a distância euclidiana entre dois pontos.
 *
 * @param a Primeiro ponto.
 * @param b Segundo ponto.
 * @return A distância entre os pontos.
 */
double distance(const point &a, const point &b)
{
    return std::hypot(a.first - b.first, a.second - b.second);
}

/**
 * @brief Calcula o diâmetro do conjunto de pontos usando o algoritmo de calipers rotativos.
 *
 * @param points Vetor de pontos.
 * @return O diâmetro do conjunto de pontos.
 */
double diametro(const std::vector<point> &points)
{
    std::vector<point> hull = convex_hull(points);
    int n = hull.size();

    if (n == 1)
        return 0.0;

    if (n == 2)
        return distance(hull[0], hull[1]);

    double max_dist = 0.0;
    int j = 1;

    for (int i = 0; i < n; ++i)
    {
        // Encontrar o ponto mais distante de i
        while (true)
        {
            int nj = (j + 1) % n;
            double d1 = distance(hull[i], hull[j]);
            double d2 = distance(hull[i], hull[nj]);

            if (d2 > d1)
                j = nj;
            else
                break;
        }
        max_dist = std::max(max_dist, distance(hull[i], hull[j]));
    }
    return max_dist;
}

int main(int argc, char **argv)
{
    std::vector<point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 1}, {1, 3}, {4, 4}};
    std::cout << "Diâmetro: " << diametro(points) << '\n';

    std::vector<point> points2(4);
    points2[0] = {0, 0};
    points2[1] = {3, 0};
    points2[2] = {0, 3};
    points2[3] = {1, 1};
    std::cout << "Diâmetro: " << diametro(points2) << '\n';
    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <array>

class Distance
{
private:
    // Construtor
    Distance() {}

public:
    /* distância do rei no xadrex */
    static long long
    distanciaDoRei(const std::array<long long, 2> &point1, const std::array<long long, 2> &point2)
    {
        long long x1 = point1[0];
        long long y1 = point1[1];
        long long x2 = point2[0];
        long long y2 = point2[0];
        return std::max(std::abs(x1 - x2), std::abs(y1 - y2));
    }

    /* Distância ao quadrado */
    static double squareDistancia(double x1, double y1, double x2, double y2)
    {
        double x = x1 - x2;
        double y = y1 - y2;
        return (x * x) + (y * y);
    }

    /* Distância Euclediana */
    static double eucledianaDistance(double x1, double y1, double x2, double y2)
    {
        double x = std::pow((x1 - x2), 2);
        double y = std::pow((y1 - y2), 2);
        return std::sqrt(x + y);
    }
};

int main(int argc, char **argv)
{
    /** Distance dist; */ // ERRO: Construtor inacessível por ser private
    std::array<long long, 2> p1 = {2, 3};
    std::array<long long, 2> p2 = {7, 1};

    std::cout << "distancia do Rei: " << Distance::distanciaDoRei(p1, p2) << '\n';
    std::cout << "Distancia ao quadrado: " << Distance::squareDistancia(2.0, 3.0, 7.0, 1.0) << '\n';
    std::cout << "Distância euclediana: " << Distance::eucledianaDistance(2.0, 3.0, 7.0, 1.0) << '\n';
}

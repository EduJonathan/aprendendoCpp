#include <iostream>
#include <random>

/**
 * std::poisson_distribution
 * --------------------------
 * Modela o número de eventos que ocorrem em um intervalo fixo de tempo,
 * quando esses eventos acontecem com uma taxa média constante.
 *
 * Exemplo: número de chamadas recebidas por hora em um call center.
 *
 * Ideal para:
 * - Simular chegadas de eventos (clientes, pacotes, pedidos)
 * - Modelar contagens aleatórias em tempo fixo
 */

static std::mt19937 motor(std::random_device{}());

int gerarEventosPoisson(double taxaLambda)
{
    std::poisson_distribution<int> dist(taxaLambda);
    return dist(motor);
}

int main(int argc, char **argv)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::poisson_distribution<int> dist(4.0); // λ = 4

    for (int i = 0; i < 10; ++i)
        std::cout << dist(gen) << '\n';

    std::cout << "============================================" << '\n';

    const double lambda = 5.0; // média de 5 eventos por intervalo

    int eventos = gerarEventosPoisson(lambda);
    std::cout << "Eventos observados neste intervalo: " << eventos
              << " (λ = " << lambda << ")\n";
    return 0;
}

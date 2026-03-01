#include "filosofo.hpp"
#include <chrono>
#include <random>

void filosofo(Mesa &mesa, int id)
{
    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)) + id);
    std::uniform_real_distribution<double> dist(0.1, 0.5);

    for (int ciclo = 0; ciclo < MAX_CICLOS; ++ciclo)
    {
        // Pensar
        SAFE_COUT("? Filósofo " << id << " está pensando");
        std::this_thread::sleep_for(std::chrono::milliseconds(int(dist(rng) * 1000)));

        // Ficar faminto e tentar comer
        mesa.pegar_garfos(id);

        // Comer
        SAFE_COUT("@ Filósofo " << id << " está comendo");
        std::this_thread::sleep_for(std::chrono::milliseconds(int(dist(rng) * 1000)));

        // Devolver garfos
        mesa.devolver_garfos(id);
    }
}

#include "mesa.hpp"

Mesa::Mesa() { estados.fill(PENSANDO); }

void Mesa::testar(int id)
{
    if (estados[id] == FAMINTO && estados[ESQUERDA(id)] != COMENDO && estados[DIREITA(id)] != COMENDO)
    {
        estados[id] = COMENDO;
        condicoes[id].notify_one();
    }
}

void Mesa::pegar_garfos(int id)
{
    std::unique_lock<std::mutex> lock(mtx);

    estados[id] = FAMINTO;
    SAFE_COUT("# Filósofo " << id << " está com fome");

    testar(id);

    if (estados[id] != COMENDO)
    {
        condicoes[id].wait(lock, [&]
        {
            return estados[id] == COMENDO;
        });
    }
}

void Mesa::devolver_garfos(int id)
{
    std::unique_lock<std::mutex> lock(mtx);

    estados[id] = PENSANDO;
    SAFE_COUT("\nFilósofo " << id << " voltou a pensar");

    testar(ESQUERDA(id));
    testar(DIREITA(id));
}

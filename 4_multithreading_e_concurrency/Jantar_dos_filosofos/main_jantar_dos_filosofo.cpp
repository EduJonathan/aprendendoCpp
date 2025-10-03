#include <thread>
#include <array>
#include <iostream>
#include "mesa.hpp"
#include "filosofo.hpp"

/**
 * O problema dos filósofos jantando é um clássico problema de sincronização
 * em computação concorrente. Cinco filósofos estão sentados ao redor de uma mesa.
 * Entre cada par de filósofos, há um garfo. Cada filósofo alterna entre pensar
 * e comer. Para comer, um filósofo precisa pegar os dois garfos ao seu lado.
 *
 * O desafio é garantir que nenhum filósofo fique com fome indefinidamente (deadlock)
 * e que os filósofos possam comer sem conflitos.
 */

int main(int argc, char **argv)
{
    Mesa mesa;                                      // Mesa compartilhada entre os filósofos
    std::array<std::thread, NUM_FILOSOFOS> threads; // Threads dos filósofos

    // Cria as threads
    for (int i = 0; i < NUM_FILOSOFOS; ++i)
    {
        threads[i] = std::thread(filosofo, std::ref(mesa), i);
    }

    // Aguarda o término
    for (auto &t : threads)
    {
        t.join();
    }

    /**
     * Compile e execute com:
     *
     * g++ -O3 -std=c++20 mesa.cpp filosofo.cpp .\main_jantar_dos_filosofo.cpp -o filosofos.exe -pthread
     * .\filosofos.exe
     */
    return 0;
}

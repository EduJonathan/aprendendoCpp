#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>
#include <array>

/**
 * O problema dos filósofos jantando é um clássico problema de sincronização
 * em computação concorrente. Cinco filósofos estão sentados ao redor de uma mesa.
 * Entre cada par de filósofos, há um garfo. Cada filósofo alterna entre pensar
 * e comer. Para comer, um filósofo precisa pegar os dois garfos ao seu lado.
 *
 * O desafio é garantir que nenhum filósofo fique com fome indefinidamente (deadlock)
 * e que os filósofos possam comer sem conflitos.
 */

constexpr int NUM_FILOSOFOS = 5; /// Número de filósofos (e garfos na mesa).
constexpr int MAX_CICLOS = 50;   // Número máximo de ciclos de pensar/comer para cada filósofo.

/// Estados possíveis de um filósofo
constexpr int PENSANDO = 2;
constexpr int FAMINTO = 1;
constexpr int COMENDO = 0;

/// Funções auxiliares para pegar vizinhos
inline int ESQUERDA(int i) { return (i + NUM_FILOSOFOS - 1) % NUM_FILOSOFOS; }
inline int DIREITA(int i) { return (i + 1) % NUM_FILOSOFOS; }

/// Mutex global para impressão segura no console
std::mutex cout_mtx;
#define SAFE_COUT(x)                              \
    {                                             \
        std::lock_guard<std::mutex> lg(cout_mtx); \
        std::cout << x << '\n';                   \
    }

/**
 * @class Mesa
 * @brief Representa a mesa de jantar onde os filósofos competem por garfos.
 *
 * A mesa gerencia o estado de cada filósofo e usa variáveis de condição
 * para garantir que dois vizinhos não comam ao mesmo tempo.
 */
class Mesa
{
private:
    std::array<int, NUM_FILOSOFOS> estados;                       ///< Estado de cada filósofo
    std::array<std::condition_variable, NUM_FILOSOFOS> condicoes; ///< Condições por filósofo
    std::mutex mtx;                                               ///< Mutex para sincronização interna

    /**
     * @brief Testa se um filósofo pode começar a comer.
     * @param id Identificador do filósofo.
     */
    void testar(int id)
    {
        if (estados[id] == FAMINTO && estados[ESQUERDA(id)] != COMENDO && estados[DIREITA(id)] != COMENDO)
        {
            estados[id] = COMENDO;
            condicoes[id].notify_one();
        }
    }

public:
    /// @brief Construtor: inicializa todos os filósofos como pensando.
    Mesa()
    {
        estados.fill(PENSANDO);
    }

    /**
     * @brief Solicita os garfos para o filósofo.
     * @param id Identificador do filósofo.
     */
    void pegar_garfos(int id)
    {
        std::unique_lock<std::mutex> lock(mtx);
        estados[id] = FAMINTO;
        SAFE_COUT("# Filósofo " << id << " está com fome");

        testar(id);

        if (estados[id] != COMENDO)
        {
            condicoes[id].wait(lock, [this, id]
            {
                return estados[id] == COMENDO;
            });
        }
    }

    /**
     * @brief Devolve os garfos do filósofo.
     * @param id Identificador do filósofo.
     */
    void devolver_garfos(int id)
    {
        std::unique_lock<std::mutex> lock(mtx);
        estados[id] = PENSANDO;
        SAFE_COUT("\nFilósofo " << id << " voltou a pensar");

        testar(ESQUERDA(id));
        testar(DIREITA(id));
    }
};

/**
 * @brief Função executada por cada filósofo.
 *
 * Cada filósofo alterna entre pensar e comer até completar MAX_CICLOS.
 *
 * @param mesa Referência para a mesa compartilhada.
 * @param id Identificador único do filósofo.
 */
void filosofo(Mesa &mesa, int id)
{
    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)) + id);
    std::uniform_real_distribution<double> dist(0.1, 0.5);

    for (int ciclo = 0; ciclo < MAX_CICLOS; ++ciclo)
    {
        // Pensar
        SAFE_COUT("? Filósofo " << id << " está pensando");
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dist(rng) * 1000)));

        // Ficar faminto e tentar comer
        mesa.pegar_garfos(id);

        // Comer
        SAFE_COUT("@ Filósofo " << id << " está comendo");
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(dist(rng) * 1000)));

        // Devolver garfos
        mesa.devolver_garfos(id);
    }
}

int main(int argc, char **argv)
{
    Mesa mesa;                                      /// Mesa compartilhada entre os filósofos
    std::array<std::thread, NUM_FILOSOFOS> threads; ///< Threads dos filósofos

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

    return 0;
}

#pragma once

#include <array>
#include <mutex>
#include <condition_variable>
#include <iostream>

constexpr int NUM_FILOSOFOS = 5; // Número de filósofos (e garfos na mesa).
constexpr int MAX_CICLOS = 50;   // Número máximo de ciclos de pensar/comer para cada filósofo.

// Estados possíveis de um filósofo
constexpr int PENSANDO = 2;
constexpr int FAMINTO = 1;
constexpr int COMENDO = 0;

// Funções auxiliares para pegar vizinhos
inline int ESQUERDA(int i) noexcept { return (i + NUM_FILOSOFOS - 1) % NUM_FILOSOFOS; }
inline int DIREITA(int i) noexcept { return (i + 1) % NUM_FILOSOFOS; }

// Mutex global para impressão segura no console
inline std::mutex cout_mtx;
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
class Mesa {
private:
    std::array<int, NUM_FILOSOFOS> estados;                       // Estado de cada filósofo
    std::array<std::condition_variable, NUM_FILOSOFOS> condicoes; // Condições por filósofo
    std::mutex mtx;                                               // Mutex para sincronização interna

    /**
     * @brief Testa se um filósofo pode começar a comer.
     * @param id Identificador do filósofo.
     */
    void testar(int id);

public:
    /// @brief Construtor: inicializa todos os filósofos como pensando.
    Mesa();

    /**
     * @brief Solicita os garfos para o filósofo.
     * @param id Identificador do filósofo.
     */
    void pegar_garfos(int id);

    /**
     * @brief Devolve os garfos do filósofo.
     * @param id Identificador do filósofo.
     */
    void devolver_garfos(int id);
};

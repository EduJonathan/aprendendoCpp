#pragma once

#include "mesa.hpp"
#include <random>

/**
 * @brief Função executada por cada filósofo.
 *
 * Cada filósofo alterna entre pensar e comer até completar MAX_CICLOS.
 *
 * @param mesa Referência para a mesa compartilhada.
 * @param id Identificador único do filósofo.
 */
void filosofo(Mesa &mesa, int id);

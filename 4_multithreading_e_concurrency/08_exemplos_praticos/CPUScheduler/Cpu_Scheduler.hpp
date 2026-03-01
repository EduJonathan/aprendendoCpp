#ifndef CPU_SCHEDULER_HPP
#define CPU_SCHEDULER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/**
 * @brief Classe que implementa algoritmos de escalonamento de CPU.
 *
 * Suporta múltiplos algoritmos de escalonamento clássicos:
 * - FCFS (First Come First Serve)
 * - SJF (Shortest Job First, não preemptivo)
 * - Round Robin (em implementação futura)
 *
 * Também faz simulação multithread para representar a execução dos processos.
 */
class CPUScheduler
{
private:
    int numProcesses;                 ///< Número de processos
    std::vector<int> burstTimes;      ///< Tempos de burst de cada processo
    std::vector<int> arrivalTimes;    ///< Tempos de chegada de cada processo
    std::vector<int> priorities;      ///< Prioridade de cada processo
    std::vector<int> waitingTimes;    ///< Tempos de espera calculados
    std::vector<int> turnaroundTimes; ///< Tempos de turnaround calculados
    float averageWaitingTime;         ///< Média dos tempos de espera
    float averageTurnaroundTime;      ///< Média dos tempos de turnaround

    /// Calcula as médias de tempo de espera e turnaround
    void calculateAverages();

    /// Exibe os resultados da simulação
    void displayResults();

public:
    /// Construtor
    CPUScheduler();

    /// Coleta os dados dos processos a partir da entrada padrão
    void getData();

    /// Simula escalonamento FCFS
    void fcfs();

    /// Simula escalonamento SJF não preemptivo
    void sjfNonPreemptive();

    /**
     * @brief Simula Round Robin (placeholder).
     *
     * @param quantum Quantum de tempo para alternância entre processos
     */
    void roundRobin(int quantum);
};

#endif

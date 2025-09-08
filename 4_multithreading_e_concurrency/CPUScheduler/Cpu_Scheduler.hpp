#ifndef CPU_SCHEDULER_HPP
#define CPU_SCHEDULER_HPP

#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>
#include <functional>

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

    // Controle de simulação
    std::mutex mtx;
    std::condition_variable cv;
    std::atomic<bool> schedulerRunning{true};
    std::atomic<int> currentTime{0};

    /**
     * @brief Thread de simulação para um processo.
     *
     * @param id Identificador do processo
     * @param burstTime Tempo de execução do processo
     * @param arrivalTime Tempo de chegada do processo
     * @param onComplete Função de callback quando o processo termina
     */
    void processThread(int id, int burstTime, int arrivalTime, std::function<void(int)> onComplete);

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

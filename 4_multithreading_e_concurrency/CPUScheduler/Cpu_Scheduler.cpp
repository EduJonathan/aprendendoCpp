#include <iostream>
#include <algorithm>
#include <chrono>
#include <thread>
#include <numeric>
#include "Cpu_Scheduler.hpp"

/**
 * @brief Construtor padrão que inicializa as variáveis.
 */
CPUScheduler::CPUScheduler() : numProcesses(0), averageWaitingTime(0.0f), averageTurnaroundTime(0.0f) {}

/**
 * @brief Lê dados de burst, chegada e prioridade de cada processo.
 */
void CPUScheduler::getData()
{
    std::cout << "Entre com o número de processos: ";
    std::cin >> numProcesses;

    burstTimes.resize(numProcesses);
    arrivalTimes.resize(numProcesses, 0);
    priorities.resize(numProcesses, 0);
    waitingTimes.resize(numProcesses, 0);
    turnaroundTimes.resize(numProcesses, 0);

    for (int i = 0; i < numProcesses; ++i)
    {
        std::cout << "Tempo de burst para P" << i + 1 << ": ";
        std::cin >> burstTimes[i];
        std::cout << "Tempo de chegada para P" << i + 1 << ": ";
        std::cin >> arrivalTimes[i];
        std::cout << "Prioridade para P" << i + 1 << ": ";
        std::cin >> priorities[i];
    }
}

/**
 * @brief Função executada por cada thread de processo.
 */
void CPUScheduler::processThread(int id, int burstTime, int arrivalTime, std::function<void(int)> onComplete)
{
    std::unique_lock<std::mutex> lock(mtx);

    while (currentTime < arrivalTime)
    {
        cv.wait(lock);
    }

    lock.unlock();
    std::this_thread::sleep_for(std::chrono::milliseconds(burstTime * 100));
    lock.lock();

    waitingTimes[id] = currentTime - arrivalTime;
    turnaroundTimes[id] = waitingTimes[id] + burstTime;

    onComplete(id);
    cv.notify_all();
}

/**
 * @brief Calcula tempos médios de espera e turnaround.
 */
void CPUScheduler::calculateAverages()
{
    float totalWaiting = std::accumulate(waitingTimes.begin(), waitingTimes.end(), 0.0f);
    float totalTurnaround = std::accumulate(turnaroundTimes.begin(), turnaroundTimes.end(), 0.0f);

    averageWaitingTime = totalWaiting / numProcesses;
    averageTurnaroundTime = totalTurnaround / numProcesses;
}

/**
 * @brief Exibe os resultados da simulação em tabela.
 */
void CPUScheduler::displayResults()
{
    std::cout << "\nProcesso\tBurst\tChegada\tEspera\tTurnaround\n";
    for (int i = 0; i < numProcesses; ++i)
    {
        std::cout << "P" << i + 1 << '\t' << burstTimes[i] << '\t' << arrivalTimes[i] << '\t'
                  << waitingTimes[i] << '\t' << turnaroundTimes[i] << '\n';
    }
    std::cout << "Tempo Médio de Espera: " << averageWaitingTime << '\n';
    std::cout << "Tempo Médio de Turnaround: " << averageTurnaroundTime << '\n';
}

/**
 * @brief Simula escalonamento FCFS.
 */
void CPUScheduler::fcfs()
{
    std::cout << "Simulando FCFS...\n";

    std::vector<std::thread> threads;
    std::vector<bool> completed(numProcesses, false);

    // Ordem por tempo de chegada
    std::vector<int> order(numProcesses);
    for (int i = 0; i < numProcesses; ++i)
        order[i] = i;

    std::sort(order.begin(), order.end(), [&](int a, int b)
    {
        return arrivalTimes[a] < arrivalTimes[b];
    });

    // Thread do clock do sistema
    std::thread scheduler([this]()
    {
        while (schedulerRunning)
        {
            std::unique_lock<std::mutex> lock(mtx);
            currentTime++;
            cv.notify_all();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    auto onComplete = [this, &completed](int id)
    {
        completed[id] = true;
        bool allDone = std::all_of(completed.begin(), completed.end(), [](bool c)
        {
            return c;
        });

        if (allDone)
            schedulerRunning = false;
    };

    for (int idx : order)
    {
        threads.emplace_back(&CPUScheduler::processThread, this, idx, burstTimes[idx], arrivalTimes[idx], onComplete);
    }

    for (auto &th : threads)
        th.join();
    scheduler.join();

    calculateAverages();
    displayResults();
}

/**
 * @brief Simula escalonamento SJF não preemptivo.
 */
void CPUScheduler::sjfNonPreemptive()
{
    std::cout << "Simulando SJF Não Preemptivo...\n";

    // TODO: implementar de forma semelhante ao FCFS, mas escolhendo menor burst.
    calculateAverages();
    displayResults();
}

/**
 * @brief Placeholder para Round Robin.
 */
void CPUScheduler::roundRobin(int quantum)
{
    std::cout << "Simulando Round Robin com quantum " << quantum << "...\n";
    /// TODO: implementar round robin
}

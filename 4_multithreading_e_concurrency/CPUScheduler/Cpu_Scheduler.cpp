#include <iostream>
#include <iomanip>
#include <string>
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
    priorities.resize(numProcesses);
    waitingTimes.resize(numProcesses, 0);
    turnaroundTimes.resize(numProcesses, 0);

    for (int i = 0; i < numProcesses; ++i)
    {
        std::cout << "Tempo de burst para P" << i + 1 << ": ";
        std::cin >> burstTimes[i];

        std::cout << "\nTempo de chegada para P" << i + 1 << ": ";
        std::cin >> arrivalTimes[i];

        std::cout << "\nPrioridade para P" << i + 1 << ": ";
        std::cin >> priorities[i];
    }
}

/**
 * @brief Calcula tempos médios de espera e turnaround.
 */
void CPUScheduler::calculateAverages()
{
    float totalW = std::accumulate(waitingTimes.begin(), waitingTimes.end(), 0.0f);
    float totalT = std::accumulate(turnaroundTimes.begin(), turnaroundTimes.end(), 0.0f);
    averageWaitingTime = totalW / numProcesses;
    averageTurnaroundTime = totalT / numProcesses;
}

/**
 * @brief Exibe os resultados da simulação em tabela.
 */
void CPUScheduler::displayResults()
{
    // Largura fixa para cada coluna (ajuste se quiser)
    const int w = 12;

    std::cout << '\n'
              << std::setw(w) << "Processo"
              << std::setw(w) << "Burst"
              << std::setw(w) << "Chegada"
              << std::setw(w) << "Espera"
              << std::setw(w) << "Turnaround"
              << '\n';

    for (int i = 0; i < numProcesses; ++i)
    {
        std::cout << std::setw(w) << ('P' + std::to_string(i + 1))
                  << std::setw(w) << burstTimes[i]
                  << std::setw(w) << arrivalTimes[i]
                  << std::setw(w) << waitingTimes[i]
                  << std::setw(w) << turnaroundTimes[i]
                  << '\n';
    }

    std::cout << '\n'
              << "Tempo Médio de Espera:      " << averageWaitingTime << '\n';
    std::cout << "Tempo Médio de Turnaround: " << averageTurnaroundTime << '\n';
}

/**
 * @brief Simula escalonamento FCFS.
 */
void CPUScheduler::fcfs()
{
    std::cout << "Simulando FCFS...\n";

    std::vector<int> order(numProcesses);
    std::iota(order.begin(), order.end(), 0);

    std::sort(order.begin(), order.end(), [&](int a, int b)
              { return arrivalTimes[a] < arrivalTimes[b]; });

    int time = 0;

    for (int p : order)
    {
        if (time < arrivalTimes[p])
        {
            time = arrivalTimes[p];
        }

        waitingTimes[p] = time - arrivalTimes[p];
        time += burstTimes[p];
        turnaroundTimes[p] = waitingTimes[p] + burstTimes[p];
    }

    calculateAverages();
    displayResults();
}

/**
 * @brief Simula escalonamento SJF não preemptivo.
 */
void CPUScheduler::sjfNonPreemptive()
{
    std::cout << "Simulando SJF Não Preemptivo...\n";

    std::vector<bool> done(numProcesses, false);
    int finished = 0;
    int time = 0;

    while (finished < numProcesses)
    {
        int idx = -1;
        int bestBurst = 1e9;

        for (int i = 0; i < numProcesses; ++i)
        {
            if (!done[i] && arrivalTimes[i] <= time && burstTimes[i] < bestBurst)
            {
                bestBurst = burstTimes[i];
                idx = i;
            }
        }

        if (idx == -1)
        {
            time++;
            continue;
        }

        waitingTimes[idx] = time - arrivalTimes[idx];
        time += burstTimes[idx];
        turnaroundTimes[idx] = waitingTimes[idx] + burstTimes[idx];

        done[idx] = true;
        finished++;
    }

    calculateAverages();
    displayResults();
}

/**
 * @brief Placeholder para Round Robin.
 */
void CPUScheduler::roundRobin(int quantum)
{
    std::cout << "Simulando Round Robin (quantum = " << quantum << ")...\n";

    std::vector<int> remaining = burstTimes;
    std::vector<int> ready;

    int time = 0;
    int completed = 0;

    while (completed < numProcesses)
    {
        for (int i = 0; i < numProcesses; ++i)
        {
            if (arrivalTimes[i] == time)
            {
                ready.push_back(i);
            }
        }

        if (ready.empty())
        {
            time++;
            continue;
        }

        int p = ready.front();
        ready.erase(ready.begin());

        int exec = std::min(quantum, remaining[p]);
        remaining[p] -= exec;
        time += exec;

        for (int i = 0; i < numProcesses; ++i)
        {
            if (arrivalTimes[i] > time - exec && arrivalTimes[i] <= time)
            {
                ready.push_back(i);
            }
        }

        if (remaining[p] == 0)
        {
            turnaroundTimes[p] = time - arrivalTimes[p];
            waitingTimes[p] = turnaroundTimes[p] - burstTimes[p];
            completed++;
        }
        else
        {
            ready.push_back(p);
        }
    }

    calculateAverages();
    displayResults();
}

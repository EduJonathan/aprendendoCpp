#include <iostream>
#include "Cpu_Scheduler.hpp"

/**
 * O algoritmo de escalonamento de CPU (CPU Scheduling) é um componente crítico
 * dos sistemas operacionais que gerencia a execução de processos na CPU.
 * Ele determina a ordem em que os processos são executados, otimizando o uso da CPU
 * e garantindo que todos os processos recebam tempo de CPU adequado.
 *
 * Este programa simula diferentes algoritmos de escalonamento de CPU,
 * incluindo First-Come, First-Served (FCFS), Shortest Job First (SJF) não preemptivo
 * e Round Robin (RR).
 */

int main(int argc, char **argv)
{
    CPUScheduler scheduler;
    int choice = 0;

    do
    {
        std::cout << "\nMENU\n";
        std::cout << "1. Digite os Dados\n";
        std::cout << "2. FCFS\n";
        std::cout << "3. SJF Non-Preemptive\n";
        std::cout << "4. Round Robin\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            scheduler.getData();
            break;

        case 2:
            scheduler.fcfs();
            break;

        case 3:
            scheduler.sjfNonPreemptive();
            break;

        case 4:
        {
            int q = 0;
            std::cout << "Enter quantum: ";
            std::cin >> q;
            scheduler.roundRobin(q);
            break;
        }
        case 5:
            break;

        default:
            std::cout << "Opção inválida!\n";
        }
    } while (choice != 5);
    return 0;
}

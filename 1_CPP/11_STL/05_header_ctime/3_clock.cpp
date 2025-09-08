#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    std::clock_t inicio = std::clock();

    // Simulação de alguma tarefa
    for (int i = 0; i < 1e7; ++i);

    std::clock_t fim = std::clock();
    double tempo = double(fim - inicio) / CLOCKS_PER_SEC;

    std::cout << "Tempo de execução: " << tempo << " segundos\n";

    return 0;
}

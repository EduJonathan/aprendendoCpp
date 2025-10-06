#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

/**
 * std::deque<T> é um container de sequência que permite inserções e remoções rápidas
 * tanto no início quanto no fim, ideal para filas com prioridades variadas.
 */

/**
 * @brief Representa uma tarefa com descrição e prioridade.
 */
struct Tarefa
{
    std::string descricao;
    int prioridade; // 1 é a prioridade mais alta
};

/**
 * @brief Adiciona uma nova tarefa à fila.
 *
 * A inserção respeita o uso da estrutura deque, mas todas as tarefas são adicionadas
 * e depois ordenadas para manter consistência.
 *
 * @param fila Fila de tarefas.
 * @param descricao Descrição da tarefa.
 * @param prioridade Prioridade da tarefa (1 = mais alta).
 */
void adicionarTarefa(std::deque<Tarefa> &fila, const std::string &descricao, int prioridade)
{
    fila.push_back({descricao, prioridade});
}

/**
 * @brief Processa e exibe as tarefas da fila em ordem de prioridade.
 *
 * As tarefas com menor valor de prioridade (mais urgente) são processadas primeiro.
 *
 * @param fila Fila de tarefas a ser processada.
 */
void processarTarefas(std::deque<Tarefa> &fila)
{
    // Ordena da prioridade mais alta (menor valor) para a mais baixa
    std::sort(fila.begin(), fila.end(), [](const Tarefa &a, const Tarefa &b)
    {
        return a.prioridade < b.prioridade;
    });

    while (!fila.empty())
    {
        Tarefa atual = fila.front();
        fila.pop_front();

        // Processa a tarefa atual
        std::cout << "Processando: " << atual.descricao
                  << " (prioridade: " << atual.prioridade << ")\n";
    }
}

int main(int argc, char **argv)
{
    std::deque<Tarefa> filaDeTarefas;

    adicionarTarefa(filaDeTarefas, "Backup", 1);
    adicionarTarefa(filaDeTarefas, "Atualizar documentação", 3);
    adicionarTarefa(filaDeTarefas, "Resolver Bug Crítico", 1);
    adicionarTarefa(filaDeTarefas, "Revisar código", 2);

    processarTarefas(filaDeTarefas);
    return 0;
}

#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>
#include <forward_list>

/**
 * std::forward_list<T> é uma lista simplesmente encadeada com iteração unidirecional.
 * É mais eficiente em termos de memória que std::list, sendo ideal quando só se precisa 
 * percorrer a lista para frente.
 */

using namespace std::chrono;

/**
 * @brief Representa uma tarefa com descrição e horário de execução.
 */
struct Tarefa
{
    std::string descricao;
    system_clock::time_point horario;
};

/**
 * @brief Adiciona uma nova tarefa no início da lista.
 * 
 * @param lista Lista de tarefas.
 * @param descricao Descrição da tarefa.
 * @param horario Horário de execução.
 */
void adicionarTarefa(std::forward_list<Tarefa> &lista, const std::string &descricao,
                     const system_clock::time_point &horario)
{
    lista.push_front({descricao, horario});
}

/**
 * @brief Remove a tarefa mais recentemente adicionada (no início da lista).
 * 
 * @param lista Lista de tarefas.
 */
void removerTarefa(std::forward_list<Tarefa> &lista)
{
    if (!lista.empty())
    {
        lista.pop_front();
    }
    else
    {
        std::cout << "Nenhuma tarefa para remover.\n";
    }
}

/**
 * @brief Exibe todas as tarefas na lista.
 * 
 * @param lista Lista de tarefas.
 */
void exibirTarefas(const std::forward_list<Tarefa> &lista)
{
    if (lista.empty())
    {
        std::cout << "Nenhuma tarefa pendente.\n";
        return;
    }

    std::cout << "Tarefas pendentes:\n";
    
    for (const auto &tarefa : lista)
    {
        auto tempo = system_clock::to_time_t(tarefa.horario);
        std::cout << "- " << tarefa.descricao
                  << " (Horário: " << std::put_time(std::localtime(&tempo), "%H:%M") << ")\n";
    }
}

/**
 * @brief Ordena as tarefas pelo horário (mais cedo primeiro).
 * 
 * @param lista Lista de tarefas.
 */
void ordenarTarefasPorHorario(std::forward_list<Tarefa> &lista)
{
    lista.sort([](const Tarefa &a, const Tarefa &b)
    {
        return a.horario < b.horario;
    });
}

int main(int argc, char **argv)
{
    std::forward_list<Tarefa> listaTarefas;

    // Adiciona tarefas com horários diferentes
    adicionarTarefa(listaTarefas, "Reunião com a equipe", system_clock::now() + hours(2));
    adicionarTarefa(listaTarefas, "Enviar relatório", system_clock::now() + hours(5));
    adicionarTarefa(listaTarefas, "Almoço", system_clock::now() + hours(3));

    std::cout << "\n--- Lista Inicial ---\n";
    exibirTarefas(listaTarefas);

    // Ordena por horário e exibe novamente
    ordenarTarefasPorHorario(listaTarefas);
    std::cout << "\n--- Tarefas Ordenadas ---\n";
    exibirTarefas(listaTarefas);

    // Remove a tarefa mais recente (antes da ordenação)
    std::cout << "\nRemovendo a tarefa mais recente...\n";
    removerTarefa(listaTarefas);

    std::cout << "\n--- Lista Atualizada ---\n";
    exibirTarefas(listaTarefas);

    return 0;
}

#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>

/**
 * Chrono: A biblioteca <chrono> do C++ é uma poderosa ferramenta para lidar
 * com tempo e duração. Ela foi introduzida no C++11 e oferece funcionalidades para
 * medir intervalos de tempo, manipular pontos no tempo e realizar conversões entre
 * diferentes unidades de tempo.
 *
 * Permitindo trabalhar com: Relógios (std::chrono::system_clock, std::chrono::steady_clock,
 * std::chrono::high_resolution_clock) – permitem medir e representar momentos específicos.
 *
 * Durações (std::chrono::duration) – Representam períodos de tempo em diferentes unidades
 * como segundos, milissegundos ou nanosegundos.
 *
 * Pontos no tempo (std::chrono::time_point) – Marcam instantes específicos em relação a um relógio.
 */

int main(int argc, char **argv)
{
    /* std::chrono::steady_clock::now => Retorna um tipo que representa um ponto no tempo */
    auto start_time = std::chrono::steady_clock::now();

    /*
     * Retorna um objeto std::chrono::duration: Que representa o tempo decorrido desde
     * a "época" em uma unidade genérica (normalmente nanosegundos ou segundos dependendo
     * do relógio).
     */
    auto duration_since_epoch = start_time.time_since_epoch();

    /* duration_cast => converte esse tempo para milissegundos. */
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch);

    // count(): retorna o valor do tempo em milissegundos como um tipo numérico que pode ser impresso.
    std::cout << "Tempo desde a época: " << ms.count() << " milissegundos" << '\n';

    // Obter o tempo atual do sistema
    auto now = std::chrono::system_clock::now();

    // std::chrono::system_clock::to_time_t: Converter para o tipo time_t
    std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);

    // Converter para uma string legível
    std::tm *now_tm = std::localtime(&now_time_t);

    // Exibir a data e hora no formato desejado (exemplo: 2025-03-26 14:30:15)
    std::cout << "Data e hora atual: " << std::put_time(now_tm, "%Y-%m-%d %H:%M:%S") << '\n';
    /**
     * para ativar e compilar com o std::put_time
     * g++ -std=c++11 1_chrono.cpp -o nome_executavel
     */

    // ALTERNATIVA: Buffer para armazenar a data e hora formatada, caso não possua opção do std::put_time()
    char buffer[100] = "";

    // Formatar a data e hora
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now_tm);

    // Exibir a data e hora formatada
    std::cout << "Data e hora atual: " << buffer << '\n';
    return 0;
}

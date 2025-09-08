#include <iostream>
#include <chrono>
#include <string>
#include <thread> // Biblioteca para manipulação de threads (para esperar entre ações)

/**
 * O std::this_thread() é um namespace da biblioteca <thread> do C++ que contém funções
 * relacionadas à thread atual, ou seja, à thread que está executando o código
 * naquele momento.
 *
 * Permitindo trabalhar:
 *
 * std::this_thread::sleep_until(time_point) – Pausa a thread até um momento específico.
 * std::this_thread::get_id() – Obtém o identificador da thread atual.
 * std::this_thread::yield() – Indica que a thread atual pode ceder controle para outras threads.
 */

/**
 * @brief Função para tocar um alarme sonoro.
 *        O alarme é emitido 5 vezes com um intervalo de 500 milissegundos entre cada som.
 */
void playAlarm()
{
    // Loop para tocar o alarme 5 vezes
    for (int i = 0; i < 5; ++i)
    {
        // Emite o som de alarme (caractere '\a')
        std::cout << '\a' << std::flush;

        // Pausa de 500 milissegundos entre os alarmes
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

/**
 * @brief Função para iniciar um temporizador.
 *        O temporizador conta o tempo em segundos e exibe o tempo restante no terminal.
 */
void startTimer(int seconds)
{
    std::cout << "Temporizador iniciado para " << seconds << " segundos..." << '\n';

    // Converte os segundos para um tipo de duração de tempo (std::chrono::seconds)
    auto duration = std::chrono::seconds(seconds);

    // Obtém o momento atual para calcular o tempo restante
    auto start = std::chrono::steady_clock::now();

    // Loop para atualizar e mostrar o tempo restante
    while (true)
    {
        // Obtém o momento atual novamente
        auto now = std::chrono::steady_clock::now();

        // Calcula o tempo que passou desde o início
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start);

        // Se o tempo transcorrido for maior ou igual à duração definida, o temporizador termina
        if (elapsed >= duration)
        {
            std::cout << "\nTempo Esgotado!" << '\n'; // Mensagem de fim de tempo
            playAlarm();                              // Chama a função para tocar o alarme
            break;                                    // Sai do loop
        }

        // Calcula o tempo restante
        int remaining = seconds - elapsed.count();

        // Exibe o tempo restante no mesmo lugar do terminal (sobrescrevendo a linha)
        std::cout << "\rTempo restante: " << remaining << " segundos" << std::flush;

        // Pausa por 100 milissegundos antes de atualizar o tempo restante
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main(int argc, char **argv)
{
    int timeInSeconds = 0; // Variável para armazenar o tempo inserido pelo usuário

    // Solicita ao usuário que digite o tempo do temporizador em segundos
    std::cout << "Digite o tempo do temporizador em segundos: ";
    std::cin >> timeInSeconds;

    // Verifica se a entrada é válida (tempo positivo)
    if (timeInSeconds <= 0)
    {
        std::cerr << "Por favor! Insira um valor positivo!" << '\n';
        return 1;
    }

    // Chama a função para iniciar o temporizador com o valor informado
    startTimer(timeInSeconds);

    /** @note Compile o código em seu terminal de seu S.O para melhor visualização */
    return 0;
}

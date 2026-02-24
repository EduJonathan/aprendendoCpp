#include <iostream>
#include <thread>
#include <iomanip>
#include <string>
#include <chrono>

/**
 * O namespace std::chrono_literals fornece *literais de tempo* para facilitar a criação de durações
 * (objetos do tipo std::chrono::duration) de forma simples e legível.
 *
 * Ao incluir:
 *     using namespace std::chrono_literals;
 *
 * é possível usar sufixos como:
 *     - h   → horas           (std::chrono::hours)
 *     - min → minutos         (std::chrono::minutes)
 *     - s   → segundos        (std::chrono::seconds)
 *     - ms  → milissegundos   (std::chrono::milliseconds)
 *     - us  → microssegundos  (std::chrono::microseconds)
 *     - ns  → nanossegundos   (std::chrono::nanoseconds)
 *
 * Exemplo:
 *     using namespace std::chrono_literals;
 *
 *     auto t1 = 10s;    // 10 segundos → std::chrono::seconds
 *     auto t2 = 500ms;  // 500 milissegundos → std::chrono::milliseconds
 *
 * Esses objetos podem ser usados diretamente em funções como:
 *     std::this_thread::sleep_for(2s);
 *
 * Observação:
 * - As literais de tempo estão disponíveis desde o C++14.
 * - São definidas no namespace: std::literals::chrono_literals
 */

using namespace std::chrono_literals; // Permite 2s, 500ms, etc.

/**
 * @brief Função de delay usando literais de tempo. Permite chamar delay(2s) ou delay(500ms) de forma intuitiva
 *
 * A função é sobrecarregada para aceitar tanto std::chrono::milliseconds quanto um valor em segundos (double).
 * Isso demonstra a flexibilidade dos literais de tempo para criar durações de forma legível e fácil de entender.
 *
 * @param ms Duração em milissegundos (std::chrono::milliseconds)
 */
void delay(std::chrono::milliseconds ms)
{
    std::this_thread::sleep_for(ms);
}

/**
 * @brief Função de delay usando literais de tempo. Permite chamar delay(2s) ou delay(500ms) de forma intuitiva
 *
 * A função é sobrecarregada para aceitar tanto std::chrono::milliseconds quanto um valor em segundos (double).
 * Isso demonstra a flexibilidade dos literais de tempo para criar durações de forma legível e fácil de entender.
 *
 * @param seconds Duração em segundos (double)
 */
void delay(double seconds)
{
    std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}

/**
 * @brief Exibe uma barra de progresso animada no console, usando um símbolo personalizado e um tempo total definido.
 * A função divide o tempo total em partes iguais para cada símbolo da barra, criando uma animação suave de progresso.
 *
 * @param total_segundos Tempo total para completar a barra de progresso, em segundos
 * @param simbolo Caractere a ser usado para preencher a barra de progresso (padrão: '#')
 */
void barraProgresso(int total_segundos, char simbolo = '#')
{
    const int largura = 40;
    std::cout << "Carregando: [";

    for (int i = 0; i <= largura; ++i)
    {
        std::cout << simbolo;
        std::cout.flush();
        std::this_thread::sleep_for(total_segundos * 1.0s / largura);
    }
    std::cout << "] Concluído!\n";
}
/**
 * @brief Exibe uma contagem regressiva no console, usando literais de tempo para definir os intervalos de espera entre cada número.
 * A função imprime os números de forma decrescente, aguardando um segundo entre cada número, e finaliza com uma mensagem de "Vai!".
 *
 * @param segundos Número de segundos para a contagem regressiva, que define o ponto de partida da contagem.
 * A função irá imprimir os números de forma decrescente até chegar a 1, aguardando um segundo entre cada número,
 * e finaliza com uma mensagem de "Vai!".
 */
void contagemRegressiva(int segundos)
{
    std::cout << "Iniciando em: ";
    for (int i = segundos; i > 0; --i)
    {
        std::cout << i << "... ";
        std::cout.flush();
        std::this_thread::sleep_for(1s);
    }
    std::cout << "Vai!\n";
}

/**
 * @brief Função que demonstra o uso de delays e animações com literais de tempo.
 * A função exibe uma série de animações e delays para ilustrar como os literais de tempo podem ser usados em aplicações práticas.
 */
void carragando()
{
    std::cout << "=== EXEMPLO DE DELAYS E ANIMAÇÕES ===\n\n";

    // 1. Contagem regressiva
    contagemRegressiva(3);

    // 2. Delay fixo
    std::cout << "\nEsperando 2 segundos...\n";
    delay(2s);
    std::cout << "Pronto após 2s!\n\n";

    // 3. Barra de progresso (10 segundos)
    std::cout << "Executando tarefa longa...\n";
    barraProgresso(10, '=');
    std::cout << "Tarefa finalizada!\n\n";

    // 4. Delay em milissegundos
    std::cout << "Piscando em 500ms...\n";
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "   ON  ";
        std::cout.flush();
        delay(500ms);
        std::cout << "\r   OFF ";
        std::cout.flush();
        delay(500ms);
    }
    std::cout << "\n\nFim do exemplo!\n";
}

int main(int argc, char **argv)
{
    carragando();

    std::chrono::seconds tempo(10);
    std::chrono::milliseconds espera(500);

    // Exemplo de uso:
    std::cout << "Tempo: " << tempo.count() << " segundos\n";
    std::cout << "Espera: " << espera.count() << " milissegundos\n";
    return 0;
}


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

// Função de delay simples
void delay(std::chrono::milliseconds ms)
{
    std::this_thread::sleep_for(ms);
}

void delay(double seconds)
{
    std::this_thread::sleep_for(std::chrono::duration<double>(seconds));
}

// Barra de progresso animada
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

// Contagem regressiva
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

// Exemplo de uso com animação
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

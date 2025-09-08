#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

// Gera número aleatório entre min e max
int tempoAleatorio(int minSeg, int maxSeg)
{
    return minSeg + rand() % (maxSeg - minSeg + 1);
}

// Escolhe uma mensagem aleatória para o turno
std::string mensagemAleatoria()
{
    std::vector<std::string> mensagens = {
        "Analisando inimigos...",
        "Verificando habilidades...",
        "Considerando usar item...",
        "Calculando estratégia...",
        "Avaliando posição no campo...",
        "Tentando lembrar o plano...",
        "Verificando inventário...",
        "Pensando profundamente...",
        "Fingindo estar calmo..."};

    return mensagens[rand() % mensagens.size()];
}

int main(int argc, char **argv)
{
    std::srand(std::time(nullptr)); // Inicializa gerador aleatório

    const int tempoTotalSegundos = 120; // 2 minutos
    const int minTurnoSegundos = 25;
    const int maxTurnoSegundos = 35;

    int tempoRestante = tempoTotalSegundos;
    int numeroDoTurno = 1;

    std::cout << "=== Simulador de Jogo por Turnos ===" << '\n';
    std::cout << "Duração total: " << tempoTotalSegundos / 60 << " minutos\n";
    std::cout << "Turnos variam de " << minTurnoSegundos << " a " << maxTurnoSegundos << " segundos\n\n";

    while (tempoRestante >= minTurnoSegundos)
    {
        int duracaoTurno = tempoAleatorio(minTurnoSegundos, maxTurnoSegundos);

        std::cout << "Turno " << numeroDoTurno << " iniciado." << '\n';
        std::cout << mensagemAleatoria() << " (" << duracaoTurno << " segundos)\n";

        // Simula progresso em tempo real com pontos
        for (int i = 0; i < duracaoTurno; ++i)
        {
            std::cout << "." << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); // 0.5s entre pontos
            if (i % 6 == 5)
                std::cout << "\n"; // Quebra linha a cada 6 segundos
        }

        std::cout << "\nTurno " << numeroDoTurno << " finalizado. Tempo restante: "
                  << tempoRestante / 60 << "m " << tempoRestante % 60 << "s\n\n";

        tempoRestante -= duracaoTurno;
        numeroDoTurno++;
    }

    std::cout << "=== Fim do jogo! Tempo esgotado. ===" << '\n';
    return 0;
}

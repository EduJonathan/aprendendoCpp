#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std::chrono_literals;

// ==================== CONFIGURAÇÕES ====================
const int TEMPO_TOTAL_JOGO = 120;    // 2 minutos no total
const int TEMPO_PENSAR_JOGADOR = 50; // Você tem 50s por turno!
const int MIN_TURNO_IA = 8;
const int MAX_TURNO_IA = 20;

// ==================== GERADOR ALEATÓRIO MODERNO ====================
class Random
{
    std::random_device rd;
    std::mt19937 gen{rd()};

public:
    int tempo(int min, int max)
    {
        std::uniform_int_distribution<> d(min, max);
        return d(gen);
    }

    std::string mensagem()
    {
        const std::vector<std::string> msgs = {
            "Analisando o campo de batalha...",
            "Calculando dano crítico...",
            "Procurando fraquezas do inimigo...",
            "Decidindo entre ataque ou defesa...",
            "Consultando o grimório de magias...",
            "Fingindo confiança total...",
            "Relembrando o tutorial de 3 horas...",
            "Olhando nervosamente para o relógio..."};
        std::uniform_int_distribution<> d(0, msgs.size() - 1);
        return msgs[d(gen)];
    }
};

// ==================== TEMPORIZADOR DO JOGADOR (com barra) ====================
class TemporizadorJogador
{
    std::atomic<int> segundos{TEMPO_PENSAR_JOGADOR};
    std::atomic<bool> acabou{false};
    std::thread worker;

public:
    TemporizadorJogador()
    {
        worker = std::thread([this]()
        {
            for (int s = TEMPO_PENSAR_JOGADOR; s >= 0; --s)
            {
                segundos.store(s);
                if (acabou.load()) break;
                std::this_thread::sleep_for(1s);
            }
            acabou = true;
        });
    }

    ~TemporizadorJogador()
    {
        acabou = true;
        if (worker.joinable())
            worker.join();
    }

    void imprimirBarra() const
    {
        int atual = segundos.load();
        const int largura = 40;
        int preenchido = static_cast<int>(std::round((static_cast<double>(atual) / TEMPO_PENSAR_JOGADOR) * largura));

        std::cout << "\rTempo para decidir: ["
                  << std::string(preenchido, '#')
                  << std::string(largura - preenchido, ' ')
                  << "] " << std::setw(2) << atual << "s " << std::flush;
    }

    bool expirou() const { return acabou.load(); }
    int restante() const { return segundos.load(); }
    void parar() { acabou = true; }
};

// ==================== MAIN ====================
int main()
{
    Random rnd;
    std::atomic<int> tempo_total{TEMPO_TOTAL_JOGO};
    int turno = 1;

    std::cout << "================================================\n";
    std::cout << "   SIMULADOR DE JOGO POR TURNOS COM PRESSÃO   \n";
    std::cout << "================================================\n";
    std::cout << "Tempo total da partida: 2 minutos\n";
    std::cout << "Você tem até 50 segundos por turno para decidir!\n\n";

    while (tempo_total > 0)
    {
        std::cout << ">>> TURNO " << turno << " <<<\n";

        TemporizadorJogador timer;
        int tempo_ia = rnd.tempo(MIN_TURNO_IA, MAX_TURNO_IA);

        std::atomic<bool> ia_pronta{false};
        std::atomic<bool> jogador_decidiu{false};
        std::atomic<bool> encerrar_turno{false};

        // ---- IA ----
        std::thread ia([&]()
        {
            std::cout << rnd.mensagem() << " (IA pensando por " << tempo_ia << "s)\n";
            for (int i = 0; i < tempo_ia * 2; ++i)
            {
                if (encerrar_turno.load()) return; // IA para se jogador decidir
                std::this_thread::sleep_for(500ms);
                std::cout << '.' << std::flush;
                if (i % 20 == 19) std::cout << '\n';
            }
            std::cout << '\n';
            ia_pronta = true;
            encerrar_turno = true;
        });

        // ---- INPUT DO JOGADOR ----
        std::thread input([&]() 
        {
            std::cout << "Sua vez! Pressione ENTER quando decidir sua ação...\n";
            std::cin.get();
            if (!encerrar_turno.load())
            {
                jogador_decidiu = true;
                encerrar_turno = true; // Jogador para a IA
            }
        });

        // ---- LOOP DO TURNO ----
        while (!encerrar_turno && !timer.expirou())
        {
            timer.imprimirBarra();
            std::this_thread::sleep_for(100ms);
        }
        std::cout << "\n\n";

        // Parar timer
        timer.parar();

        // Garantir que tudo terminou
        encerrar_turno = true;
        if (input.joinable())
            input.join();
        if (ia.joinable())
            ia.join();

        // ---- RESULTADO ----
        if (jogador_decidiu && timer.restante() > 0)
        {
            std::cout << "✔ Você decidiu a tempo! (restavam "
                      << timer.restante() << "s)\n";
            std::cout << "Você tomou iniciativa antes da IA.\n";
        }
        else if (ia_pronta)
        {
            std::cout << "✖ A IA agiu primeiro!\n";
        }
        else
        {
            std::cout << "⏳ Tempo esgotado! Você não decidiu a tempo.\n";
        }

        // ---- CALCULAR TEMPO GASTO NO TURNO ----
        int tempo_gasto_jogador = TEMPO_PENSAR_JOGADOR - timer.restante();
        int tempo_gasto = std::max(tempo_ia, tempo_gasto_jogador);

        tempo_total -= tempo_gasto;

        // Impede ficar negativo (correção importante)
        if (tempo_total < 0)
            tempo_total = 0;

        std::cout << "Tempo restante na partida: "
                  << tempo_total / 60 << "m " << tempo_total % 60 << "s\n\n";
    }

    std::cout << "================================================\n";
    std::cout << "           FIM DA PARTIDA! Tempo esgotado.     \n";
    std::cout << "================================================\n";

    return 0;
}

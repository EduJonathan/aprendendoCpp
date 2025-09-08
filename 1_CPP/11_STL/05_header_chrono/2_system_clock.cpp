#include <iostream>
#include <ctime>
#include <chrono>

/**
 * O std::chrono::system_clock(): é um dos relógios disponíveis na biblioteca <chrono>
 * do C++. Ele representa o relógio do sistema operacional e é usado para obter a data
 * e a hora atuais.
 * Pode sofrer ajustes pelo sistema operacional, como mudanças no horário devido à
 * sincronização com servidores NTP ou alterações manuais feitas pelo usuário.
 *
 * Isso o torna adequado para capturar horários e datas, mas menos confiável para medir
 * intervalos de tempo com precisão.
 */

int main(int argc, char **argv)
{
    // Obtendo o ponto de tempo atual
    auto agora = std::chrono::system_clock::now();

    // Convertendo para tempo "legível"
    auto hoje = std::chrono::system_clock::to_time_t(agora);
    std::cout << "HOJE é: " << std::ctime(&hoje);

    // Calculando a data de ontem (subtraindo 1 dia)
    auto ontem = agora - std::chrono::hours(24); // 24 horas para o dia anterior
    auto ontem_time_t = std::chrono::system_clock::to_time_t(ontem);
    std::cout << "ONTEM foi: " << std::ctime(&ontem_time_t);

    // Calculando a data de amanhã (adicionando 1 dia)
    auto amanha = agora + std::chrono::hours(24); // 24 horas para o dia seguinte
    auto amanha_time_t = std::chrono::system_clock::to_time_t(amanha);
    std::cout << "AMANHÃ será: " << std::ctime(&amanha_time_t);

    return 0;
}

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <locale>
#include <chrono>

/**
 * O std::put_time é um manipulador de saída em C++ (C++11+), semelhante ao std::strftime() e std::get_time().
 * Ele é usado para formatar objetos de tempo (std::tm) ao escrever em fluxos de saída, como std::cout ou std::ostringstream.
 *
 * Funciona de forma semelhante ao strftime, mas é integrado ao sistema de streams,
 * permitindo expressões como: std::cout << std::put_time(&tempo, "%d/%m/%Y %H:%M:%S");
 *
 * Principais códigos de formatação:
 * +--------+--------------------------+------------+
 * │ Código │ Significado              │ Exemplo    │
 * +--------+--------------------------+------------+
 * │ %d     │ Dia do mês (2 díg.)      │ 29         │
 * +--------+--------------------------+------------+
 * │ %m     │ Mês (2 díg.)             │ 10         │
 * +--------+--------------------------+------------+
 * │ %Y     │ Ano (4 díg.)             │ 2025       │
 * +--------+--------------------------+------------+
 * │ %H     │ Hora (24h)               │ 15         │
 * +--------+--------------------------+------------+
 * │ %M     │ Minutos                  │ 03         │
 * +--------+--------------------------+------------+
 * │ %S     │ Segundos                 │ 00         │
 * +--------+--------------------------+------------+
 *
 * Exemplo:
 *     std::time_t agora = std::time(nullptr);
 *     std::tm* tempo = std::localtime(&agora);
 *     std::cout << "Data e hora atual: " << std::put_time(tempo, "%d/%m/%Y %H:%M:%S") << '\n';
 *
 * Observação:
 * - std::put_time respeita o locale configurado no stream, permitindo exibir nomes de meses e dias em diferentes idiomas.
 */

// Função para configurar locale global (opcional, mas recomendado)
void configurarLocale()
{
    try
    {
        std::locale::global(std::locale("pt_BR.UTF-8")); // Linux/macOS
    }
    catch (...)
    {
        try
        {
            std::locale::global(std::locale("Portuguese_Brazil")); // Windows
        }
        catch (...)
        {
            std::cerr << "Aviso: Locale pt_BR não disponível. Usando padrão (inglês).\n";
        }
    }

    // Garante que cout use o locale global
    std::cout.imbue(std::locale());
}

// Função para ler uma data/hora formatada do usuário
// Função para ler data/hora SEM segundos
std::tm lerDataHora()
{
    std::tm tm = {};
    std::string entrada;

    while (true)
    {
        std::cout << "Digite a data e hora (dd/mm/aaaa HH:MM): ";
        std::getline(std::cin, entrada);

        std::istringstream ss(entrada);

        // Tenta ler: dia/mês/ano hora:minuto [segundos opcionais]
        ss >> std::get_time(&tm, "%d/%m/%Y %H:%M");

        if (ss.fail())
        {
            std::cerr << "Erro no formato! Use: dd/mm/aaaa HH:MM\n";
            continue;
        }

        // Se houver segundos (ex: 23:59:45), ignore-os
        if (!ss.eof())
        {
            char colon;
            int segundos;
            if (ss >> colon >> segundos && colon == ':')
            {
                // Segundos lidos, mas ignorados
                tm.tm_sec = 0; // Força 0
            }
            else
            {
                std::cerr << "Ignorando dados extras após HH:MM.\n";
            }
        }
        else
        {
            tm.tm_sec = 0; // Sem segundos → 00
        }

        // Validação básica
        if (tm.tm_year < 100 || tm.tm_year > 3000 - 1900 ||
            tm.tm_mon < 0 || tm.tm_mon > 11 ||
            tm.tm_mday < 1 || tm.tm_mday > 31 ||
            tm.tm_hour < 0 || tm.tm_hour > 23 ||
            tm.tm_min < 0 || tm.tm_min > 59)
        {
            std::cerr << "Data/hora fora do intervalo válido!\n";
            continue;
        }

        tm.tm_sec = 0;    // Garante segundos = 0
        tm.tm_isdst = -1; // Deixa o sistema decidir (horário de verão)

        break;
    }

    return tm;
}

// Função para formatar um std::tm como string
std::string formatarDataHora(const std::tm &tm)
{
    char buffer[256];

    // Remove os segundos da saída
    std::strftime(buffer, sizeof(buffer), "%A, %d de %B de %Y às %H:%M", &tm);
    return std::string(buffer);
}

int main(int argc, char **argv)
{
    configurarLocale(); // Ativa português

    // --- Hora atual (thread-safe com C++11+) ---
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm *local_now = std::localtime(&t); // Ainda não thread-safe, mas comum em main()

    std::cout << "Data e hora atual com std:put_time(): "
              << std::put_time(local_now, "%d/%m/%Y %H:%M:%S")
              << '\n';

    // --- Ler do usuário ---
    std::tm dataHora = lerDataHora();
    std::string formatada = formatarDataHora(dataHora);
    std::cout << "Data formatada: " << formatada << '\n';
    return 0;
}

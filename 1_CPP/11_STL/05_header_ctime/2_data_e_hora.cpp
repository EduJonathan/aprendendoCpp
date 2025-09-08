#include <iostream>
#include <ctime>

int main(int argc, char **argv)
{
    std::time_t agora = std::time(nullptr);
    std::tm *tempoLocal = std::localtime(&agora);

    std::cout << "Ano: " << (tempoLocal->tm_year + 1900) << '\n';
    std::cout << "Mês: " << (tempoLocal->tm_mon + 1) << '\n';
    std::cout << "Dia: " << tempoLocal->tm_mday << '\n';
    std::cout << "Hora: " << tempoLocal->tm_hour << '\n';
    std::cout << "Minuto: " << tempoLocal->tm_min << '\n';
    std::cout << "Segundo: " << tempoLocal->tm_sec << '\n';

    return 0;
}

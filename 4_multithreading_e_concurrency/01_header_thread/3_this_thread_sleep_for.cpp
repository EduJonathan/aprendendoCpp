#include <iostream>
#include <chrono>
#include <thread>

/**
 * std::this_thread::sleep_for é uma função que faz a thread atual "dormir" por um período de tempo especificado.
 * Isso é útil para simular atrasos, controlar a taxa de execução ou esperar por eventos.
 */

int main(int argc, char **argv)
{
    std::cout << "Thread vai dormir por 2 segundos.." << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Acordei depois de 2 segundos!" << '\n';
    return 0;
}

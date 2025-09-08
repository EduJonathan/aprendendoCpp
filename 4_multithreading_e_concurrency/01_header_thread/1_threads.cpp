#include <iostream>
#include <chrono>
#include <thread>

// Threads são unidades de execução que permitem a execução concorrente de código.

void function_thread(void)
{
    std::cout << "A thread Iniciou" << '\n';
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "A Thread Terminou" << '\n';
}

int main(int argc, char **argv)
{
    std::cout << "Iniciar Thread Principal" << '\n';
    std::thread thread1(function_thread);

    thread1.join();
    std::cout << "Thread Joined" << '\n';

    std::thread thread2(function_thread);
    thread2.detach();
    std::cout << "Thread Detached" << '\n';

    std::cout << "Terminar Thread Principal" << '\n';

    return 0;
}

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> contador{0};

void incrementar()
{
    for (int i = 0; i < 1000; ++i)
        contador++;
}

int main(int argc, char **argv)
{
    std::thread t1(incrementar), t2(incrementar);
    t1.join();
    t2.join();
    std::cout << "Contador final: " << contador << '\n';

    /**
     * Compile e execute
     * g++ -std=c++17 razoes_e_fracoes.cpp -o razoes_e_fracoes -pthread
     * ./razoes_e_fracoes
     */

    return 0;
}

#include <iostream>
#include <thread>
#include <semaphore>

std::counting_semaphore<2> sem(2); // até 2 threads por vez

void tarefa(int id)
{
    sem.acquire();
    std::cout << "Thread " << id << " entrou\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " saiu\n";
    sem.release();
}

int main(int argc, char **argv)
{
    std::thread t1(tarefa, 1), t2(tarefa, 2), t3(tarefa, 3);
    t1.join();
    t2.join();
    t3.join();

    /**
     * Compile e execute
     * g++ -std=c++20 controle_de_acesso.cpp -o controle_de_acesso -pthread
     * ./controle_de_acesso
     */

    return 0;
}

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>

std::mutex m;
std::condition_variable cv;
std::queue<int> fila;

void produtor()
{
    std::unique_lock<std::mutex> lock(m);
    fila.push(10);
    cv.notify_one(); // avisa consumidor
}

void consumidor()
{
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, [] 
    {
        return !fila.empty();
    });

    std::cout << "Consumido: " << fila.front() << '\n';
    fila.pop();
}

int main(int argc, char **argv)
{
    std::thread t1(produtor), t2(consumidor);
    t1.join();
    t2.join();
    return 0;
}

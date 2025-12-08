#include <iostream>
#include <thread>
#include <mutex>

std::mutex &f()
{
    static std::mutex m;
    return m;
}

int main(int argc, char const *argv[])
{
    std::thread t1([]
                   {
        std::lock_guard<std::mutex> lg(f());
        std::cout << "Thread 1 acquired the lock." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Thread 1 releasing the lock." << std::endl; });
    return 0;
}

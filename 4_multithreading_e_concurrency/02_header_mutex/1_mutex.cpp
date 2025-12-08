#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;     // Mutex for protecting shared data
int sharedData = 0; // Shared data among threads

void incrementSharedData(int n, const std::string &threadName)
{
    for (int i = 0; i < n; ++i)
    {
        mtx.lock();
        ++sharedData;
        std::cout << threadName << " increments value to " << sharedData << '\n';
        mtx.unlock();
    }
}

int main(int argc, char **argv)
{
    std::thread t1(incrementSharedData, 5, "Thread 1");
    std::thread t2(incrementSharedData, 5, "Thread 2");

    t1.join();
    t2.join();

    return 0;
}

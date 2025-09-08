#include <iostream>
#include <future>

int tarefa()
{
    return 42;
}

int main(int argc, char **argv)
{
    std::future<int> f = std::async(tarefa);
    std::cout << "Resultado futuro: " << f.get() << '\n';
}

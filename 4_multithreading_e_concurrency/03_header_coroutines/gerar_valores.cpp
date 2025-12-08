#include <iostream>
#include <coroutine>
#include <optional>

struct Generator
{
    struct promise_type
    {
        int current_value;
        std::suspend_always yield_value(int value)
        {
            current_value = value;
            return {};
        }
        std::suspend_always initial_suspend() { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        Generator get_return_object() { return Generator{this}; }
        void return_void() {}
        void unhandled_exception() { std::exit(1); }
    };

    promise_type *promise;
    Generator(promise_type *p) : promise(p) {}
};

Generator contador(int n)
{
    for (int i = 1; i <= n; ++i)
        co_yield i; // "pausa" e retorna valor
}

int main(int argc, char **argv)
{
    auto gen = contador(3);
    std::cout << "Gerou: " << gen.promise->current_value << '\n';

    /**
     * Compile e execute
     * g++ -std=c++17 gerar_valores.cpp -o gerar_valores -pthread
     * ./gerar_valores
     */
    return 0;
}

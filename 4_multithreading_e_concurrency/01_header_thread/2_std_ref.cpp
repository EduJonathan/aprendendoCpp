#include <iostream>
#include <thread>

/**
 * std::ref é uma função que cria um objeto std::reference_wrapper. Isso é útil para passar
 * referências para funções que esperam argumentos por valor.
 *
 * Permitindo passar referências para variáveis sem copiá-las.
 */

void square(int num, int &result)
{
    auto compute = [](int n) -> int
    {
        return n * n;
    };

    result = compute(num);
}

int main(int argc, char **argv)
{
    int result = 0;
    std::thread t(square, 5, std::ref(result));
    t.join();
    std::cout << "O quadrado de 5 é: " << result << '\n';
    return 0;
}

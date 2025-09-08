#include <iostream>
#include <functional>

/*
 * std::function<class _Fp>: Classe que armazena funções, lambdas ou objetos funcionais.
 * É útil para passar funções como argumentos e para permitir maior flexibilidade na
 * programação funcional e otimizações.
 */

void sayHello()
{
    std::cout << "Olá, mundo!" << '\n';
}

inline float mult(float a, float b)
{
    return a * b;
}

int main(int argc, char **argv)
{
    // Armazena a função sayHello
    std::function<void()> func = sayHello;
    func(); // Chama a função armazenada

    // Use lambda para passar os argumentos para mult
    std::function<float()> adicao = []()
    {
        return mult(4.0f, 5.0f);
    };
    std::cout << "Resultado da adição: " << adicao() << '\n';

    return 0;
}

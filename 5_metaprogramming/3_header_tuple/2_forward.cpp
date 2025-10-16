#include <tuple>
#include <utility>
#include <iostream>

/**
 * std::forward: Esta função demonstra o uso de std::forward para manter as qualidades de valor (lvalue ou rvalue)
 * dos argumentos passados para uma função genérica (forwarding/passthrough function).
 *
 * O std::forward é essencial quando queremos passar adiante argumentos perfeitos (perfect forwarding),
 * ou seja, preservar se um argumento foi passado como lvalue ou rvalue.
 *
 * No contexto dessa função:
 * - Func &&f é um parâmetro universal (também chamado de forwarding reference).
 * - Args &&...args são parâmetros universais variádicos.
 *
 * A chamada:
 *   std::forward<Func>(f)
 *   std::forward<Args>(args)...
 * garante que os argumentos sejam encaminhados para std::apply com o mesmo tipo de valor
 * com que foram recebidos (lvalue ou rvalue), evitando cópias desnecessárias ou perdas de eficiência.
 *
 * O uso de std::make_tuple aqui força a cópia/movimentação dos argumentos para dentro de um tuple,
 * mas o uso de std::forward ajuda a evitar cópias desnecessárias quando possível.
 */

template <typename Func, typename... Args>
void applyFunc(Func &&f, Args &&...args)
{
    auto tuple = std::make_tuple(std::forward<Args>(args)...);
    std::apply(std::forward<Func>(f), tuple);
}

void someFunction(int a, double b)
{
    std::cout << "someFunction called with a = " << a << ", b = " << b << '\n';
}

int main(int argc, char **argv)
{
    applyFunc(someFunction, 42, 3.14);
    return 0;
}

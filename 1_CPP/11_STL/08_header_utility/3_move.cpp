#include <iostream>
#include <string>
#include <memory>
#include <utility>

/**
 * std::move(): É utilizado para transferir a posse de recursos entre objetos de forma
 * eficiente, sem copiar os dados, eficiente ao evitar cópias desnecessárias, funciona
 * com objetos que podem ser movidos, como strings, vetores, etc.
 */

int main(int argc, char **argv)
{
    std::string original = "Texto original";
    std::string moved = std::move(original);

    std::cout << "Movido: " << moved << '\n';
    std::cout << "Original (após mover): " << original << '\n';

    auto move_lambda = [](auto &&x) -> decltype(auto)
    {
        return std::move(x);
    };

    std::unique_ptr<int> p1 = std::make_unique<int>(42);
    std::unique_ptr<int> p2 = move_lambda(p1); // Move o ponteiro de p1 para p2

    if (p1)
    {
        std::cout << "p1 ainda possui o objeto: " << *p1 << '\n';
    }
    else
    {
        std::cout << "p1 foi movido e está vazio" << '\n';
    }

    if (p2)
    {
        std::cout << "p2 possui o objeto: " << *p2 << '\n';
    }
    else
    {
        std::cout << "p2 está vazio" << '\n';
    }

    std::shared_ptr<int> sp1 = std::make_shared<int>(100);
    std::shared_ptr<int> sp2 = sp1; // cópia simples — ambos compartilham o objeto

    std::cout << "sp1 conta: " << sp1.use_count() << ", valor: " << *sp1 << '\n';
    std::cout << "sp2 conta: " << sp2.use_count() << ", valor: " << *sp2 << '\n';

    std::shared_ptr<int> sp3 = move_lambda(sp1); // move sp1 para sp3

    std::cout << "Após move:" << '\n';
    std::cout << "sp1 conta: " << (sp1 ? sp1.use_count() : 0) << '\n';
    std::cout << "sp3 conta: " << sp3.use_count() << ", valor: " << *sp3 << '\n';
    return 0;
}

#include <iostream>
#include <string>
#include <variant>

/**
 * std::visit:
 * -----------------
 *
 * std::visit é uma função utilitária do C++17 que aplica um functor (função ou lambda)
 * ao valor armazenado em um std::variant.
 *
 * Isso permite manipular o conteúdo do variant sem precisar saber explicitamente
 * qual tipo ele contém — o despacho de tipo é feito automaticamente.
 */

// Functor (struct com operator()) usado em std::visit sem lambda
struct PrintVisitor
{
    void operator()(int value) const { std::cout << "int: " << value << '\n'; }
    void operator()(double value) const { std::cout << "double: " << value << '\n'; }
    void operator()(const std::string &value) const { std::cout << "string: " << value << '\n'; }
};

// Cria e retorna um variant com base em uma escolha
std::variant<int, double, std::string> visit_sem_lambda(int choice)
{
    switch (choice)
    {
    case 0:
        return 42;
    
    case 1:
        return 3.1415;

    case 2:
        return std::string("Olá, std::visit!");

    default:
        return -1; // Valor padrão (int)
    }
}

// Usa std::visit com uma lambda genérica
void visit_com_lambda(const std::variant<int, double, std::string> &var)
{
    std::visit([](auto &&arg)
    {
        std::cout << "Valor visitado: " << arg << '\n';
    }, var);
}

int main(int argc, char **argv)
{
    auto v1 = visit_sem_lambda(0);
    auto v2 = visit_sem_lambda(1);
    auto v3 = visit_sem_lambda(2);

    std::cout << "=== Usando std::visit com functor ===\n";
    std::visit(PrintVisitor{}, v1);
    std::visit(PrintVisitor{}, v2);
    std::visit(PrintVisitor{}, v3);

    std::cout << "\n=== Usando std::visit com lambda ===\n";
    visit_com_lambda(v1);
    visit_com_lambda(v2);
    visit_com_lambda(v3);

    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <concepts>

/**
 * DUCK TYPING: duck typing é um conceito de programação onde o tipo ou a classe de um objeto
 * é determinado pela presença de certos métodos e propriedades, em vez da herança de uma
 * classe específica. Em outras palavras, "se parece com um pato e grasna como um pato, então é um pato".
 * No contexto de C++, isso pode ser implementado usando templates e conceitos.
 */

// CONCEPT: Define o "contrato estrutural" para um Pedido
template <typename T>
concept PedidoValido =
    requires(T p) {
        { p.produto } -> convertible_to<std::string>;
        { p.preco } -> convertible_to<double>;
        { p.quantidade } -> convertible_to<int>;
        { p.parcelado } -> convertible_to<int>;
        { p.total() } -> convertible_to<double>;
    };

// Função DUCK TYPING: aceita QUALQUER tipo que satisfaça o Concept
template <PedidoValido Pedido>
void registrarCompra(const Pedido &p)
{
    std::cout << "\n=== Pedido Registrado ===\n";
    std::cout << "Produto:     " << p.produto << '\n';
    std::cout << "Preço UN:    R$ " << fixed << setprecision(2) << p.preco << '\n';
    std::cout << "Qtd:         " << p.quantidade << '\n';
    std::cout << "Total:       R$ " << fixed << setprecision(2) << p.total() << '\n';
    std::cout << "Parcelado:   " << p.parcelado << "x de R$ "
              << fixed << setprecision(2) << (p.total() / p.parcelado) << '\n';
    std::cout << "==========================\n";
}

// NOVA FUNÇÃO 1: Total de TODOS os produtos
template <PedidoValido Pedido>
void exibirTotalGeral(const std::vector<Pedido> &pedidos)
{
    double totalGeral = 0.0;

    for (const auto &p : pedidos)
    {
        totalGeral += p.total();
    }

    std::cout << "\n=== TOTAL GERAL DE TODOS OS PRODUTOS ===\n";
    std::cout << "R$ " << fixed << setprecision(2) << totalGeral << '\n';
    std::cout << "============================================\n";
}

// Estrutura única utilizada pelo funcionário
struct PedidoFuncionario
{
    std::string produto;
    double preco;
    int quantidade;
    int parcelado;

    double total() const
    {
        return preco * quantidade;
    }
};

// Catálogo de produtos
struct Produto
{
    std::string nome;
    double preco;
};

std::vector<Produto> catalogo = {
    {"Smartphone X200", 1999.99},
    {"Notebook Gamer Z15", 4500.00},
    {"Smart TV 55\"", 2999.90}};

int main(int argc, char **argv)
{
    // Vetor para armazenar todos os pedidos
    std::vector<PedidoFuncionario> todosPedidos;

    // Pedido 1
    PedidoFuncionario p1{
        catalogo[0].nome,
        catalogo[0].preco,
        1,
        1};
    todosPedidos.push_back(p1);

    // Pedido 2
    PedidoFuncionario p2{
        catalogo[1].nome,
        catalogo[1].preco,
        1,
        10};
    todosPedidos.push_back(p2);

    // Pedido 3
    PedidoFuncionario p3{
        catalogo[2].nome,
        catalogo[2].preco,
        2,
        6};
    todosPedidos.push_back(p3);

    // ✅ REGISTRA CADA PEDIDO (mantém o original)
    for (const auto &p : todosPedidos)
    {
        registrarCompra(p);
    }

    // ✅ NOVA FUNCIONALIDADE 1: Total geral de todos os produtos
    exibirTotalGeral(todosPedidos);

    // ✅ NOVA FUNCIONALIDADE 2: Mostra parcelamento detalhado
    std::cout << "\n=== DETALHAMENTO DO PARCELAMENTO ===\n";
    for (const auto &p : todosPedidos)
    {
        double valorParcela = p.total() / p.parcelado;
        std::cout << p.produto << " → " << p.parcelado
                  << "x de R$ " << fixed << setprecision(2) << valorParcela << '\n';
    }
    std::cout << "=====================================\n";

    return 0;
}

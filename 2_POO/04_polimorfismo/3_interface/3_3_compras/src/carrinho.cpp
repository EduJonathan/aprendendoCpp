#include "../classes/classCarrinho.hpp"
#include <iostream>

void Carrinho::adicionarProduto(std::shared_ptr<IProduto> produto)
{
    itens.push_back(produto);
}

void Carrinho::aplicarCupom(std::shared_ptr<ICupom> novoCupom)
{
    cupom = novoCupom;
}

void Carrinho::listarProdutos() const
{
    std::cout << "=== Itens no Carrinho ===\n";
    for (const auto &item : itens)
    {
        item->exibirDetalhes();
    }
}

double Carrinho::calcularTotalBruto() const
{
    double total = 0.0;
    for (const auto &item : itens)
    {
        total += item->getPreco();
    }
    return total;
}

double Carrinho::calcularTotalComDesconto() const
{
    double total = calcularTotalBruto();
    if (cupom)
    {
        return cupom->aplicarDesconto(total);
    }
    return total;
}

void Carrinho::finalizarCompra(const IPagamento &metodoPagamento) const
{
    double totalComDesconto = calcularTotalComDesconto();
    metodoPagamento.pagar(totalComDesconto);
}

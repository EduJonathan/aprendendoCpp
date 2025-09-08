#include "../classes/classProduto.hpp"
#include "../classes/classPagamento.hpp"
#include "../classes/classCupom.hpp"
#include "../classes/classCarrinho.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Carrinho carrinho;

    carrinho.adicionarProduto(std::make_shared<GPU>("NVIDIA RTX 4080", 6500.00));
    carrinho.adicionarProduto(std::make_shared<CPU>("Intel Core i9-14900K", 3500.00));
    carrinho.adicionarProduto(std::make_shared<RAM>("Corsair Vengeance 32GB", 1200.00));
    carrinho.adicionarProduto(std::make_shared<Gabinete>("Gabinete NZXT H510", 550.00));

    carrinho.listarProdutos();

    std::cout << "Total bruto: R$" << carrinho.calcularTotalBruto() << "\n";

    carrinho.aplicarCupom(std::make_shared<Cupom10Porcento>());
    std::cout << "Total com desconto: R$" << carrinho.calcularTotalComDesconto() << "\n";

    Pix pagamento;
    carrinho.finalizarCompra(pagamento);

    /**
     * Compile e execute com:
     * g++ -std=c++14 .\carrinho.cpp .\cupom.cpp .\main.cpp .\pagamento.cpp .\produto.cpp -o nome_do_executavel
     * .\nome_do_executavel
     */

    return 0;
}

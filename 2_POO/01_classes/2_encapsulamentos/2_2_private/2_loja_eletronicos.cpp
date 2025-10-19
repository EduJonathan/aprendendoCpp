#include <iostream>
#include <string>

class LojaDeEletronicos
{
private:
    // Variáveis privadas: só podem ser acessadas ou modificadas dentro da classe.
    std::string produto;
    int estoqueDeEletronicos;
    bool temNoEstoque;
    bool temNaLoja;

public:
    float preco;

    void setProduto(const std::string &produto)
    {
        this->produto = produto;
    }

    void setEstoqueDeEletronicos(int estoqueDeEletronicos)
    {
        this->estoqueDeEletronicos = estoqueDeEletronicos;
    }

    void setTemNoEstoque(bool temNoEstoque)
    {
        this->temNoEstoque = temNoEstoque;
    }

    void setTemNaLoja(bool temNaLoja)
    {
        this->temNaLoja = temNaLoja;
    }

    void setPreco(float preco)
    {
        this->preco = preco;
    }

    /* Getters */
    std::string getProduto()
    {
        return produto;
    }

    int getEstoqueDeEletronicos()
    {
        return estoqueDeEletronicos;
    }

    float getPreco()
    {
        return preco;
    }

    // Método para verificar a disponibilidade do produto
    bool verificarDisponibilidade()
    {
        if (temNoEstoque && temNaLoja)
        {
            return true;
        }
        return false;
    }
};

class Cliente
{
private:
    std::string nome;
    float saldo;
    LojaDeEletronicos *produtoComprado;

public:
    // Setter para 'nome' e 'saldo'
    void setNome(const std::string &nome)
    {
        this->nome = nome;
    }

    void setSaldo(float saldo)
    {
        this->saldo = saldo;
    }

    // Método para tentar comprar o produto
    void comprarProduto(LojaDeEletronicos &loja)
    {
        if (!loja.verificarDisponibilidade())
        {
            std::cout << loja.getProduto() << " não está disponível na loja." << '\n';
            return;
        }

        if (saldo < loja.getPreco())
        {
            std::cout << nome << " não tem saldo suficiente para comprar " << loja.getProduto() << '.' << '\n';
            return;
        }

        saldo -= loja.getPreco();
        produtoComprado = &loja;
        std::cout << nome << " comprou o produto " << loja.getProduto() << " com sucesso!" << '\n';
        std::cout << "Saldo restante: R$ " << saldo << '\n';
    }

    // Método para mostrar se o cliente tem ou não o produto
    void mostrarCompra()
    {
        if (produtoComprado)
        {
            std::cout << nome << " levou o produto " << produtoComprado->getProduto() << " para casa!" << '\n';
        }
        else
        {
            std::cout << nome << " não levou nenhum produto." << '\n';
        }
    }
};

int main(int argc, char **argv)
{
    // Criando a loja e o produto
    LojaDeEletronicos loja;

    loja.setProduto("Televisão");
    loja.setEstoqueDeEletronicos(50);
    loja.setTemNoEstoque(true);
    loja.setTemNaLoja(true);
    loja.setPreco(1500.50);

    // Criando o cliente
    Cliente cliente;
    cliente.setNome("João");
    cliente.setSaldo(2000.00); // Cliente com R$ 2000

    // Cliente tenta comprar o produto
    cliente.comprarProduto(loja);

    // Mostra se o cliente levou ou não o produto
    cliente.mostrarCompra();

    return 0;
}

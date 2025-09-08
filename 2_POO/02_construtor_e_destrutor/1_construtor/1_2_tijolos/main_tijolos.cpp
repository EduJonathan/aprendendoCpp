#include <iostream>
#include <string>
#include "class_tijolos.hpp"

// Construtor
ExportacaoDeTijolos::ExportacaoDeTijolos(int qtdExportados, int qtdPedidos)
    : quantidadeDeTijolos(qtdExportados), quantidadeDeTijolosPedidos(qtdPedidos),
      dimensaoDosTijolos("14x10")
{
    verificaQuantidade();
}

// Getters
std::string ExportacaoDeTijolos::getDimensao(void) const
{
    return dimensaoDosTijolos;
}

int ExportacaoDeTijolos::getQuantidadeDeTijolos(void) const
{
    return quantidadeDeTijolos;
}

int ExportacaoDeTijolos::getQuantidadeDeTijolosPedidos(void) const
{
    return quantidadeDeTijolosPedidos;
}

bool ExportacaoDeTijolos::isQuantidadeCondizente(void) const
{
    return quantidadeCondizidente;
}

// Setters
void ExportacaoDeTijolos::setQuantidadeDeTijolos(int qtd)
{
    quantidadeDeTijolos = qtd;
    verificaQuantidade();
}

void ExportacaoDeTijolos::setQuantidadeDeTijolosPedidos(int qtd)
{
    quantidadeDeTijolosPedidos = qtd;
    verificaQuantidade();
}

// Método privado
void ExportacaoDeTijolos::verificaQuantidade(void)
{
    quantidadeCondizidente = (quantidadeDeTijolos == quantidadeDeTijolosPedidos);
}

int main(int argc, char **argv)
{
    // Criando uma instância com 500 tijolos exportados e 500 pedidos
    ExportacaoDeTijolos exportacao(500, 500);

    std::cout << "Dimensao dos Tijolos: " << exportacao.getDimensao() << '\n';
    std::cout << "Quantidade Exportada: " << exportacao.getQuantidadeDeTijolos() << '\n';
    std::cout << "Quantidade Pedida: " << exportacao.getQuantidadeDeTijolosPedidos() << '\n';

    if (exportacao.isQuantidadeCondizente())
    {
        std::cout << "A quantidade exportada condiz com a pedida." << '\n';
    }
    else
    {
        std::cout << "A quantidade exportada NAO condiz com a pedida." << '\n';
    }

    // Alterando valores
    exportacao.setQuantidadeDeTijolosPedidos(600);

    std::cout << "\nApós alteração do pedido:" << '\n';
    std::cout << "Nova Quantidade Pedida: " << exportacao.getQuantidadeDeTijolosPedidos() << '\n';

    if (exportacao.isQuantidadeCondizente())
    {
        std::cout << "Agora a quantidade exportada condiz com a pedida." << '\n';
    }
    else
    {
        std::cout << "Agora a quantidade exportada NAO condiz com a pedida." << '\n';
    }

    return 0;
}

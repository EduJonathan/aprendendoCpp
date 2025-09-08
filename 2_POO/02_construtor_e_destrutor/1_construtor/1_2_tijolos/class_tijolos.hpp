#ifndef CLASS_TIJOLOS_HPP
#define CLASS_TIJOLOS_HPP

#include <string>

class ExportacaoDeTijolos
{
private:
    std::string dimensaoDosTijolos; // A dimensão do tijolo (14x10)
    int quantidadeDeTijolos;        // Quantidade de tijolos exportados
    int quantidadeDeTijolosPedidos; // Quantidade de tijolos pedidos pelo cliente
    bool quantidadeCondizidente;    // Verificar se a quantidade solicitada condiz com a exportada

public:
    // Construtor
    ExportacaoDeTijolos(int qtdExportados, int qtdPedidos);

    // Métodos Getters
    std::string getDimensao(void) const;
    int getQuantidadeDeTijolos(void) const;
    int getQuantidadeDeTijolosPedidos(void) const;
    bool isQuantidadeCondizente(void) const;

    // Métodos Setters
    void setQuantidadeDeTijolos(int qtd);
    void setQuantidadeDeTijolosPedidos(int qtd);

private:
    // Método para verificar se as quantidades condizem
    void verificaQuantidade(void);
};

#endif // CLASS_TIJOLOS_HPP

#include <iostream>
#include <memory>
#include "../classes/classCartaoCredito.hpp"
#include "../classes/classBoletoBancario.hpp"
#include "../classes/classPix.hpp"

/**
 * @brief Função para realizar uma compra usando um modo de pagamento
 *
 * @param pagamento Ponteiro para o modo de pagamento a ser utilizado
 * @param valor Valor da compra
 */
void realizarCompra(ModoPagamento *pagamento, double valor)
{
    std::cout << "Iniciando compra usando: " << pagamento->getDescricao() << '\n';

    try
    {
        pagamento->processarPagamento(valor);
        std::cout << "Compra finalizada!\n\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Erro ao processar pagamento: " << e.what() << "\n\n";
    }
}

int main(int argc, char **argv)
{
    BoletoBancario boleto;
    CartaoCredito cartao("4111111111111111", "John Silva", "12/25", "123", 3);
    Pix pix("john.silva@email.com");

    realizarCompra(&cartao, 500.00);
    realizarCompra(&boleto, 99.90);
    realizarCompra(&pix, 150.75);

    std::unique_ptr<ModoPagamento> pagamento1 = std::make_unique<CartaoCredito>("5555444433332222", "Maria Souza", "06/26", "456", 6);
    std::unique_ptr<ModoPagamento> pagamento2 = std::make_unique<BoletoBancario>();
    std::unique_ptr<ModoPagamento> pagamento3 = std::make_unique<Pix>("11987654321");

    realizarCompra(pagamento1.get(), 1200.50);
    realizarCompra(pagamento2.get(), 75.30);
    realizarCompra(pagamento3.get(), 200.00);

    /**
     * Compile e execute com:
     *
     * > g++ -std=c++17 -I../classes boletoBancario.cpp cartaoDeCredito.cpp Pix.cpp pagamento_main.cpp -o main.exe
     * > .\main.exe
     */
    return 0;
}

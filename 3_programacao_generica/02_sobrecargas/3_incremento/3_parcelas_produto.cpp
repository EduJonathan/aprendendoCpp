#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <new>

// Classe base abstrata para métodos de pagamento
class MetodoPagamento
{
protected:
    double valorTotal;
    int parcelasTotal;
    int parcelasPagas;
    std::string nomeProduto;

public:
    MetodoPagamento(double valor, int parcelas, std::string produto)
        : valorTotal(valor), parcelasTotal(parcelas), parcelasPagas(0), nomeProduto(produto) {}

    virtual ~MetodoPagamento() {}

    // Operador de incremento (pagar parcela)
    virtual MetodoPagamento &operator++() = 0;

    // Operador de decremento (estornar parcela)
    virtual MetodoPagamento &operator--() = 0;

    virtual void mostrarSituacao() const = 0;
    virtual double getValorParcela() const = 0;
    virtual std::string getTipo() const = 0;

    double getValorTotal() const { return valorTotal; }
    int getParcelasTotal() const { return parcelasTotal; }
    int getParcelasPagas() const { return parcelasPagas; }
    std::string getNomeProduto() const { return nomeProduto; }

    double getValorPago() const
    {
        return getValorParcela() * parcelasPagas;
    }

    double getValorRestante() const
    {
        return valorTotal - getValorPago();
    }
};

// Classe para pagamento no crediário
class Crediario : public MetodoPagamento
{
private:
    double taxaJuros;

public:
    Crediario(double valor, int parcelas, std::string produto, double juros = 0.05)
        : MetodoPagamento(valor, parcelas, produto), taxaJuros(juros) {}

    // Incremento: pagar uma parcela
    Crediario &operator++() override
    {
        if (parcelasPagas < parcelasTotal)
        {
            parcelasPagas++;
            std::cout << "Parcela " << parcelasPagas << " paga no crediário!" << '\n';
        }
        else
        {
            std::cout << "Todas as parcelas já foram pagas!" << '\n';
        }
        return *this;
    }

    // Decremento: estornar uma parcela
    Crediario &operator--() override
    {
        if (parcelasPagas > 0)
        {
            parcelasPagas--;
            std::cout << "Parcela " << (parcelasPagas + 1) << " estornada!" << '\n';
        }
        else
        {
            std::cout << "Não há parcelas pagas para estornar!" << '\n';
        }
        return *this;
    }

    double getValorParcela() const override
    {
        return (valorTotal * (1 + taxaJuros)) / parcelasTotal;
    }

    void mostrarSituacao() const override
    {
        std::cout << "\n=== CREDIÁRIO ===" << '\n';
        std::cout << "Produto: " << nomeProduto << '\n';
        std::cout << "Valor total: R$ " << std::fixed << std::setprecision(2) << valorTotal << '\n';
        std::cout << "Taxa de juros: " << taxaJuros * 100 << '%' << '\n';
        std::cout << "Valor com juros: R$ " << getValorTotalComJuros() << '\n';
        std::cout << "Parcelas: " << parcelasPagas << "/" << parcelasTotal << '\n';
        std::cout << "Valor da parcela: R$ " << getValorParcela() << '\n';
        std::cout << "Valor pago: R$ " << getValorPago() << '\n';
        std::cout << "Valor restante: R$ " << getValorRestante() << '\n';
    }

    std::string getTipo() const override { return "Crediário"; }

    double getValorTotalComJuros() const
    {
        return valorTotal * (1 + taxaJuros);
    }
};

// Classe para pagamento no cartão de crédito
class CartaoCredito : public MetodoPagamento
{
public:
    CartaoCredito(double valor, int parcelas, std::string produto)
        : MetodoPagamento(valor, parcelas, produto) {}

    // Incremento: pagar uma parcela
    CartaoCredito &operator++() override
    {
        if (parcelasPagas < parcelasTotal)
        {
            parcelasPagas++;
            std::cout << "Parcela " << parcelasPagas << " paga no cartão!" << '\n';
        }
        else
        {
            std::cout << "Todas as parcelas já foram pagas!" << '\n';
        }
        return *this;
    }

    // Decremento: estornar uma parcela
    CartaoCredito &operator--() override
    {
        if (parcelasPagas > 0)
        {
            parcelasPagas--;
            std::cout << "Parcela " << (parcelasPagas + 1) << " estornada!" << '\n';
        }
        else
        {
            std::cout << "Não há parcelas pagas para estornar!" << '\n';
        }
        return *this;
    }

    double getValorParcela() const override
    {
        return valorTotal / parcelasTotal;
    }

    void mostrarSituacao() const override
    {
        std::cout << "\n=== CARTÃO DE CRÉDITO ===" << '\n';
        std::cout << "Produto: " << nomeProduto << '\n';
        std::cout << "Valor total: R$ " << std::fixed << std::setprecision(2) << valorTotal << '\n';
        std::cout << "Parcelas: " << parcelasPagas << "/" << parcelasTotal << '\n';
        std::cout << "Valor da parcela: R$ " << getValorParcela() << '\n';
        std::cout << "Valor pago: R$ " << getValorPago() << '\n';
        std::cout << "Valor restante: R$ " << getValorRestante() << '\n';
    }

    std::string getTipo() const override { return "Cartão de Crédito"; }
};

// Função para demonstrar o uso dos operadores
void demonstrarCompra(MetodoPagamento *compra)
{
    std::cout << "\n\n=== INICIANDO DEMONSTRAÇÃO ===" << '\n';
    compra->mostrarSituacao();

    // Pagando algumas parcelas
    std::cout << "\n--- Pagando 3 parcelas ---" << '\n';
    for (int i = 0; i < 3; i++)
    {
        ++(*compra);
    }
    compra->mostrarSituacao();

    // Estornando uma parcela
    std::cout << "\n--- Estornando 1 parcela ---" << '\n';
    --(*compra);
    compra->mostrarSituacao();

    // Pagando mais parcelas
    std::cout << "\n--- Pagando 2 parcelas ---" << '\n';
    for (int i = 0; i < 2; i++)
    {
        ++(*compra);
    }
    compra->mostrarSituacao();
}

int main(int argc, char **argv)
{
    // Exemplo de uso com polimorfismo
    std::vector<MetodoPagamento *> compras;

    // Compra no crediário
    compras.push_back(new Crediario(1110.00, 10, "Poco X3", 0.05));

    // Compra no cartão de crédito
    compras.push_back(new CartaoCredito(1250.00, 10, "Iphone 13"));

    // Demonstrando cada tipo de compra
    for (MetodoPagamento *compra : compras)
    {
        demonstrarCompra(compra);
    }

    // Limpeza da memória
    for (MetodoPagamento *compra : compras)
    {
        delete compra;
    }

    return 0;
}

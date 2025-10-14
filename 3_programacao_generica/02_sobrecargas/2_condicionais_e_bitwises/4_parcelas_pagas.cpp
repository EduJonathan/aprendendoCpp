#include <iostream>
#include <bitset>
#include <iomanip>
#include <vector>
#include <string>
#include <new>

// Classe base abstrata para métodos de pagamento
class MetodoPagamento
{
protected:
    double valorTotal;
    int parcelasTotal;
    std::string nomeProduto;
    unsigned int parcelasPagas; // Bitfield para controle das parcelas

public:
    MetodoPagamento(double valor, int parcelas, std::string produto)
        : valorTotal(valor), parcelasTotal(parcelas), nomeProduto(produto), parcelasPagas(0) {}

    virtual ~MetodoPagamento() {}

    // Operador bitwise OR (|) para marcar parcelas como pagas
    virtual MetodoPagamento &operator|(int parcela) = 0;

    // Operador bitwise AND (&) para verificar se parcela foi paga
    virtual bool operator&(int parcela) const = 0;

    // Operador bitwise XOR (^) para alternar estado da parcela
    virtual MetodoPagamento &operator^(int parcela) = 0;

    // Operador bitwise NOT (~) para estornar todas as parcelas
    virtual MetodoPagamento &operator~() = 0;

    virtual void mostrarSituacao() const = 0;
    virtual double getValorParcela() const = 0;
    virtual std::string getTipo() const = 0;

    int getParcelasPagasCount() const
    {
        // Conta quantos bits estão setados (parcelas pagas)
        int count = 0;
        unsigned int temp = parcelasPagas;
        while (temp)
        {
            count += temp & 1;
            temp >>= 1;
        }
        return count;
    }

    double getValorTotal() const { return valorTotal; }
    int getParcelasTotal() const { return parcelasTotal; }
    std::string getNomeProduto() const { return nomeProduto; }
    double getValorPago() const { return getValorParcela() * getParcelasPagasCount(); }
    double getValorRestante() const { return valorTotal - getValorPago(); }

    void mostrarBitfield() const
    {
        std::cout << "Estado das parcelas (1=paga, 0=pendente): ";
        for (int i = parcelasTotal - 1; i >= 0; i--)
        {
            std::cout << ((parcelasPagas >> i) & 1);
        }
        std::cout << '\n';
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

    // Operador OR: marcar parcela como paga
    Crediario &operator|(int parcela) override
    {
        if (parcela >= 1 && parcela <= parcelasTotal)
        {
            parcelasPagas |= (1 << (parcela - 1));
            std::cout << "Parcela " << parcela << " marcada como paga no crediário!" << '\n';
        }
        else
        {
            std::cout << "Número de parcela inválido!" << '\n';
        }
        return *this;
    }

    // Operador AND: verificar se parcela foi paga
    bool operator&(int parcela) const override
    {
        if (parcela >= 1 && parcela <= parcelasTotal)
        {
            return parcelasPagas & (1 << (parcela - 1));
        }
        return false;
    }

    // Operador XOR: alternar estado da parcela
    Crediario &operator^(int parcela) override
    {
        if (parcela >= 1 && parcela <= parcelasTotal)
        {
            parcelasPagas ^= (1 << (parcela - 1));
            std::cout << "Estado da parcela " << parcela << " alternado!" << '\n';
        }
        else
        {
            std::cout << "Número de parcela inválido!" << '\n';
        }
        return *this;
    }

    // Operador NOT: estornar todas as parcelas
    Crediario &operator~() override
    {
        parcelasPagas = 0;
        std::cout << "Todas as parcelas estornadas no crediário!" << '\n';
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
        std::cout << "Parcelas pagas: " << getParcelasPagasCount() << '/' << parcelasTotal << '\n';
        std::cout << "Valor da parcela: R$ " << getValorParcela() << '\n';
        std::cout << "Valor pago: R$ " << getValorPago() << '\n';
        std::cout << "Valor restante: R$ " << getValorRestante() << '\n';
        mostrarBitfield();
    }

    std::string getTipo() const override { return "Crediário"; }
    double getValorTotalComJuros() const { return valorTotal * (1 + taxaJuros); }
};

// Classe para pagamento no cartão de crédito
class CartaoCredito : public MetodoPagamento
{
public:
    CartaoCredito(double valor, int parcelas, std::string produto)
        : MetodoPagamento(valor, parcelas, produto) {}

    // Operador OR: marcar parcela como paga
    CartaoCredito &operator|(int parcela) override
    {
        if (parcela >= 1 && parcela <= parcelasTotal)
        {
            parcelasPagas |= (1 << (parcela - 1));
            std::cout << "Parcela " << parcela << " marcada como paga no cartão!" << '\n';
        }
        else
        {
            std::cout << "Número de parcela inválido!" << '\n';
        }
        return *this;
    }

    // Operador AND: verificar se parcela foi paga
    bool operator&(int parcela) const override
    {
        if (parcela >= 1 && parcela <= parcelasTotal)
        {
            return parcelasPagas & (1 << (parcela - 1));
        }
        return false;
    }

    // Operador XOR: alternar estado da parcela
    CartaoCredito &operator^(int parcela) override
    {
        if (parcela >= 1 && parcela <= parcelasTotal)
        {
            parcelasPagas ^= (1 << (parcela - 1));
            std::cout << "Estado da parcela " << parcela << " alternado!" << '\n';
        }
        else
        {
            std::cout << "Número de parcela inválido!" << '\n';
        }
        return *this;
    }

    // Operador NOT: estornar todas as parcelas
    CartaoCredito &operator~() override
    {
        parcelasPagas = 0;
        std::cout << "Todas as parcelas estornadas no cartão!" << '\n';
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
        std::cout << "Parcelas pagas: " << getParcelasPagasCount() << '/' << parcelasTotal << '\n';
        std::cout << "Valor da parcela: R$ " << getValorParcela() << '\n';
        std::cout << "Valor pago: R$ " << getValorPago() << '\n';
        std::cout << "Valor restante: R$ " << getValorRestante() << '\n';
        mostrarBitfield();
    }

    std::string getTipo() const override { return "Cartão de Crédito"; }
};

// Função para demonstrar o uso dos operadores bitwise
void demonstrarOperadoresBitwise(MetodoPagamento *compra)
{
    std::cout << "\n\n=== DEMONSTRAÇÃO OPERADORES BITWISE ===" << '\n';
    compra->mostrarSituacao();

    // Usando operador OR para marcar parcelas como pagas
    std::cout << "\n--- Marcando parcelas 1, 3 e 5 como pagas (operador |) ---" << '\n';
    *compra | 1 | 3 | 5;
    compra->mostrarSituacao();

    // Usando operador AND para verificar parcelas
    std::cout << "\n--- Verificando parcelas (operador &) ---" << '\n';
    for (int i = 1; i <= compra->getParcelasTotal(); ++i)
    {
        if (*compra & i)
        {
            std::cout << "Parcela " << i << ": PAGA" << '\n';
        }
        else
        {
            std::cout << "Parcela " << i << ": Pendente" << '\n';
        }
    }

    // Usando operador XOR para alternar estados
    std::cout << "\n--- Alternando estado das parcelas 2 e 5 (operador ^) ---" << '\n';
    *compra ^ 2 ^ 5;
    compra->mostrarSituacao();

    // Usando operador NOT para estornar todas
    std::cout << "\n--- Estornando todas as parcelas (operador ~) ---" << '\n';
    ~(*compra);
    compra->mostrarSituacao();
}

int main(int argc, char **argv)
{
    // Exemplo de uso com polimorfismo
    std::vector<MetodoPagamento *> compras;

    // Compra no crediário
    compras.push_back(new Crediario(1250.00, 10, "Notebook Asus", 0.05));

    // Compra no cartão de crédito
    compras.push_back(new CartaoCredito(3.250, 10, "IPhone 14 Pro Max"));

    // Demonstrando cada tipo de compra com operadores bitwise
    for (MetodoPagamento *compra : compras)
    {
        demonstrarOperadoresBitwise(compra);
    }

    // Limpeza da memória
    for (MetodoPagamento *compra : compras)
    {
        delete compra;
    }
    return 0;
}

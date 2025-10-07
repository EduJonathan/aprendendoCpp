#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>

// Classe base abstrata para contas de energia
class ContaEnergia
{
protected:
    std::string tipo;
    double consumo; // em Kwh
    double valorKwh;
    double iluminacaoPublica;
    double multa;
    double multaCIP;
    double juros;
    double jurosCIP;

public:
    ContaEnergia(std::string tipo, double consumo, double valorKwh) : tipo(tipo),
                                                                      consumo(consumo),
                                                                      valorKwh(valorKwh), iluminacaoPublica(0), multa(0), multaCIP(0), juros(0), jurosCIP(0) {}

    virtual ~ContaEnergia() {}

    // Sobrecarga de operadores para adicionar encargos
    virtual ContaEnergia &operator+(double valor) = 0; // Adiciona encargo
    virtual ContaEnergia &operator-(double valor) = 0; // Remove encargo
    virtual ContaEnergia &operator++() = 0;            // Aplica juros
    virtual ContaEnergia &operator--() = 0;            // Remove juros

    // Sobrecarga do operador de função para cálculo complexo
    virtual double operator()(double desconto = 0) const = 0;

    virtual void mostrarDetalhes() const = 0;
    virtual double calcularValorBase() const = 0;

    double getConsumo() const { return consumo; }
    std::string getTipo() const { return tipo; }

    double getTotalEncargos() const
    {
        return iluminacaoPublica + multa + multaCIP + juros + jurosCIP;
    }

    double getValorTotal() const
    {
        return calcularValorBase() + getTotalEncargos();
    }

    // Métodos para configurar encargos
    void setIluminacaoPublica(double valor) { iluminacaoPublica = valor; }
    void setMulta(double valor) { multa = valor; }
    void setMultaCIP(double valor) { multaCIP = valor; }
    void setJuros(double valor) { juros = valor; }
    void setJurosCIP(double valor) { jurosCIP = valor; }
};

// Classe para conta de luz
class ContaLuz : public ContaEnergia
{
private:
    double taxaICMS;

public:
    ContaLuz(double consumo, double valorKwh, double taxaICMS = 0.25)
        : ContaEnergia("Luz", consumo, valorKwh), taxaICMS(taxaICMS) {}

    // Operador + para adicionar encargos
    ContaLuz &operator+(double valor) override
    {
        // Distribui o valor entre os encargos proporcionalmente
        double totalAtual = getTotalEncargos();
        if (totalAtual > 0)
        {
            double fator = valor / totalAtual;
            iluminacaoPublica += iluminacaoPublica * fator;
            multa += multa * fator;
            multaCIP += multaCIP * fator;
        }
        else
        {
            // Se não há encargos, adiciona à multa padrão
            multa += valor;
        }
        return *this;
    }

    // Operador - para remover encargos
    ContaLuz &operator-(double valor) override
    {
        // Remove proporcionalmente dos encargos
        double totalAtual = getTotalEncargos();
        if (totalAtual > 0)
        {
            double fator = valor / totalAtual;
            iluminacaoPublica = std::max(0.0, iluminacaoPublica - iluminacaoPublica * fator);
            multa = std::max(0.0, multa - multa * fator);
            multaCIP = std::max(0.0, multaCIP - multaCIP * fator);
        }
        return *this;
    }

    // Operador ++ para aplicar juros
    ContaLuz &operator++() override
    {
        juros += getValorTotal() * 0.02;    // 2% de juros
        jurosCIP += getValorTotal() * 0.01; // 1% de juros CIP
        return *this;
    }

    // Operador -- para remover juros
    ContaLuz &operator--() override
    {
        juros = 0;
        jurosCIP = 0;
        return *this;
    }

    // Operador () para cálculo com desconto
    double operator()(double desconto = 0) const override
    {
        double valorBase = calcularValorBase();
        double totalEncargos = getTotalEncargos();
        return (valorBase + totalEncargos) * (1 - desconto / 100);
    }

    double calcularValorBase() const override
    {
        double valorConsumo = consumo * valorKwh;
        return valorConsumo + (valorConsumo * taxaICMS);
    }

    void mostrarDetalhes() const override
    {
        std::cout << "\n=== CONTA DE " << tipo << " ===" << '\n';
        std::cout << "Consumo: " << consumo << " Kwh" << '\n';
        std::cout << "Valor do Kwh: R$ " << std::fixed << std::setprecision(4) << valorKwh << '\n';
        std::cout << "Valor base (consumo + ICMS): R$ " << std::fixed << std::setprecision(2) << calcularValorBase() << '\n';
        std::cout << "Iluminação Pública: R$ " << std::fixed << std::setprecision(2) << iluminacaoPublica << '\n';
        std::cout << "Multa: R$ " << std::fixed << std::setprecision(2) << multa << '\n';
        std::cout << "Multa CIP: R$ " << std::fixed << std::setprecision(2) << multaCIP << '\n';
        std::cout << "Juros: R$ " << std::fixed << std::setprecision(2) << juros << '\n';
        std::cout << "Juros CIP: R$ " << std::fixed << std::setprecision(2) << jurosCIP << '\n';
        std::cout << "TOTAL: R$ " << std::fixed << std::setprecision(2) << getValorTotal() << '\n';
    }
};

// Classe para conta de água
class ContaAgua : public ContaEnergia
{
private:
    double taxaEsgoto;

public:
    ContaAgua(double consumo, double valorKwh, double taxaEsgoto = 0.80)
        : ContaEnergia("Água", consumo, valorKwh), taxaEsgoto(taxaEsgoto) {}

    // Operador + para adicionar encargos
    ContaAgua &operator+(double valor) override
    {
        // Distribui o valor entre os encargos proporcionalmente
        double totalAtual = getTotalEncargos();
        if (totalAtual > 0)
        {
            double fator = valor / totalAtual;
            iluminacaoPublica += iluminacaoPublica * fator;
            multa += multa * fator;
            multaCIP += multaCIP * fator;
        }
        else
        {
            // Se não há encargos, adiciona à multa padrão
            multa += valor;
        }
        return *this;
    }

    // Operador - para remover encargos
    ContaAgua &operator-(double valor) override
    {
        // Remove proporcionalmente dos encargos
        double totalAtual = getTotalEncargos();
        if (totalAtual > 0)
        {
            double fator = valor / totalAtual;
            iluminacaoPublica = std::max(0.0, iluminacaoPublica - iluminacaoPublica * fator);
            multa = std::max(0.0, multa - multa * fator);
            multaCIP = std::max(0.0, multaCIP - multaCIP * fator);
        }
        return *this;
    }

    // Operador ++ para aplicar juros
    ContaAgua &operator++() override
    {
        juros += getValorTotal() * 0.03;     // 3% de juros
        jurosCIP += getValorTotal() * 0.015; // 1.5% de juros CIP
        return *this;
    }

    // Operador -- para remover juros
    ContaAgua &operator--() override
    {
        juros = 0;
        jurosCIP = 0;
        return *this;
    }

    // Operador () para cálculo com desconto
    double operator()(double desconto = 0) const override
    {
        double valorBase = calcularValorBase();
        double totalEncargos = getTotalEncargos();
        return (valorBase + totalEncargos) * (1 - desconto / 100);
    }

    double calcularValorBase() const override
    {
        double valorConsumo = consumo * valorKwh;
        return valorConsumo + (valorConsumo * taxaEsgoto);
    }

    void mostrarDetalhes() const override
    {
        std::cout << "\n=== CONTA DE " << tipo << " ===" << '\n';
        std::cout << "Consumo: " << consumo << " Kwh" << '\n';
        std::cout << "Valor do Kwh: R$ " << std::fixed << std::setprecision(4) << valorKwh << '\n';
        std::cout << "Valor base (consumo + esgoto): R$ " << std::fixed << std::setprecision(2) << calcularValorBase() << '\n';
        std::cout << "Iluminação Pública: R$ " << std::fixed << std::setprecision(2) << iluminacaoPublica << '\n';
        std::cout << "Multa: R$ " << std::fixed << std::setprecision(2) << multa << '\n';
        std::cout << "Multa CIP: R$ " << std::fixed << std::setprecision(2) << multaCIP << '\n';
        std::cout << "Juros: R$ " << std::fixed << std::setprecision(2) << juros << '\n';
        std::cout << "Juros CIP: R$ " << std::fixed << std::setprecision(2) << jurosCIP << '\n';
        std::cout << "TOTAL: R$ " << std::fixed << std::setprecision(2) << getValorTotal() << '\n';
    }
};

int main(int argc, char **argv)
{
    std::cout << "=== SISTEMA DE CONTAS DE ENERGIA ===" << '\n';

    // Criando contas
    ContaLuz luz(150, 0.85);  // 150 Kwh a R$ 0.85
    ContaAgua agua(30, 4.50); // 30 Kwh a R$ 4.50

    // Configurando encargos iniciais
    luz.setIluminacaoPublica(15.00);
    luz.setMulta(0);
    luz.setMultaCIP(5.00);

    agua.setIluminacaoPublica(12.00);
    agua.setMulta(0);
    agua.setMultaCIP(4.50);

    // Mostrando contas iniciais
    std::cout << "\n--- Contas Iniciais ---" << '\n';
    luz.mostrarDetalhes();
    agua.mostrarDetalhes();

    // Aplicando operadores
    std::cout << "\n--- Após Adição de Encargos (+ R$ 20,00) ---" << '\n';
    luz + 20.00;
    agua + 20.00;
    luz.mostrarDetalhes();
    agua.mostrarDetalhes();

    // Aplicando juros
    std::cout << "\n--- Após Aplicação de Juros (operator++) ---" << '\n';
    ++luz;
    ++agua;
    luz.mostrarDetalhes();
    agua.mostrarDetalhes();

    // Usando operador de função com desconto
    std::cout << "\n--- Cálculo com Desconto (operator()) ---" << '\n';
    std::cout << "Luz com 10% de desconto: R$ " << luz(10) << '\n';
    std::cout << "Água com 15% de desconto: R$ " << agua(15) << '\n';

    // Removendo juros
    std::cout << "\n--- Após Remoção de Juros (operator--) ---" << '\n';
    --luz;
    --agua;
    luz.mostrarDetalhes();
    agua.mostrarDetalhes();

    // Removendo encargos
    std::cout << "\n--- Após Remoção de Encargos (- R$ 10,00) ---" << '\n';
    luz - 10.00;
    agua - 10.00;
    luz.mostrarDetalhes();
    agua.mostrarDetalhes();
    return 0;
}

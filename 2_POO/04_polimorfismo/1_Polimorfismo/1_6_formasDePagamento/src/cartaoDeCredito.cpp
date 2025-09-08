#include <iostream>
#include <cmath>
#include <stdexcept>
#include <ctime>
#include "../classes/classCartaoCredito.hpp"

CartaoCredito::CartaoCredito(const std::string &num, const std::string &nome,
                             const std::string &validade, const std::string &cvv, int parcelas) : numeroCartao(num), nomeTitular(nome), dataValidade(validade), cvv(cvv), parcelas(1)
{
    setParcelas(parcelas);
}

void CartaoCredito::setParcelas(int numParcelas)
{
    if (numParcelas < 1 || numParcelas > 12)
    {
        throw std::invalid_argument("Número de parcelas inválido (1-12)");
    }
    parcelas = numParcelas;
}

bool CartaoCredito::validarNumeroCartao() const
{
    int soma = 0;
    bool alternar = false;

    for (int i = numeroCartao.length() - 1; i >= 0; --i)
    {
        int digito = numeroCartao[i] - '0';

        if (alternar)
        {
            digito *= 2;

            if (digito > 9)
                digito = (digito % 10) + 1;
        }

        soma += digito;
        alternar = !alternar;
    }

    return (soma % 10 == 0);
}

bool CartaoCredito::validarData() const
{
    int mes = std::stoi(dataValidade.substr(0, 2));
    int ano = std::stoi(dataValidade.substr(3, 2)) + 2000;

    std::time_t t = std::time(nullptr);
    std::tm *agora = std::localtime(&t);
    int anoAtual = agora->tm_year + 1900;
    int mesAtual = agora->tm_mon + 1;

    return !(ano < anoAtual || (ano == anoAtual && mes < mesAtual));
}

bool CartaoCredito::validarCVV() const
{
    return cvv.length() == 3 || cvv.length() == 4;
}

std::vector<double> CartaoCredito::calcularParcelas(double valorTotal, int numParcelas) const
{
    std::vector<double> parcelas;
    double valorParcela = std::round((valorTotal / numParcelas) * 100) / 100;
    double soma = valorParcela * (numParcelas - 1);
    double ultimaParcela = valorTotal - soma;

    for (int i = 0; i < numParcelas - 1; ++i)
    {
        parcelas.push_back(valorParcela);
    }

    parcelas.push_back(ultimaParcela);
    return parcelas;
}

int CartaoCredito::determinarMaxParcelas(double valor) const
{
    if (valor >= 1000)
        return 12;

    if (valor >= 500)
        return 6;

    if (valor >= 200)
        return 3;
    return 1;
}

void CartaoCredito::processarPagamento(double valor)
{
    if (!validarNumeroCartao())
        throw std::runtime_error("Número do cartão inválido");

    if (!validarData())
        throw std::runtime_error("Cartão expirado");

    if (!validarCVV())
        throw std::runtime_error("CVV inválido");

    int maxParcelas = determinarMaxParcelas(valor);

    if (parcelas > maxParcelas)
        throw std::runtime_error("Número de parcelas não permitido para este valor");

    std::cout << "Processando pagamento de R$" << valor << " via cartão de crédito (" << getUltimosDigitos() << ")\n";

    std::cout << "Parcelado em " << parcelas << "x\n";

    auto valoresParcelas = calcularParcelas(valor, parcelas);
    for (std::size_t i = 0ull; i < valoresParcelas.size(); ++i)
    {
        std::cout << "  Parcela " << (i + 1) << ": R$" << valoresParcelas[i] << '\n';
    }
}

std::string CartaoCredito::getDescricao() const
{
    return "Cartão de Crédito (" + getUltimosDigitos() + ") - " + std::to_string(parcelas) + "x";
}

std::string CartaoCredito::getUltimosDigitos() const
{
    return numeroCartao.substr(numeroCartao.length() - 4);
}

bool CartaoCredito::ehValido() const
{
    return validarNumeroCartao() && validarData() && validarCVV();
}

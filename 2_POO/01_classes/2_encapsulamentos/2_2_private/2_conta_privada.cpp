#include <iostream>
#include <iomanip>
#include <string>

class Pessoa
{
public:
    std::string nome;
    int numeroAgencia;
    int numeroConta;
    std::string senha;

    void mostrarDados() const
    {
        std::cout << "Titular da conta: " << nome << '\n';
        std::cout << "Agência: " << numeroAgencia << ", Conta: " << numeroConta << '\n';
    }
};

class ContaPessoal
{
private:
    double saldo;
    Pessoa pessoa;

public:
    void getMostrarSaldo() const
    {
        std::cout << "Seu saldo é: R$ " << std::fixed << std::setprecision(2) << saldo << '\n';
    }

    void setDefinirSaldo(double saldoInicial)
    {
        saldo = saldoInicial;
    }

    void setDeposito()
    {
        std::string senhaInserida;
        std::cout << "Digite a senha para realizar o depósito: ";
        std::cin >> senhaInserida;

        if (senhaInserida != pessoa.senha)
        {
            std::cout << "Senha incorreta! Depósito não realizado.\n";
            return;
        }

        double quantia;
        std::cout << "Qual valor deseja depositar? ";
        std::cin >> quantia;

        if (quantia <= 0)
        {
            std::cout << "Quantia inválida!\n";
            return;
        }

        saldo += quantia;
        std::cout << "Depósito de R$" << quantia << " realizado com sucesso!\n";
    }

    void setSaque()
    {
        std::string senhaInserida;
        std::cout << "Digite a senha para realizar o saque: ";
        std::cin >> senhaInserida;

        if (senhaInserida != pessoa.senha)
        {
            std::cout << "Senha incorreta! Saque não realizado.\n";
            return;
        }

        double quantia;
        std::cout << "Qual valor deseja sacar? ";
        std::cin >> quantia;

        if (quantia <= 0)
        {
            std::cout << "Quantia inválida!\n";
            return;
        }

        if (quantia > saldo)
        {
            std::cout << "Saldo insuficiente!\n";
            return;
        }

        saldo -= quantia;
        std::cout << "Saque de R$" << quantia << " realizado com sucesso!\n";
    }

    void getMostrarDadosPessoa() const
    {
        pessoa.mostrarDados();
    }

    void setAssociarPessoa(const Pessoa &p)
    {
        pessoa = p;
    }

    void realizarOperacao()
    {
        char operacao;
        std::cout << "Deseja realizar um depósito ou saque? (D/S): ";
        std::cin >> operacao;

        switch (std::tolower(operacao))
        {
        case 'd':
            setDeposito();
            break;

        case 's':
            setSaque();
            break;

        default:
            std::cout << "Operação inválida!\n";
        }
    }
};

int main(int argc, char **argv)
{
    ContaPessoal conta;
    Pessoa pessoa = {"João Silva", 1234, 567890, "1234"};

    conta.setAssociarPessoa(pessoa);
    conta.setDefinirSaldo(0.0);

    conta.getMostrarDadosPessoa();
    conta.getMostrarSaldo();

    conta.realizarOperacao();
    conta.getMostrarSaldo();

    return 0;
}

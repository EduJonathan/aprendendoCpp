#include <iostream>
#include <string>
#include <new>

class Funcionario
{
protected:
    std::string nome;
    int idade;
    double salario;

public:
    // Construtor
    Funcionario(std::string nome, int idade, double salario) : nome(nome), idade(idade), salario(salario) {}

    // Método comum a todos os funcionários
    void apresentar()
    {
        std::cout << "Nome: " << nome << "\nIdade: " << idade << "\nSalário: R$ " << salario << '\n';
    }

    // Método sem 'virtual' (sem polimorfismo)
    void realizarTarefa()
    {
        std::cout << nome << " está realizando uma tarefa genérica." << '\n';
    }
};

class Gerente : public Funcionario
{
public:
    Gerente(std::string nome, int idade, double salario) : Funcionario(nome, idade, salario) {}

    // Sobrescrevendo o método realizarTarefa para o gerente
    void realizarTarefa()
    {
        std::cout << nome << " está gerenciando a equipe e tomando decisões estratégicas." << '\n';
    }

    void apresentar()
    {
        Funcionario::apresentar();
        std::cout << "Cargo: Gerente\n";
    }
};

class Desenvolvedor : public Funcionario
{
public:
    Desenvolvedor(std::string nome, int idade, double salario) : Funcionario(nome, idade, salario) {}

    // Sobrescrevendo o método realizarTarefa para o desenvolvedor
    void realizarTarefa()
    {
        std::cout << nome << " está desenvolvendo software e corrigindo bugs." << '\n';
    }

    void apresentar()
    {
        Funcionario::apresentar();
        std::cout << "Cargo: Desenvolvedor\n";
    }
};

class Assistente : public Funcionario
{
public:
    Assistente(std::string nome, int idade, double salario) : Funcionario(nome, idade, salario) {}

    // Sobrescrevendo o método realizarTarefa para o assistente
    void realizarTarefa()
    {
        std::cout << nome << " está auxiliando na organização de documentos e suporte administrativo." << '\n';
    }

    void apresentar()
    {
        Funcionario::apresentar();
        std::cout << "Cargo: Assistente\n";
    }
};

int main(int argc, char **argv)
{
    // Criando objetos dos diferentes tipos de funcionários
    Funcionario *gerente = new Gerente("Carlos", 45, 8000.00);
    Funcionario *desenvolvedor = new Desenvolvedor("Ana", 30, 5000.00);
    Funcionario *assistente = new Assistente("Lucas", 25, 2500.00);

    // Apresentando informações e realizando tarefas
    std::cout << "\n=== Informações do Gerente ===\n";
    gerente->apresentar();
    gerente->realizarTarefa(); // Chama a versão de 'realizarTarefa()' da classe 'Gerente'

    std::cout << "\n=== Informações do Desenvolvedor ===\n";
    desenvolvedor->apresentar();
    desenvolvedor->realizarTarefa(); // Chama a versão de 'realizarTarefa()' da classe 'Desenvolvedor'

    std::cout << "\n=== Informações do Assistente ===\n";
    assistente->apresentar();
    assistente->realizarTarefa(); // Chama a versão de 'realizarTarefa()' da classe 'Assistente'

    // Liberando memória alocada
    delete gerente;
    delete desenvolvedor;
    delete assistente;

    return 0;
}

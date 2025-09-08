#include <iostream>
#include <memory>
#include <string>

// Interface abstrata
class Pessoa
{
public:
    virtual std::string getInformarPessoa() const = 0;
    virtual ~Pessoa() = default;
};

// Classe base com atributos comuns
class CaracteristicaPessoa : public Pessoa
{
protected:
    std::string nome;
    int idade;
    std::string cpf;
    std::string sexo;

public:
    CaracteristicaPessoa(const std::string &n, int i, const std::string &c, const std::string &s)
        : nome(n), idade(i), cpf(c), sexo(s) {}
};

// Classe derivada Homem
class Homem : public CaracteristicaPessoa
{
private:
    std::string profissao;

public:
    Homem(const std::string &n, int i, const std::string &c, const std::string &s,
          const std::string &prof) : CaracteristicaPessoa(n, i, c, s), profissao(prof) {}

    std::string getInformarPessoa(void) const override
    {
        return "Homem:\nNome: " + nome + "\nIdade: " + std::to_string(idade) +
               "\nCPF: " + cpf + "\nSexo: " + sexo + "\nProfissão: " + profissao + '\n';
    }
};

// Classe derivada Mulher
class Mulher : public CaracteristicaPessoa
{
private:
    std::string escolaridade;

public:
    Mulher(const std::string &n, int i, const std::string &c, const std::string &s,
           const std::string &esc) : CaracteristicaPessoa(n, i, c, s), escolaridade(esc) {}

    std::string getInformarPessoa(void) const override
    {
        return "Mulher:\nNome: " + nome + "\nIdade: " + std::to_string(idade) +
               "\nCPF: " + cpf + "\nSexo: " + sexo + "\nEscolaridade: " + escolaridade + '\n';
    }
};

int main(int argc, char **argv)
{
    Pessoa *pessoa1 = new Homem("Carlos", 35, "123.456.789-00", "Masculino", "Engenheiro");
    Pessoa *pessoa2 = new Mulher("Ana", 28, "987.654.321-00", "Feminino", "Mestrado");

    std::cout << pessoa1->getInformarPessoa();

    std::cout << "\n----------------------------------\n";

    std::cout << pessoa2->getInformarPessoa();

    delete pessoa1;
    delete pessoa2;

    std::cout << "\n----------------------------------\n";

    std::unique_ptr<Pessoa> smartPessoa1 = std::make_unique<Homem>("João", 40, "111.222.333-44", "Masculino", "Professor");
    std::unique_ptr<Pessoa> smartPessoa2 = std::make_unique<Mulher>("Maria", 30, "444.555.666-77", "Feminino", "Doutorado");

    std::cout << smartPessoa1->getInformarPessoa();

    std::cout << "\n----------------------------------\n";

    std::cout << smartPessoa2->getInformarPessoa();
    return 0;
}

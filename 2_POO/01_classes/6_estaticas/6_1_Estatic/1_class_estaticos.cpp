#include <iostream>

// Classe Pessoa, sem ser estática
class Pessoa
{
public:
    std::string nome;
    int idade;

public:
    // Método para exibir informações
    void exibirInfo()
    {
        std::cout << "Nome: " << nome << ", Idade: " << idade << '\n';
    }
};

// Classe Pessoa, com membros estáticos
class PessoaEstatica
{
public:
    static std::string nome;
    static int idade;

    // Método para exibir informações
    static void exibirInfo()
    {
        std::cout << "\nNome: " << nome << ", Idade: " << idade << '\n';
    }
};

// Inicialização dos membros estáticos
std::string PessoaEstatica::nome = "João";
int PessoaEstatica::idade = 30;

int main(int argc, char **argv)
{
    Pessoa pessoa;
    pessoa.nome = "Maria";
    pessoa.idade = 25;
    pessoa.exibirInfo();

    PessoaEstatica::exibirInfo();

    // No resultado, parece que estamos lidando com a mesma informação, mas em contextos diferentes.
    // A classe Pessoa representa uma instância específica, enquanto a classe PessoaEstatica
    // representa informações compartilhadas entre todas as instâncias.
    return 0;
}

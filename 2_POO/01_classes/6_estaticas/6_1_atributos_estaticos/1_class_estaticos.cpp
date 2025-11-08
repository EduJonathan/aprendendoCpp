#include <iostream>
#include <string>

/**
 * Método estático são declarados com a palavra-chave "static" e pertencem à classe,
 * não a instâncias específicas. Eles não têm acesso direto a membros não estáticos.
 *
 * Atributos estáticos são compartilhados entre todas as instâncias da classe.
 *
 * Uso: Para funções utilitárias que não dependem do estado da instância.
 * Atributos estáticos são úteis para contadores ou caches compartilhados e gerenciar
 * dados compartilhados(contadores globais e caches(caches são estruturas de dados que
 * armazenam resultados de operações caras para reutilização posterior)).
 *
 * PROBLEMAS: Metódos estáticos não têm acesso ao ponteiros "this", por não está
 * vinculado a uma instância específica. E não podem chamar métodos não estáticos
 * diretamente ou acessar atributos não estáticos.
 */

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

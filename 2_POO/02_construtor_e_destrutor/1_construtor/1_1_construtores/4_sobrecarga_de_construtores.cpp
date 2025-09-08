#include <iostream>

/**
 * Em um código podemos ter mais de um construtor dentro de uma única classe. Isso é conhecido
 * como sobrecarga de construtores, e permite que objetos sejam inicializados de diferentes
 * maneiras, dependendo dos parâmetros fornecidos.
 *
 * Seu uso é especialmente útil quando queremos criar objetos com diferentes conjuntos de dados
 * ou quando queremos fornecer valores padrão para certos atributos. Seu contexto de usabilidade
 * é em classes que possuem múltiplos atributos ou quando queremos oferecer flexibilidade na
 * inicialização dos objetos.
 *
 * Tenha quantas sobrecargas de construtores quiser em C++,não há limite fixo imposto
 * pela linguagem. O que importa é que cada construtor tenha uma assinatura única, ou seja,
 * um conjunto de parâmetros diferente.
 *
 * Apenas lembre-se:
 *
 * - A ordem e tipo dos parâmetros devem ser diferentes.
 * - Você não pode ter dois construtores com exatamente a mesma assinatura, mesmo que o
 * conteúdo seja diferente.
 */

class Pessoa
{
private:
    std::string nome;
    int idade;

public:
    /**
     * @brief Construtor padrão.
     * Inicializa com nome "Desconhecido" e idade 0.
     */
    Pessoa() : nome("Desconhecido"), idade(0) {}

    /**
     * @brief Construtor com nome e idade.
     * @param nome Nome da pessoa
     * @param idade Idade da pessoa
     */
    Pessoa(const std::string &nome, int idade) : nome(nome), idade(idade) {}

    // Construtor 3: só nome
    Pessoa(const std::string &nome) : nome(nome), idade(0) {}

    // Construtor 4: só idade
    Pessoa(int idade) : nome("Desconhecido"), idade(idade) {}

    // Construtor 5: usando ponteiros (exemplo só pra mostrar variação)
    Pessoa(const char *nome) : nome(nome), idade(0) {}

    /**
     * @brief Construtor de cópia.
     * Cria uma nova instância copiando os valores de outra instância.
     * @param outra Outra instância da classe Pessoa
     */
    Pessoa(const Pessoa &outra) : nome(outra.nome), idade(outra.idade) {}

    // Método para exibir informações da pessoa
    void exibirInformacoes() const
    {
        std::cout << "Nome: " << nome << ", Idade: " << idade << '\n';
    }
};

int main(int argc, char **argv)
{
    // Usando o construtor padrão
    Pessoa pessoa1;
    pessoa1.exibirInformacoes();

    // Usando o construtor com parâmetros
    Pessoa pessoa2("Alice", 30);
    pessoa2.exibirInformacoes();

    // Usando o construtor com só nome
    Pessoa pessoa3("Bob");
    pessoa3.exibirInformacoes();

    // Usando o construtor com só idade
    Pessoa pessoa4(25);
    pessoa4.exibirInformacoes();

    // Usando o construtor com ponteiro
    Pessoa pessoa5("Charlie");
    pessoa5.exibirInformacoes();

    // Usando o construtor de cópia
    Pessoa pessoa6 = pessoa2;
    pessoa6.exibirInformacoes();

    return 0;
}

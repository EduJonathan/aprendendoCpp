#include <iostream>
#include <string>
#include <new>

/**
 * Construtores em Structs na linguagem C++ são funções especiais que são
 * automaticamente chamadas quando um objeto da struct é criado. Eles são usados
 * para inicializar os atributos do objeto e podem ter parâmetros para permitir
 * a configuração inicial dos valores.
 */

#ifndef PESSOA
#define PESSOA

/**
 * @brief Definição da estrutura Pessoa
 */
struct Pessoa
{
    std::string n;  // Atributo para armazenar o nome da pessoa
    unsigned int i; // Atributo para armazenar a idade da pessoa
    float a;        // Atributo para armazenar a altura da pessoa

    // Construtor que inicializa os atributos com valores passados como argumentos
    Pessoa(std::string nome, unsigned int idade, float altura)
    {
        n = nome;   // Inicializa o nome com o valor recebido
        i = idade;  // Inicializa a idade com o valor recebido
        a = altura; // Inicializa a altura com o valor recebido
        std::cout << "Construtor chamado para pessoa: " << nome << '\n';
    }

    // Função para exibir os dados da pessoa
    // 'const' significa que não vamos modificar o objeto
    void exibirPessoa(void) const
    {
        std::cout << "Nome: " << n << '\n';   // Exibe o nome
        std::cout << "Idade: " << i << '\n';  // Exibe a idade
        std::cout << "Altura: " << a << '\n'; // Exibe a altura
    }
};

#endif

#ifndef ANIMAL
#define ANIMAL

/**
 * @brief Definição da estrutura Animal
 */
struct Animal
{
    std::string nome; // Atributo para armazenar o nome do animal
    std::string raca; // Atributo para armazenar a raça do animal

    // Construtor que inicializa os atributos usando uma lista de inicialização
    Animal(std::string n, std::string r) : nome(n), raca(r) {}
    // O construtor inicializa diretamente os atributos 'nome' e 'raca' com os valores recebidos

    // Função para exibir os dados do animal
    // 'const' significa que os objetos não passar por nenhuma alteração
    void exibirAnimal(void) const
    {
        std::cout << "Nome: " << nome << '\n'; // Exibe o nome do animal
        std::cout << "Raça: " << raca << '\n'; // Exibe a raça do animal
    }
};

#endif

int main(int argc, char **argv)
{
    // Criação do objeto 'person' do tipo Pessoa e inicialização com os valores passados
    Pessoa person("Eduardo", 24, 1.80);
    person.exibirPessoa(); // Chama a função para exibir os dados da pessoa

    std::cout << "-------------------\n";

    // Criação do objeto 'animal' do tipo Animal e inicialização com os valores passados
    Animal *animal = new Animal("Totó", "Poodle");
    animal->exibirAnimal(); // Chama a função para exibir os dados do animal
    delete animal;          // Libera a memória alocada para o objeto 'animal'

    /**
     * @note Utilizar construtores em structs no C++ pode ser muito útil quando você
     * precisa de controle sobre a inicialização dos membros ou quando deseja garantir
     * uma inicialização correta e segura.
     *
     * No entanto, deve-se ter cuidado para não complicar demais o código quando uma
     * solução mais simples seria suficiente. Em muitos casos, a decisão dependerá do
     * equilíbrio entre simplicidade e a necessidade de garantir que os objetos sejam
     * inicializados corretamente.
     */
    return 0;
}

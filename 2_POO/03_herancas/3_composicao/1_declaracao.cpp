#include <iostream>
#include <string>

/**
 * Sobre a declaração de composição:
 *
 * Na composição, a classe composta contém diretamente os objetos das classes componentes
 * como membros. Isso significa que os objetos componentes são criados e destruídos
 * junto com a classe composta.
 *
 * A declaração de composição é feita simplesmente incluindo os objetos das classes
 * componentes como membros da classe composta.
 *
 * Declaração de composição:
 * class classeA{
 *   class classeB{};
 * };
 *
 * Porém tenha preferência em uma sintaxe mais clara sobre a composição:
 * class classeB{ // Implementação };
 *
 * class classeA{
 *   classeB objetoB;
 * };
 *
 * Pois a primeira sintaxe pode gerar confusão, fazendo parecer que classeB é uma
 * classe interna de classeA, o que não é o caso na composição.
 */

// Exemplo de composição com sintaxe um pouco confusa
class classeA
{
    class classeB
    {
    public:
        int valor;

    public:
        classeB(int v) : valor(v) {}
    };

    classeB objetoB; // Composição explícita

public:
    classeA() : objetoB(42) {} // classeB criada com classeA
    
    void exibirValor()
    {
        std::cout << "Valor de objetoB: " << objetoB.valor << '\n';
    }
    // Quando classeA é destruída, objetoB também é
};

// Exemplo de composição com sintaxe clara e organizada
class Professor
{
    std::string nome;
    std::string disciplina;
    int idade;

public:
    Professor(const std::string &n, const std::string &d, int i)
        : nome(n), disciplina(d), idade(i) {}

    void exibirInfo() const
    {
        std::cout << "Professor: " << nome
                  << ", Disciplina: " << disciplina
                  << ", Idade: " << idade << '\n';
    }
};

class Universidade
{
    std::string nome;
    std::string endereco;
    Professor professor; // Composição explícita

public:
    Universidade() : nome("UFABC"), endereco("Rua dos Estudantes"), professor("João", "Matemática", 40) {}

    void exibirInfo()
    {
        std::cout << "Universidade: " << nome << ", Endereço: " << endereco << '\n';
        professor.exibirInfo(); // Chamada adicionada
    }
    // Quando Universidade é destruída, professor também é destruído
}; 

int main(int argc, char **argv)
{
    classeA a;        // Cria um objeto da classeA
    Universidade uni; // Cria um objeto da Universidade
    a.exibirValor();
    uni.exibirInfo();
    return 0;
}

#include <iostream>

/**
 * HERANCA: A herança possibilita que as classes compartilhem seus atributos, métodos e
 * outros membros da classe entre si. Para a ligação entre as classes, a herança adota
 * um relacionamento esquematizado hierarquicamente, ou seja, a classe derivada herda
 * os membros da classe base.
 *
 * CUIDADOS: Quanto mais classes e mais heranças forem utilizadas, o programa ficará
 * mais complexo. Por muitas vezes é recomendado usar composição em vez de herança,
 * quando possível, já que a composição (ou seja, incorporar objetos de outras classes
 * como parte de um objeto) tende a ser mais flexível e menos propensa a criar uma rede
 * complexa de dependências.
 *
 * Então o equilíbrio entre herança, composição e outras práticas de design de software é
 * fundamental para manter a complexidade sob controle.
 */

class Pergunta
{
public:
    void pergunta(void)
    {
        std::cout << "Oi! Tudo bem?" << '\n';
    }
};

class Pessoa : public Pergunta
{
public:
    void responde(void)
    {
        std::cout << "Olá! Tudo Bem Sim e Com Você?" << '\n';
    }
};

int main(int argc, char **argv)
{
    // Pergunta perguntar;
    // perguntar.pergunta();
    // perguntar.responde(); // Erro: class "Pergunta" has no member "responde"

    // Tecnicamente a classe Pessoa já vale para os 2 métodos
    // `pergunta` e `responde` por conta da herança.
    // Então declarar a classe `Pergunta` não tem necessidade.

    Pessoa pessoa;
    pessoa.pergunta();
    pessoa.responde();
    return 0;
}

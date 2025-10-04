#include <iostream>

/**
 * Classe hierárquica em programação orientada a objetos em C++, especialmente em linguagens
 * como C++, refere-se a uma estrutura de herança onde uma única classe base é estendida
 * por múltiplas classes derivadas, ou seja são várias classes derivadas que herdam de uma
 * única classe base.
 *
 * Essa organização cria uma hierarquia de classes, com a classe base no topo e as classes
 * derivadas abaixo, cada uma podendo adicionar ou especializar comportamentos.
 */

// Classe base
class Funcionario
{
public:
    void baterPonto()
    {
        std::cout << "Funcionário bateu o ponto." << '\n';
    }
};

// Classe derivada 1
class Professor : public Funcionario
{
public:
    void darAula()
    {
        std::cout << "Professor está dando aula." << '\n';
    }
};

// Classe derivada 2
class Pesquisador : public Funcionario
{
public:
    void fazerPesquisa()
    {
        std::cout << "Pesquisador está realizando uma pesquisa." << '\n';
    }
};

int main(int argc, char **argv)
{
    Professor prof;
    Pesquisador pesq;

    prof.baterPonto();    // Método herdado
    prof.darAula();       // Método específico de Professor
    pesq.baterPonto();    // Método herdado
    pesq.fazerPesquisa(); // Método específico de Pesquisador
    return 0;
}

#include <iostream>

/**
 * A herança híbrida em C++ combina mais de um tipo de herança — por exemplo,
 * herança múltipla e herança hierárquica — em uma única estrutura. Isso pode ser
 * útil para modelar sistemas complexos, mas também exige cuidado para evitar ambiguidade,
 * especialmente com a famosa "Diamond Problem".
 *
 * @note Embora poderosa, a herança híbrida pode aumentar a complexidade do código,
 * então deve ser usada com cautela. Seu uso inadequado pode levar a problemas de manutenção
 * e legibilidade, use-a quando você precisar na seguinte situação:
 *
 * - Quando você precisar combinar comportamentos de múltiplas classes base.
 * - Quando você está lidando com uma hierarquia de classes complexa.
 */

// Classe base
class Pessoa
{
public:
    void mostrarPessoa()
    {
        std::cout << "Sou uma pessoa." << '\n';
    }
};

// Herança hierárquica
class Estudante : public Pessoa
{
public:
    void mostrarEstudante()
    {
        std::cout << "Sou um estudante." << '\n';
    }
};

class Trabalhador : public Pessoa
{
public:
    void mostrarTrabalhador()
    {
        std::cout << "Sou um trabalhador." << '\n';
    }
};

// Herança múltipla
class Estagiario : public Estudante, public Trabalhador
{
public:
    void mostrarEstagiario()
    {
        std::cout << "Sou um estagiário." << '\n';
    }
};

int main(int argc, char **argv)
{
    Estagiario e;

    // Chamando métodos das classes base
    e.mostrarEstudante();
    e.mostrarTrabalhador();
    e.mostrarEstagiario();

    // Ambiguidade: Pessoa está herdada duas vezes
    // e.mostrarPessoa(); // Isso causaria erro de ambiguidade

    // Solução: especificar qual caminho usar
    e.Estudante::mostrarPessoa();
    e.Trabalhador::mostrarPessoa();

    return 0;
}

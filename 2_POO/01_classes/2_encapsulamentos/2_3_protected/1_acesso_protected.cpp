#include <iostream>
#include <string>

/**
 * PROTECTED: É um nível de encapsulamento semelhante ao private, ou seja, também oculta
 * os membros da classe para o mundo externo. A diferença é que membros protected são
 * acessíveis pelas classes derivadas.
 *
 * Em C++, o protected é comumente usado em herança, quando você deseja esconder certos
 * detalhes da implementação do código externo, mas ainda permitir que classes filhas
 * possam interagir com esses membros.
 *
 * Use protected quando você está projetando uma classe base para ser estendida, e
 * deseja que as subclasses tenham acesso a determinados atributos ou métodos internos,
 * sem expô-los publicamente.
 */

class Casa
{
private:
    std::string cofreSecreto = "Segredo da casa (nível privado)";

protected:
    std::string trancaEletronica = "Senha da porta (nível protegido)";

public:
    std::string campainha = "Toque a campainha (nível público)";

public:
    void acessarCasa()
    {
        std::cout << "Acessando como dono da casa (método interno da própria classe):" << '\n';
        std::cout << "- " << cofreSecreto << '\n';
        std::cout << "- " << trancaEletronica << '\n';
        std::cout << "- " << campainha << '\n';
        std::cout << '\n';
    }
};

void visitanteTentaAcessar(Casa &casa)
{
    std::cout << "Visitante tentando acessar:" << '\n';
    // std::cout << "- " << casa.cofreSecreto << '\n';
    // std::cout << "- " << casa.trancaEletronica << '\n';
    std::cout << "- " << casa.campainha << '\n';
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    Casa casa;

    casa.acessarCasa();          // A própria classe pode acessar tudo
    visitanteTentaAcessar(casa); // Visitante só acessa o public
}

#include <iostream>
#include <string>
#include <memory>

// Classe Base
class Pessoa
{
public:
    std::string nome;
    Pessoa(const std::string &name) : nome(name) {}

    void apresentar(void)
    {
        std::cout << "Olá, meu nome é " << nome << "." << '\n';
    }
};

// Classe Derivada (Nível 1)
class Estudante : public Pessoa
{
public:
    std::string curso;
    Estudante(const std::string &name, const std::string &course) : Pessoa(name), curso(course) {}

    void apresentar(void)
    {
        Pessoa::apresentar();
        std::cout << "Eu estou estudando " << curso << "." << '\n';
    }
};

// Classe Derivada (Nível 2)
class EstudanteUniversitario : public Estudante
{
public:
    std::string universidade;
    EstudanteUniversitario(const std::string &name, const std::string &course,
                           const std::string &uni) : Estudante(name, course),
                                                     universidade(uni) {}

    void apresentar(void)
    {
        Estudante::apresentar();
        std::cout << "Eu estudo na universidade " << universidade << "." << '\n';
    }
};

int main(int argc, char **argv)
{
    // Cada classe de Estudante vai herdando as características da classe Pessoa e da anterior,
    // Formando assim uma cadeia de herança(Pessoa -> Estudante -> EstudanteUniversitario).
    // Pois a herança multi-nível serve como base para outras classes.

    std::unique_ptr<EstudanteUniversitario> eu = std::make_unique<EstudanteUniversitario>("Eduardo", "Engenharia de Software", "UFRJ");
    eu->apresentar();
    return 0;
}

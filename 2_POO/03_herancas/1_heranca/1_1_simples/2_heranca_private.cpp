#include <iostream>

/**
 * A herança **private** em C++ faz com que todos os membros públicos e protegidos
 * da classe base se tornem privados na classe derivada. Isso restringe o acesso direto
 * a esses membros fora da classe derivada, incluindo por objetos da própria classe derivada.
 *
 * Apenas a própria classe derivada tem acesso a esses membros, e suas subclasses
 * ou código externo não conseguem acessá-los.
 *
 * É usada quando se deseja **ocultar** os membros da classe base da classe derivada,
 * limitando seu uso apenas dentro da própria classe derivada, sem expô-los externamente.
 *
 * Exemplo:
 * Se a classe `Cachorro` herda de `Animal` com herança private, seus métodos e atributos de `Animal`
 * não serão acessíveis nem mesmo por objetos de `Cachorro`, mas sim somente pela implementação
 * de `Cachorro`.
 */

class Exemplo1
{
public:
    int atributoPublico;

protected:
    int atributoProtegido;

private:
    int atributoPrivado;
};

// Classe derivada, onde a classe Exemplo2 herda privadamente de Exemplo1
class Exemplo2 : private Exemplo1
{
public:
    void acessarAtributos(void)
    {
        atributoPublico = 1;   // Acesso permitido, porém se torna privado em Exemplo2
        atributoProtegido = 2; // Acesso permitido, porém se torna privado em Exemplo2
        // atributoPrivado = 3; // Erro: não é possível acessar atributoPrivado
    }
};

class Base
{
public:
    void mostrarMensagem()
    {
        std::cout << "Mensagem da classe Base\n";
    }
};

class Derivada : private Base
{
public:
    // Método público da classe derivada que acessa o método da base
    void chamarBase()
    {
        mostrarMensagem(); // permitido: acesso dentro da classe derivada
    }
};

int main(int argc, char **argv)
{
    Exemplo2 exemplo2;
    /* exemplo2.atributoPublico = 1; */ // Acesso permitido, porém não é possível acessar fora de Exemplo2

    std::cout << "-------------------\n";

    Derivada obj;

    /* obj.mostrarMensagem(); */ // Erro: método agora é privado em Derivada
    obj.chamarBase();            // Correto: chama o método da base indiretamente

    return 0;
}

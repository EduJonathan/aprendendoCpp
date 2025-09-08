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

class Ponto_x
{
private:
    int value_x;

public:
    void setX(void)
    {
        std::cout << "Digite o valor de x: ";
        std::cin >> value_x;
    }

    void getX(void)
    {
        std::cout << "O valor de x é: " << value_x << '\n';
    }
};

class Ponto_y : private Ponto_x
{
private:
    int value_y;

public:
    void setY(void)
    {
        std::cout << "Digite o valor de y: ";
        std::cin >> value_y;
    }

    void getY(void)
    {
        std::cout << "O valor de y é: " << value_y << '\n';
    }

    // Como herdou de forma privada, precisa de métodos intermediários para acessar setX/getX
    void definirX(void)
    {
        setX(); // ok: acesso permitido dentro da classe derivada
    }

    void mostrarX(void)
    {
        getX(); // ok: acesso permitido dentro da classe derivada
    }
};

int main(int argc, char **argv)
{
    Exemplo2 exemplo2;
    /* exemplo2.atributoPublico = 1; */ // Acesso permitido, porém não é possível acessar fora de Exemplo2

    std::cout << "-------------------\n";

    Ponto_y pontoY;

    // pontoY.setX();  // ERRO: setX() agora é privado em Ponto_y
    pontoY.definirX(); // Correto: usa método público da própria classe
    pontoY.setY();

    // pontoY.getX();  // ERRO: getX() também é privado em Ponto_y
    pontoY.mostrarX(); // Correto
    pontoY.getY();
    return 0;
}

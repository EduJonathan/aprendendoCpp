#include <iostream>
#include <algorithm>

/**
 * A herança pública em C++ permite que os membros públicos e protegidos de uma classe base
 * se tornem acessíveis diretamente na classe derivada. Isso facilita a reutilização de
 * código e a especialização de comportamento, permitindo que a classe derivada herde os
 * métodos e atributos da classe base.
 *
 * É comum quando se deseja que a classe derivada seja uma extensão da classe base,
 * mantendo a mesma interface pública.
 *
 * Em resumo:
 * - A classe derivada pode acessar os membros públicos e protegidos da classe base.
 * - Permite estender ou modificar o comportamento da classe base sem alterar sua interface.
 * - Usada quando a relação entre as classes é de "especialização" (ex: um tipo de outro).
 *
 * Exemplo:
 * A classe `Cachorro` herda de `Animal`, podendo usar o método `comer()` da classe base
 * e adicionar seu próprio método `latir()`.
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

// Classe derivada, onde a classe Exemplo2 herda publicamente de Exemplo1
class Exemplo2 : public Exemplo1
{
public:
    void acessarAtributos(void)
    {
        atributoPublico = 1;   // Acesso permitido
        atributoProtegido = 2; // Acesso permitido
        // atributoPrivado = 3; // Erro: atributoPrivado é privado
    }
};

class Ponto
{
private:
    int x;

public:
    void setX(void)
    {
        std::cout << "Digite o valor de x: ";
        std::cin >> x;
    }

    void getX(void)
    {
        std::cout << "O valor de x é: " << x << '\n';
    }

    int getValorX(void) const
    {
        return x;
    }

    void setValorX(int valor)
    {
        x = valor;
    }

    int &getValorXRef(void)
    {
        return x;
    }
};

class Point : public Ponto
{
private:
    int y;

public:
    void setY(void)
    {
        std::cout << "Digite o valor de y: ";
        std::cin >> y;
    }

    void getY(void)
    {
        std::cout << "O valor de y é: " << y << '\n';
    }

    void trocarXY(void)
    {
        std::swap(y, getValorXRef());
    }
};

int main(int argc, char **argv)
{
    Exemplo1 exemplo1;
    exemplo1.atributoPublico = 1;
    // exemplo1.atributoProtegido = 2; // Acesso negado
    // exemplo1.atributoPrivado = 3; // Erro: atributoPrivado é privado

    std::cout << "-------------------\n";

    Point ponto;

    ponto.setX();
    ponto.setY();

    std::cout << "\nAntes da troca:\n";
    ponto.getX();
    ponto.getY();

    ponto.trocarXY();

    std::cout << "\nDepois da troca:\n";
    ponto.getX();
    ponto.getY();
    return 0;
}

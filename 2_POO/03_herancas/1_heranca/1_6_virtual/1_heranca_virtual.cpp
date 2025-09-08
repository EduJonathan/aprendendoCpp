#include <iostream>

class Animal
{
public:
    void comer()
    {
        std::cout << "A classe Animal está comendo" << '\n';
    }
};

class Mamifero : virtual public Animal
{
public:
    void respirar()
    {
        std::cout << "A classe Mamífero está respirando" << '\n';
    }
};

class Ave : virtual public Animal
{
public:
    void voar()
    {
        std::cout << "A classe Ave está voando" << '\n';
    }
};

class Morcego : public Mamifero, public Ave
{
public:
    void ecolocalizar()
    {
        std::cout << "A classe Morcego está ecolocalizando" << '\n';
    }
};

/**
 * HERANÇA VIRTUAL - RESOLVENDO O PROBLEMA DO DIAMANTE:
 *
 * A classe Morcego herda de Mamifero e Ave, que por sua vez herdam de Animal.
 * Sem herança virtual, isso causaria o problema do diamante: duas instâncias de Animal.
 *
 * Usando `virtual public Animal` em Mamifero e Ave, garantimos que apenas UMA instância
 * de Animal seja herdada por Morcego, evitando ambiguidade ao chamar métodos como `comer()`.
 *
 * Use herança virtual quando houver herança múltipla com uma classe base comum (problema do diamante).
 * Evite em herança simples ou quando a complexidade não justifica — pode ser desnecessária e
 * introduzir overhead.
 */

int main(int argc, char **argv)
{
    Morcego bat;

    bat.comer();        // Herdado de Animal (sem ambiguidade)
    bat.respirar();     // Herdado de Mamifero
    bat.voar();         // Herdado de Ave
    bat.ecolocalizar(); // Definido em Morcego

    return 0;
}

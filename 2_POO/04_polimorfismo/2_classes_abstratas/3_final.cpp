#include <iostream>

/**
 * FINAL: A keyword `final` em C++, introduzida no C++11, é utilizada em 2 situações
 * heranças e métodos virtuais, onde podemos:
 * 1. Impedir que uma classe seja herdada.
 * 2. Impedir que um método virtual seja sobrescrito em classes derivadas.
 *
 * Isso aumenta a flexibilidade e controle sobre códigos extensivos, ao mesmo tempo
 * em que garante que certas partes da hierarquia de classes permaneçam inalteradas
 * e melhorar a legibilidade e otimização do compilador.
 */

// <== Final em classe ==>
class MyClass final
{
public:
    void method();
};

// Não é possível herdar de MyClass, erro: a 'final' class type cannot be used as a base class
// class MyDerivedClass : public MyClass
//{
// public:
// void method();
//};

// <== Final em método ==>
class MyBaseClass
{
public:
    virtual void method() final
    {
        std::cout << "A classe base não pode ser herdada mas o metodo não pode ser sobrescrito." << '\n';
    };

    virtual void metodo() const
    {
        std::cout << "Metodo virtual que pode ser sobrescrito." << '\n';
    }
};

class MyDerivedClass final : public MyBaseClass
{
public:
    // void method() override;

    void metodo() const override
    {
        std::cout << "Metodo sobrescrito na classe derivada." << '\n';
    }
};

int main(int argc, char **argv)
{
    MyDerivedClass MyClass; // Criação de um MyClass da classe derivada
    MyClass.metodo();       // Chamada do método sobrescrito
    return 0;
}

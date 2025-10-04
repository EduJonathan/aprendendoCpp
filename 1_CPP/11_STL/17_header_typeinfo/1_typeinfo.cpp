#include <iostream>
#include <new>
#include <memory>
#include <typeinfo>

/**
 * A <typeinfo> é uma biblioteca da STL em C++ que fornece informações sobre os
 * tipos dos objetos em tempo de execução. Ela faz parte do mecanismo
 * de RTTI (Run-Time Type Information).
 *
 * Permite consultar o tipo estático ou dinâmico de uma expressão em tempo de execução (RTTI)
 * com o operador typeid, foi implementado no C++20.
 */

class Base
{
    virtual void dummy() {}
};
class Derivada : public Base
{
};

class base
{
public:
    virtual ~base() = default; // Necessário para RTTI funcionar corretamente
};

class Derived : public base
{
};

int main(int argc, char **argv)
{
    int inteiro = 42;
    std::cout << "Tipo de inteiro: " << typeid(inteiro).name() << '\n';

    std::string str = "42";
    std::cout << "Tipo de string: " << typeid(str).name() << '\n';

    char *ponteiro = new char;
    std::cout << "Tipo ponteiro para char: " << typeid(*ponteiro).name() << '\n';

    Base *obj = new Derivada;
    std::cout << "Tipo dinâmico: " << typeid(*obj).name() << '\n';

    // Criando objeto com smart pointer (unique_ptr)
    std::unique_ptr<base> object = std::make_unique<Derived>();

    // typeid no objeto apontado (*object) – RTTI
    std::cout << "Tipo dinâmico com smart Pointers: " << typeid(*object).name() << '\n';

    delete obj;
    delete ponteiro;
    // Não precisa de delete – o unique_ptr faz isso automaticamente

    // A expressão typeid(objeto) retorna uma referência para um objeto do tipo std::type_info.
    // Esse objeto contém informações sobre o tipo do objeto passado.
    // Utilizado em objetos polimorfismo para descobrir o tipo real de um objeto apontado
    // por um ponteiro ou referência de classe base.
    // O typeid com objetos não polimórficos em ponteiros pode causar resultados inesperados.
    return 0;
}

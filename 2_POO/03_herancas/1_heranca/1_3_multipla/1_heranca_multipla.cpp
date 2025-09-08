#include <iostream>

/**
 * Herança múltipla em C++ permite que uma classe herde de mais de uma classe base.
 * Isso pode ser útil para combinar funcionalidades de diferentes classes, mas
 * também pode levar a desafios como o "problema do diamante" quando duas classes
 * bases compartilham uma ancestral comum.
 */

class A
{
public:
    void showA(void)
    {
        std::cout << "Classe A" << '\n';
    }
};

class B
{
public:
    void showB(void)
    {
        std::cout << "Classe B" << '\n';
    }
};

// Classe C herdando de A e B
class C : public A, public B
{
public:
    void showC(void)
    {
        std::cout << "Classe C" << '\n';
    }
};

int main(int argc, char **argv)
{
    C obj;
    obj.showA(); // Método da classe A
    obj.showB(); // Método da classe B
    obj.showC(); // Método da classe C
    return 0;
}

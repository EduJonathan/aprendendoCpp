#include <iostream>
#include <typeinfo>

int main(int argc, char **argv)
{
    int a = 5;
    double b = 3.14;

    if (typeid(a) == typeid(b))
    {
        std::cout << "Tipos iguais" << '\n';
    }
    else
    {
        std::cout << "Tipos diferentes" << '\n';
    }

    return 0;
}

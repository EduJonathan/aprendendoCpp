#include <iostream>

class Matematica
{
public:
    static int contador;

    static int somar(int a, int b)
    {
        return a + b;
    }

    void incrementar()
    {
        contador++;
    }
};

int Matematica::contador = 0;

int main(int argc, char **argv)
{
    std::cout << "Soma: " << Matematica::somar(5, 3) << '\n';

    Matematica::contador = 10;
    std::cout << "Contador: " << Matematica::contador << '\n';

    Matematica math;
    math.incrementar();
    std::cout << "Contador: " << Matematica::contador << '\n';

    return 0;
}

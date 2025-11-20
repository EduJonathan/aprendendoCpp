#include <iostream>

class Contador
{
private:
    int contador;

public:
    Contador() : contador(0) {}

    int get_contador() const
    {
        return contador;
    }

    void operator++()
    {
        ++contador;
        std::cout << "Incremento pré-fixado chamado. Novo valor: " << contador << '\n';
    }

    void operator++(int)
    {
        contador++;
        std::cout << "Incremento pós-fixado chamado. Novo valor: " << contador << '\n';
    }
};

int main(int argc, char **argv)
{
    Contador contador1, contador2;

    std::cout << "Contador1 inicial: " << contador1.get_contador() << '\n';
    std::cout << "Contador2 inicial: " << contador2.get_contador() << '\n';

    ++contador1;
    ++contador2;
    contador2++;

    std::cout << "Contador1 inicial: " << contador1.get_contador() << '\n';
    std::cout << "Contador2 inicial: " << contador2.get_contador() << '\n';

    return 0;
}

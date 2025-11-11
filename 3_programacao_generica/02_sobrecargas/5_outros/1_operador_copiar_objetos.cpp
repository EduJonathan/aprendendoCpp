#include <iostream>
#include <new>

class MinhaClasse
{
public:
    int valor;

    MinhaClasse &operator=(const MinhaClasse &outro)
    {
        valor = outro.valor;
        return *this;
    }
};

class ExemploComHeranca : public MinhaClasse
{
public:
    int outroValor;

    ExemploComHeranca &operator=(const ExemploComHeranca &outro)
    {
        if (this != &outro)
        {
            MinhaClasse::operator=(outro);
            outroValor = outro.outroValor;
        }
        return *this;
    }
};

template <typename T>
void copiarObjeto(const T &origem, T &destino)
{
    destino = origem;
    std::cout << "Objeto copiado com sucesso!\n";
    std::cout << "Valor de destino: " << destino.valor << '\n';
    std::cout << "Valor de destino: " << destino.outroValor << '\n';
}

int main(int argc, char **argv)
{
    MinhaClasse *obj1 = new MinhaClasse;
    MinhaClasse *obj2 = new MinhaClasse;
    obj1->valor = 42;
    *obj2 = *obj1;

    std::cout << "Valor de obj2: " << obj2->valor << '\n';
    delete obj1;
    delete obj2;

    ExemploComHeranca *obj3 = new ExemploComHeranca;
    ExemploComHeranca *obj4 = new ExemploComHeranca;
    obj3->valor = 42;
    obj3->outroValor = 84;
    *obj4 = *obj3;

    std::cout << "Valor de obj4: " << obj4->valor << ", " << obj4->outroValor << '\n';

    copiarObjeto(*obj3, *obj4);
    delete obj3;
    delete obj4;
    return 0;
}

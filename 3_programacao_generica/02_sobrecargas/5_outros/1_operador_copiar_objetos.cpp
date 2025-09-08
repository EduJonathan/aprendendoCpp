#include <iostream>
#include <new>

/**
 * A sobrecarga do operador de atribuição (=) permite definir como um objeto deve
 * ser copiado para outro, substituindo a cópia superficial (shallow copy) por uma
 * cópia profunda (deep copy), além de evitar problemas relacionados à duplicação de
 * recursos e melhorar a sintaxe de atribuição.
 *
 * Exemplo com método explícito de cópia:
 * Pessoa p1("João");
 * Pessoa p2("Maria");
 * p2.copiar(p1);  // Copia o conteúdo de p1 para p2
 *
 * Com a sobrecarga do operador de atribuição:
 * Pessoa p1("João");
 * Pessoa p2("Maria");
 * p2 = p1;  // Chama o operador de atribuição, realizando a cópia
 *
 * A **cópia profunda** é a maneira mais segura de garantir que objetos com recursos alocados
 * dinamicamente sejam copiados corretamente, criando uma cópia completa de seus dados.
 * Sem isso, você pode acabar com uma cópia rasa, onde apenas os ponteiros são copiados
 * e não os dados reais, o que pode resultar em conflitos e acesso inválido de memória.
 *
 * Caso um objeto aloque memória dinamicamente e você não sobrecarregue o operador de atribuição
 * e o construtor de cópia, o compilador usará o operador de atribuição padrão, que realiza
 * uma cópia rasa. Nesse caso, tanto o objeto original quanto o copiado podem compartilhar o
 * mesmo espaço de memória, resultando em problemas como **'double free'** ou **'segmentation fault'**.
 *
 * Quando usar:
 * - Quando você precisa de uma cópia profunda (deep copy) de um objeto.
 * - Quando um objeto contém ponteiros para recursos dinâmicos (como memória alocada).
 * - Quando você deseja personalizar o comportamento de cópia de um objeto.
 */

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

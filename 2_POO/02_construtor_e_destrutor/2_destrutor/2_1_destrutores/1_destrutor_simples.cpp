#include <iostream>

/**
 * DESTRUTOR: Semelhante ao construtor, com a diferença que no destrutor, eles não
 * recebem argumentos e não retornam valores, denominado por um '~' e o mesmo nome
 * da classe, os destrutores são chamados quando um objeto da classe ou estrutura é
 * utilizado para destruir o objeto.
 * Importância no trabalho de recursos como memória, arquivos, abertura de conexões, etc.
 *
 * Quando usar: Quando você precisa liberar recursos ou realizar ações de limpeza
 * ao destruir um objeto.
 */

class Object
{
private:
    char letra;

public:
    Object(char l) : letra(l)
    {
        std::cout << "Objeto Construtor criado chamado para a letra: " << letra << '\n';
    }

    ~Object()
    {
        std::cout << "Objeto Destrutor chamado para a letra: " << letra << '\n';
    }

    Object print(void)
    {
        Object obj('B');
        return obj;
    }
};

int main(int argc, char **argv)
{
    Object obj('A');
    obj.print();
    return 0;
}

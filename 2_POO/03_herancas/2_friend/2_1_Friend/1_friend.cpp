#include <iostream>

/**
 * A keyword "friend" em C++ permite que uma função ou outra classe tenha acesso
 * a membros privados e protegidos de uma classe, mesmo que não sejam membros delas.
 * Útil quando você precisa de uma função ou classe que interaja com o estado interno
 * de outra classe, sem expor os detalhes dessa outra classe e sem tornar todos os
 * detalhes acessíveis ao mundo exterior.
 *
 * @note friend NÃO é um meio de herança, mas sim um meio de colaboração entre classes.
 * Uma forma de acesso controlado aos membros privados de uma classe.
 */

class FRIEND
{
private:
    int x; // Atributo privado
    int y; // Atributo privado

public:
    /* Construtor da classe */
    FRIEND(int valorX, int valorY) : x(valorX), y(valorY) {}

    /* Função amiga */
    friend int exibirValor(FRIEND f);
};

/**
 * @brief Função amiga que exibe um valor calculado a partir dos atributos de um objeto FRIEND.
 *
 * Esta função acessa diretamente os membros privados da classe FRIEND e calcula
 * a soma dos atributos x e y, subtraindo 5 do resultado.
 *
 * @param amigo Objeto da classe FRIEND cujos atributos serão acessados.
 * @return O resultado da expressão f.x + f.y - 5.
 */
int exibirValor(FRIEND amigo)
{
    return static_cast<double>(amigo.x + amigo.y - 5);
    // return amigo.x + amigo.y - 5;
}

int main(int argc, char **argv)
{
    FRIEND Friend(100, 200);
    std::cout << "Valor calculado: " << exibirValor(Friend) << '\n';
    return 0;
}

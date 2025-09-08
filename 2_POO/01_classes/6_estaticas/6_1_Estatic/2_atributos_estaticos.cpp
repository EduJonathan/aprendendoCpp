#include <iostream>

/**
 * Método estático são declarados com a palavra-chave "static" e pertencem à classe,
 * não a instâncias específicas. Eles não têm acesso direto a membros não estáticos.
 *
 * Atributos estáticos são compartilhados entre todas as instâncias da classe.
 *
 * Uso: Para funções utilitárias que não dependem do estado da instância. (ex: Matematica::somar)
 * Atributos estáticos são úteis para contadores ou caches compartilhados e gerenciar
 * dados compartilhados(contadores globais e caches(caches são estruturas de dados que
 * armazenam resultados de operações caras para reutilização posterior)).
 *
 * PROBLEMAS: Metódos estáticos não têm acesso ao ponteiros "this", por não está vinculado a uma
 * instância específica. E não podem chamar métodos não estáticos diretamente ou acessar atributos
 * não estáticos.
 */

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

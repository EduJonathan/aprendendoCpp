#include <iostream>
#include <span>
#include <vector>

/**
 * std::span é uma visão (view) sobre uma sequência contínua de elementos.
 * Não é um container, ou seja, não possui os dados, apenas "aponta para eles".
 * Pode ser usado como uma referência leve e segura a arrays ou partes de arrays,
 * inclusive em funções.
 *
 * std::span não possui os dados, então os dados devem viver tempo suficiente
 * (não usar com variáveis locais temporárias que saem de escopo).
 * Ele não aloca memória — apenas aponta para uma sequência já existente.
 * Disponível a partir do C++20
 *
 * | Vantagem             | Explicação                                               |
 * | -------------------- | -------------------------------------------------------- |
 * | **Segurança**        | Evita ponteiros crus ou manipulação insegura             |
 * | **Performance**      | Leve (sem alocação), passa por referência                |
 * | **Versatilidade**    | Funciona com `std::vector`, C-arrays, `std::array`, etc. |
 * | **Sem cópias**       | Ideal para leitura ou manipulação temporária de dados    |
 * | **Compatibilidade**  | Integra-se bem com outras partes da STL                  |
 */

void imprimir(std::span<int> dados)
{
    for (int valor : dados)
    {
        std::cout << valor << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char **argv)
{
    std::vector<int> numeros = {10, 20, 30, 40, 50};

    imprimir(numeros);                  // span de todo o vector
    imprimir({numeros.begin() + 1, 3}); // span parcial (20, 30, 40)

    int array[] = {1, 2, 3};
    imprimir(array); // também funciona com arrays C

    /**
     * Compile com: g++ -std=c++20 span.cpp -o span
     * ./span
     */
    return 0;
}

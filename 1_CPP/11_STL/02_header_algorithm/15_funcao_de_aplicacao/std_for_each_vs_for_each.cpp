#include <iostream>
#include <vector>
#include <algorithm>

/**
 * | Característica       | std::for_each()             | Range-based for                        |
 * +----------------------+-----------------------------+----------------------------------------+
 * | Sintaxe              | Mais verbosa                | Mais limpa e intuitiva                 |
 * | Performance          | Pode ter overhead de função | Geralmente mais eficiente              |
 * | Flexibilidade        | Aceita qualquer callable    | Apenas corpo do loop                   |
 * | Controle do iterador | Explícito (begin/end)       | Implícito                              |
 * | Modificação          | Pode modificar elementos    | Pode modificar (depende da declaração) |
 *
 * ------------------------------------
 *
 * A (std::for_each) como função:
 *
 * - Overhead de chamada: Cada elemento gera uma chamada à função/lambda.
 * - Stack frame: Cria um frame de pilha para cada invocação.
 * - Profundidade de chamada: Pode contribuir para o call stack
 * - Pode ser inlined (depende do compilador e otimizações)
 *
 * ------------------------------------
 *
 * Como código (ranged-based):
 * - Sem overhead de função: O código é expandido inline.
 * - Sem stack frame adicional: Executa no contexto atual.
 * - Sem profundidade extra: Não aumenta call stack.
 * - Sempre otimizável: O compilador vê como um loop tradicional.
 *
 * Use range-based for para a maioria dos casos, e std::for_each()
 * apenas quando precisar da flexibilidade de usar funções/lambdas complexas ou reutilizáveis.
 */

int main(int argc, char **argv)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Range-based for (mais comum)
    for (int valor : vec)
    {
        std::cout << valor << ' ';
    }
    std::cout << '\n';

    // std::for_each (útil para operações complexas)
    std::for_each(vec.begin(), vec.end(), [](int &n)
    {
        n *= 2; // Dobra cada valor
    });

    // Verificando o resultado
    for (int valor : vec)
    {
        std::cout << valor << ' '; // 2 4 6 8 10
    }
    std::cout << '\n';

    return 0;
}

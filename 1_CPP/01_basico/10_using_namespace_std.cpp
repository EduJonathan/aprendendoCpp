#include <iostream>
#include <algorithm> // Possui uma função chamada count, que pode ser chamada como std::count()
#include <string>

/**
 * É realmente uma má prática usar `using namespace std;`?
 *
 * Não é *tecnicamente* errado, mas costuma ser considerado uma **má prática** —
 * sobretudo em projetos grandes ou bibliotecas — devido aos riscos que traz.
 *
 * Por que evitar:
 * 1. Conflitos de nomes:
 *    A libc++ define identificadores comuns como `vector`, `list`, `count`, etc.
 *    Importar todo o namespace `std` pode causar colisões com outras bibliotecas
 *    ou com o próprio código.
 *
 * 2. Menos clareza:
 *    `std::cout`, `std::string`, etc., deixam explícito que o identificador pertence à biblioteca padrão.
 *
 * 3. Manutenção difícil:
 *    Em projetos grandes, `using namespace std;` aumenta a chance de ambiguidade
 *    e torna o código menos previsível. O prefixo `std::` evita esses problemas.
 *
 * Boas práticas:
 * - Em arquivos .cpp pequenos ou exemplos simples: pode ser usado com cautela.
 * - Em arquivos de cabeçalho (.h/.hpp): **evite sempre** para não poluir o namespace de quem incluir o arquivo.
 *
 * Conclusão:
 * Use `using namespace std;` de forma consciente. Em geral, prefira `std::`
 * para manter clareza, segurança e melhor manutenção.
 *
 * Observação:
 * Outras bibliotecas também oferecem namespaces amplos, como `cv`, `Qt` e `Eigen`.
 * Assim como com `std`, importá-las com `using namespace` pode simplificar o código,
 * mas deve ser feito com cuidado para evitar conflitos e preservar a legibilidade.
 */

using namespace std;

void minhaFuncao(void)
{
    /* using namespace std; */
    // Só afeta o escopo dentro da função, porém, tenha preferência pela importação seletiva,
    // como mostrado abaixo para evitar poluição do namespace.

    using std::cout;
    using std::endl;
    cout << "Função executada: Olá" << endl;
}

// Haverá conflito com std::count (função da STL da header <algorithm>)
int count = 10;

int main(int argc, char **argv)
{
    // `string string` Aqui não haverá ambiguidade, pois maioria do problema da ambiguidade
    // ocorre quando usamos `using namespace std;` no escopo global, assim como está acontecendo
    // com a variável global `int count` pois quando você a chama `count`, o compilador não sabe
    // se você está se referindo à variável global ou à função `std::count` da header <algorithm>.
    string string;
    string = "String";
    cout << string << endl;

    cout << "-----------------------------------" << '\n';

    // Qual `count` será usado a variável ou da header <algorithm>? Terá Ambiguidade!
    // cout << count << endl;

    cout << "-----------------------------------" << '\n';
    cout << "ESCOPO `::` (Resolução de Ambiguidades)" << '\n';
    cout << "-----------------------------------" << '\n';

    // 1. Variável local
    int count = 20;

    // Imprime 20 (local)
    cout << "count (local): " << count << '\n';

    // 2. Variável global
    cout << "::count (global): " << ::count << '\n'; // Imprime 10 (acessa o global explícito)

    // 3. Função global (std) - Note que 'std' é um namespace
    cout << "Resultado (std::count): " << std::count(string.begin(), string.end(), 'a') << '\n';

    minhaFuncao();

    /**
     * Este código é para vermos o quão poluido pode ficar a leitura e escrita do código
     * ao utilizar `using namespace std` ou qualquer outro derivado que em si não é errado,
     * mas devemos ter boas práticas para evitar problemas com namespaces:
     *
     * 1. Evite `using namespace std;` no escopo global para prevenir:
     *    - Poluição do namespace.
     *    - Conflitos de nomes (ex.: std::count vs. variável count).
     *    - Perda de clareza na origem dos identificadores.
     *
     * 2. Prefira qualificadores explícitos (`std::cout`, `std::string`).
     * 3. Use importações seletivas (`using std::cout;`) em escopos locais, se necessário.
     * 4. Escolha nomes descritivos para variáveis (ex.: `texto` em vez de `string`).
     * 5. Use o operador `::` para resolver conflitos de escopo, como em `::global_counter`.
     */
    return 0;
}

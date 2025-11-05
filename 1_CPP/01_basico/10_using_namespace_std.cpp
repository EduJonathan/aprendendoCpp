#include <iostream>
#include <algorithm> // Possui uma função chamada count, que pode ser chamada como std::count()
#include <string>

/**
 * Afinal, utilizar `using namespace std;` é uma má prática?
 *
 * Tecnicamente, não é *intrinsecamente* errado, mas é considerado uma **má prática**
 * em muitos contextos, especialmente em projetos maiores ou bibliotecas, devido aos
 * riscos e problemas que pode causar.
 *
 * Por que evitar `using namespace std;`:
 *
 * 1. Conflito de nomes:
 * - A biblioteca padrão define nomes genéricos e comuns como `vector`, `list`, `count`, etc.
 * - Ao importar todo o namespace `std`, esses nomes ficam disponíveis no escopo global,
 * o que pode causar colisões com nomes de outras bibliotecas ou do próprio código.
 *
 * 2. Redução da legibilidade:
 * - Escrever `std::cout`, `std::string`, etc., torna o código mais claro ao
 * indicar que esses identificadores pertencem à biblioteca padrão.
 *
 * 3. Manutenção e escalabilidade:
 * - Em projetos maiores, com muitas bibliotecas e arquivos, o uso de `using namespace std;`
 * aumenta o risco de ambiguidades e conflitos entre nomes.
 * - Manter o uso explícito de `std::` melhora a clareza e evita problemas futuros.
 *
 * Boas práticas recomendadas:
 *
 * - Em arquivos .cpp pequenos, como programas de teste ou scripts simples:
 * Pode-se usar `using namespace std;` com cautela.
 *
 * - Em arquivos de cabeçalho (.h/.hpp):
 * **Evite sempre** — poluir o namespace de quem incluir o cabeçalho pode gerar sérios problemas.
 *
 * Conclusão:
 * Use `using namespace std;` com consciência. Em geral, prefira o uso explícito de `std::`
 * para melhorar a segurança, clareza e manutenção do seu código.
 *
 * Curiosidade:
 * Há outros `using namespace` padrões de outras bibliotecas(de terceiros sendo mais explicíto), como por exemplo
 * `using namespace cv` - Biblioteca de manipulação de imagens
 * `using namespace Qt` - Biblioteca para implementação de interface gráfica (GUI)
 * `using namespace Eigen` - Usada para álgebra linear, manipulação eficiente de matrizes e vetores.
 *
 * Dentre várias outras
 *
 * Assim como em `std`, usar `using namespace` dessas bibliotecas pode facilitar o código,
 * mas deve ser feito com cuidado para evitar conflitos e manter a clareza.
 */

using namespace std;

void minhaFuncao(void)
{
    /* using namespace std; */
    // Só afeta o escopo dentro da função, porém, tenha preferência pela importação seletiva para evitar poluição do namespace
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
     * 6. Prefira `\n` a `std::endl` para evitar flushes desnecessários.
     */
    return 0;
}

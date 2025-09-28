#include <iostream>
#include <algorithm> // Possui uma função chamada count, que pode ser chamada como std::count()
#include <string>

/**
 * Afinal, utilizar `using namespace std;` é uma má prática?
 *
 * Tecnicamente, não é *intrinsecamente* errado, mas é considerado uma **má prática** em muitos
 * contextos, especialmente em projetos maiores ou bibliotecas, devido aos riscos e problemas
 * que pode causar.
 *
 * Por que evitar `using namespace std;`:
 *
 * 1. Conflito de nomes:
 * - A biblioteca padrão define nomes genéricos e comuns como `vector`, `list`, `count`, etc.
 * - Ao importar todo o namespace `std`, esses nomes ficam disponíveis no escopo global,
 * o que pode causar colisões com nomes de outras bibliotecas ou do próprio código.
 *
 * 2. Redução da legibilidade:
 * - Escrever `std::cout`, `std::string`, etc., torna o código mais claro ao indicar que
 * esses identificadores pertencem à biblioteca padrão.
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
 * Há outros `using namespace` padrões de outras bibliotecas, como por exemplo
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
    // using namespace std; // Só afeta o escopo da função
    // Porém, tenha preferência pela importação seletiva para evitar poluição do namespace
    using std::cout;
    using std::endl;

    cout << "Olá" << endl;
}

int count = 10; // Haverá conflito com std::count (função da STL da header <algorithm>)

int main(int argc, char **argv)
{
    // `string string` Aqui não haverá ambiguidade, pois a ambiguidade só aparece se você
    // trouxer todo o namespace std para o escopo onde a variável global count também é visível.
    // Por isso string não está visível e não será ambíguo
    string string;
    string = "String";
    cout << string << endl;

    std::cout << "-----------------------------------" << '\n';

    // Qual `count` será usado a variável ou da header <algorithm>? Terá Ambiguidade!
    // cout << count << endl;

    std::cout << "-----------------------------------" << '\n';
    std::cout << "ESCOPO `::`" << '\n';

    // O operador de resolução de escopo é para acessar membros dentro de um
    // namespace, classe, funções podendo até mesmo variáveis e funções de outros headers.

    int count = 20;
    std::cout << count << '\n';   // Imprime 20 (local)
    std::cout << ::count << '\n'; // Imprime 10 (global)

    /**
     * Este código é para nós vermos o quão poluido pode ficar a leitura, utilizar `using namespace std`
     * ou qualquer outro derivado não é errado, mas boas práticas devemos evitar com namespaces:
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

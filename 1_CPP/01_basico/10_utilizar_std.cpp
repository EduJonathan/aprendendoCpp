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
 * - Melhor ainda: importar apenas o que for necessário com `using std::cout;`, `using std::string;`, etc.
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
    using namespace std; // Só afeta o escopo da função
    cout << "Olá" << endl;
}

int count = 10; // Haverá conflito com std::count (função da STL da header <algorithm>)

int main(int argc, char **argv)
{
    // Uns dos problemas é justamente na sintaxe, exemplo declarando uma string: `std::string string`
    string string;

    // Qual `count` será usado a variável ou da header <algorithm>? Terá Ambiguidade!
    // cout << count << endl;

    return 0;
}

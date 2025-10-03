#include <iostream> // (input/output stream): Biblioteca para realizar entrada e saída de dados

/**
 * std::cout — Objeto da classe std::ostream usado para imprimir dados no console (saída padrão).
 *
 * COMPONENTES:
 *
 * - std: É um namespace (espaço de nomes) que agrupa classes, funções e objetos da
 * biblioteca padrão do C++. Ele evita conflitos de nomes entre bibliotecas diferentes.
 *
 * - :: (operador de resolução de escopo): Usado para acessar membros dentro de um
 * namespace ou classe. Exemplo: std::cout acessa o objeto cout dentro do namespace std.
 *
 * - cout (console output): Objeto responsável por exibir saídas no terminal.
 * Outros objetos semelhantes incluem:
 * - std::cin: Entrada padrão (teclado)
 * - std::cerr: Saída de erro
 * - std::clog: Saída de log
 *
 * - << (operador de inserção): Envia dados para um fluxo de saída, como std::cout.
 * É sobrecarregado (overloaded) para aceitar vários tipos de dados: strings,
 * inteiros, floats, etc. Isso permite usar o mesmo operador para imprimir diferentes
 * tipos sem precisar de formatadores, como ocorre em C (ex: printf("%d %s %f")).
 *
 * - using namespace std;: Permite omitir o prefixo 'std::' em elementos do namespace std.
 * Torna o código mais limpo em exemplos pequenos, mas deve ser evitado em projetos grandes
 * para prevenir conflitos de nomes.
 */

/* using namespace std; */ // Para usar o namespace std globalmente
/* using std::cout; */     // Usar APENAS o std::cout globalmente, inserindo no código cout
/* using std::endl; */     // Usar APENAS o std::endl globalmente, inserindo no código endl

int main(int argc, char **argv)
{
    std::cout << "std::cout << Imprimindo o texto: Hello World" << std::endl;
    // std::endl ou stander end line('\n') objeto para quebra de linha.
    // para outros caracteres de escape como ('\t'), ('\r') e ('\b') não existe o std::,
    // tendo que ser inserido diretamente no texto ou depois dos caracteres '<<'.

    std::cout << std::endl
              << "===========================================" << std::endl;
    std::cout << "\nCARACTERES \v DE \t ESCAPES" << std::endl;
    std::cout << "===========================================" << '\n';

    // cout << endl << "Sem utilizar o std::cout para imprimir texto" << endl;
    return 0;
}

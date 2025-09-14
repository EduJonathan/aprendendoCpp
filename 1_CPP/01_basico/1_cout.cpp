#include <iostream> // (input/output stream): Biblioteca para realizar entrada e saída de dados

/**
 * std::cout (standard console output): É um objeto da classe std::ostream que permite imprimir textos e valores no console.
 *
 * `std` => É um namespace (espaço de nomes), um contêiner que agrupa classes, objetos
 * e funções relacionadas da biblioteca padrão C++ (STL). Ele garante que os nomes
 * definidos dentro dele não entrem em conflito com outros nomes fora dele.
 *
 * `::` => É o operador de resolução de escopo, usado para acessar membros dentro de um namespace ou classe.
 *
 * `cout(console output)` => É o objeto de saída padrão (console), assim como `cin`
 * é para entrada e `cerr` para saída de erros, dentre outros. Todos fazem parte do
 * namespace `std`.
 *
 * `<<` => É o operador de inserção ostream(output stream), usado para enviar
 * (ou "inserir") dados para o fluxo de saída. Ele é sobrecarregado pois como é para
 * diferentes tipos de dados, como strings, números inteiros, ponto flutuante, etc.
 * Isso permite que o operador seja usado de forma genérica, porém mais flexível,
 * facilitando a impressão de diferentes tipos no console, sem necessitar de
 * formatadores como visto em C.
 *
 * `using namespace std;` => É utilizado para que não seja necessário escrever `std::`
 * ou qualquer outro derivado, onde torna-se global para que antes de cada elemento do
 * namespace `std` (como `cout`, `cin`, `endl`, etc.), tornando o código mais limpo,
 * porém deve ser usado com cautela para evitar conflitos de nomes em programas maiores.
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

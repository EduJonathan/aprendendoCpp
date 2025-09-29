#include <iostream>

/**
 * std::cin — Objeto da classe std::istream usado para entrada de dados pelo console (entrada padrão).
 *
 * Conceito:
 * - Similar ao std::cout, mas utilizado para entrada em vez de saída.
 * - Permite que o usuário digite valores durante a execução do programa.
 *
 * Componentes:
 *
 * - >> (operador de extração): Lê dados do fluxo de entrada (teclado) e armazena em variáveis.
 * É sobrecarregado para aceitar diferentes tipos de dados (int, float, string, etc.).
 * Exemplo: std::cin >> idade;
 *
 * - std (namespace): Assim como outros componentes da biblioteca padrão (como cout, cerr, endl), o cin também está dentro do namespace std.
 *
 * - using namespace std;: Permite usar apenas `cin` em vez de `std::cin`.
 * Exemplo: cin >> nome;
 * No entanto, deve ser usado com cuidado em projetos maiores para evitar conflitos de nomes.
 */

/* using namespace std; */ // Linha para usar o namespace std globalmente
/* using std::cin; */      // Usar APENAS o std::cin globalmente, inserindo no código cin

int main(int argc, char **argv)
{
    std::cout << "LEITURA COM std::cin" << '\n';

    // Declarando uma variável do tipo inteiro.
    int x = 4;

    // Imprimindo o valor da variável antes do std::cin.
    std::cout << "Valor de x antes do std::cin: " << x << '\n';

    // Utilizando o std::cin para receber um número do usuário.
    std::cout << "Digite um número: ";
    std::cin >> x;
    std::cout << "Você digitou: " << x << '\n';

    std::cout << "---------------------------------" << '\n';
    std::cout << "CAPTURA DE MÚLTIPLOS DADOS" << '\n';

    // Declarando duas variáveis de tipos char e int
    char letra = '\0';
    int num = 0;

    // Utilizando o std::cin para receber diretamente uma letra e um número do usuário.
    std::cout << "Digite uma letra e numero: ";
    std::cin >> letra >> num;
    std::cout << "Você digitou a letra: " << letra << " e número: " << num << '\n';
    return 0;
}

#include <iostream>

/**
 * std::cin (stander console input): Objeto este que permite que o usuário digite um valor.
 *
 * Mesmo conceito do std::cout, mas para entrada de dados. Com a diferença na
 * sua sobrecarga, sendo ele o `>>` do tipo istream(input stream), que permite
 * a leitura sobrecarregando diferentes tipos de dados.
 *
 * Podendo ter escopo global utilizando o `using namespace std;` para que não
 * fique utilizando `std::` para cada elemento, ficando assim `cin >> variável`.
 */

/* using namespace std; */ // Linha para usar o namespace std globalmente
/* using std::cin; */      // Usar APENAS o std::cout globalmente, inserindo no código cin

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

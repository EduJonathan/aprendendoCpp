#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Lvalue e Rvalue
 *
 * - Lvalue (locator value): Representa um objeto que ocupa uma localização identificável na memória.
 * Pode aparecer no lado esquerdo de uma atribuição.
 *
 * - Rvalue (read value): É um valor temporário que não tem uma localização identificável na memória.
 * Geralmente aparece no lado direito de uma atribuição.
 *
 * Referências em Sites:
 * https://learn.microsoft.com/pt-br/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=msvc-170
 * https://medium.com/@pkgmalinda/modern-c-understanding-lvalues-rvalues-and-std-move-6ef6f00c6ea7
 * https://pt.stackoverflow.com/questions/6373/o-que-s%C3%A3o-os-rvalues-lvalues-xvalues-glvalues-e-prvalues
 * https://github.com/jeaye/value-category-cheatsheet/blob/master/value-category-cheatsheet.pdf
 * https://en.cppreference.com/w/cpp/language/value_category.html
 * https://www.learncpp.com/cpp-tutorial/value-categories-lvalues-and-rvalues/
 */

void func(int &x) { std::cout << "Lvalue\n"; }
void func(int &&x) { std::cout << "Rvalue\n"; }

int main(int argc, char **argv)
{
    int x = 10;
    x = 20;        // 'x' é um lvalue
    int y = 5 + 3; // '5 + 3' é um rvalue

    std::cout << "\n=================================================" << '\n';

    std::cout << "Erros que podem ser cometidos" << '\n';

    /* 5 = x; */       // expression must be a modifiable lvalueC/C++(137)
    /* int &&r = x; */ // ERRO: 'x' é lvalue, não pode inicializar rvalue reference

    std::string a = "hello";
    /* std::string &&b = a; */ // ERRO: a é lvalue, precisa de std::move(a)
    std::string &&b = std::move(a);

    int value = 10;
    /* func(value); */     // Lvalue
    /* func(10); */        // Rvalue
    /* func(value + 5); */ // Rvalue

    std::cout << "\n=================================================" << '\n';

    std::vector<std::string> nomes = {"Ana", "Bruno", "Carlos"};

    std::cout << "1. Loop por cópia (modifica a cópia):\n";
    for (std::string nome : nomes)
    {
        nome += " (Modificado)";
        std::cout << nome << " ";
    }

    std::cout << "\n\nVetor original:\n";
    for (const std::string &nome : nomes)
    {
        std::cout << nome << " ";
    }

    std::cout << "\n\n2. Loop por referência (modifica o vetor original):\n";
    for (std::string &nome : nomes)
    {
        nome += " [Editado]";
        std::cout << nome << " ";
    }

    std::cout << "\n\n3. Loop por referência constante (somente leitura):\n";
    for (const std::string &nome : nomes)
    {
        std::cout << nome << " ";
        // nome += "erro"; // ERRO: não pode modificar const reference
    }

    std::cout << "\n\n4. Loop com std::move (simula rvalue):\n";
    for (std::string &nome : nomes)
    {
        std::string novo_nome = std::move(nome); // Transfere o conteúdo
        std::cout << "Movido: " << novo_nome << " | Original: " << nome << "\n";
    }

    // std::cout << "\n5. Loop com rvalue reference (raro de se ver no range-based for):\n";
    // std::vector<std::string> outros = {"João", "Lucas", "Maria"};

    // std::string&& normalmente não se usa assim, mas apenas por curiosidade:

    // for (std::string &&nome : std::move(outros))
    // {
    // A "outros" agora é um vetor vazio ou inválido após std::move
    // std::cout << "Nome movido: " << nome << "\n";
    // }

    return 0;
}

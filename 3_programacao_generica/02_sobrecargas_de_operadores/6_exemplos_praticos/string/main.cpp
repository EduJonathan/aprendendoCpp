#include <iostream>
#include "string.hpp"

int main(int argc, char **argv)
{
    std::cout << "=== Testes da classe Str ===\n\n";

    // Construtor padrão
    Str a;
    std::cout << "a (vazia): \"" << a << "\" | length = " << a.length() << '\n';

    // Construtor com const char*
    Str b("Ola");
    Str c(" Mundo");
    std::cout << "b: " << b << '\n';
    std::cout << "c: " << c << '\n';

    // operator+
    Str d = b + c;
    std::cout << "d = b + c: " << d << '\n';

    // operator+=
    b += c;
    std::cout << "b += c: " << b << '\n';

    // Construtor de cópia
    Str e = d;
    std::cout << "e (copia de d): " << e << '\n';

    // Construtor de movimento
    Str f = std::move(e);
    std::cout << "f (movido de e): " << f << '\n';
    std::cout << "e apos move: \"" << e << "\" | empty = " << e.empty() << '\n';

    // Atribuição por cópia
    Str g;
    g = f;
    std::cout << "g (atribuicao por copia de f): " << g << '\n';

    // Atribuição por movimento
    Str h;
    h = std::move(g);
    std::cout << "h (atribuicao por movimento de g): " << h << '\n';
    std::cout << "g apos move: \"" << g << "\" | empty = " << g.empty() << '\n';

    // operator[]
    try
    {
        std::cout << "h[0] = " << h[0] << '\n';
        h[0] = 'o';
        std::cout << "h apos alterar h[0]: " << h << '\n';

        // Deve lançar exceção
        std::cout << h[100] << '\n';
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Excecao capturada: " << e.what() << '\n';
    }

    // Comparações
    Str x("abc");
    Str y("xyz");

    std::cout << "\nComparacoes:\n";
    std::cout << "x = " << x << ", y = " << y << '\n';
    std::cout << "x == y: " << (x == y) << '\n';
    std::cout << "x != y: " << (x != y) << '\n';
    std::cout << "x <  y: " << (x < y) << '\n';
    std::cout << "x <= y: " << (x <= y) << '\n';
    std::cout << "x >  y: " << (x > y) << '\n';
    std::cout << "x >= y: " << (x >= y) << '\n';

    // clear()
    h.clear();
    std::cout << "\nh apos clear(): \"" << h << "\" | empty = " << h.empty() << '\n';

    // Entrada com operator>>
    Str input;
    std::cout << "\nDigite uma palavra: ";
    std::cin >> input;
    std::cout << "Voce digitou: " << input << '\n';

    // Entrada com getline_str
    Str line;
    std::cout << "\nDigite uma linha inteira: ";
    std::cin.ignore(); // limpa o '\n' anterior
    getline_str(std::cin, line);
    std::cout << "Linha: " << line << '\n';

    std::cout << "\n=== Fim dos testes ===\n";
    return 0;
}

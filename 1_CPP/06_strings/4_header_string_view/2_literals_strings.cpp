#include <iostream>
#include <typeinfo> // biblioteca que fornece informações sobre os tipos dos objetos em tempo de execução, como typeid e name.
#include <string>
#include <string_view>

/**
 * O namespace std::literals::string_literals faz parte da biblioteca padrão do C++
 * (introduzido no C++14) e define o operador de sufixo `s` para criar objetos
 * std::string diretamente a partir de strings literais. Ele permite que você transforme
 * uma string literal (como "texto") em um objeto std::string de forma conveniente e eficiente,
 * sem a necessidade de construções explícitas.
 *
 * Características principais:
 *
 * - Sufixo `s`: O operador `s` converte uma string literal em um objeto std::string.
 *
 * - Namespace: Está definido em std::literals::string_literals,
 * dentro do namespace mais amplo std::literals.
 *
 * - Inclusão: Requer a inclusão da `header <string>` e o uso explícito do namespace
 * std::literals::string_literals ou std::literals.
 *
 * - Objetivo: Facilitar a criação de objetos std::string em vez de usar `const char*` ou
 * construir `std::string` manualmente.
 *
 * Quando usar?
 * - Quando você precisa de um objeto std::string (que possui os dados e gerencia a memória)
 * a partir de uma string literal.
 *
 * - Para melhorar a legibilidade do código, evitando construções como std::string("texto").
 *
 * - Em contextos onde você precisa de funcionalidades específicas de std::string, como
 * concatenação ou modificação, que não estão disponíveis em std::string_view.
 */

using namespace std::literals::string_literals;

int main(int argc, char **argv)
{
    // Exemplo com std::string_view
    std::string_view str_view = "Mundo!";
    std::cout << str_view << '\n';
    std::cout << "Tipo: " << typeid(str_view).name() << '\n';

    // Exemplo com std::string
    std::string str = "Hello, World!"s; // ou auto str = "Hello, World!"s;
    std::cout << str << '\n';
    std::cout << "Tipo: " << typeid(str).name() << '\n';

    return 0;
}

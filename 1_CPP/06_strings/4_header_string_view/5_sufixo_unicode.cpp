#include <string>
#include <iostream>

/**
 * Além do sufixo s para std::string com caracteres char, o namespace std::literals::string_literals
 * também suporta sufixos para strings Unicode (introduzidos em C++11/C++20):
 *
 * - u8"s": Cria um std::u8string (string UTF-8, disponível em C++20).
 * - u"s": Cria um std::u16string (string UTF-16).
 * - U"s": Cria um std::u32string (string UTF-32).
 * - L"s": Cria um std::wstring (string de caracteres largos, dependente da plataforma).
 *
 * Quando usar std::literals::string_literals?
 *
 * - Use o sufixo s quando você precisa de um objeto std::string que possua os dados e seja modificável.
 *
 * - Prefira sv (de std::literals::string_view_literals) quando você só precisa de uma visão
 * não-destrutiva e não quer alocar memória.
 *
 * - Use sufixos Unicode (u8"s", u"s", U"s", L"s") quando trabalhar com codificações específicas,
 * especialmente em aplicações que lidam com internacionalização.
 *
 * CUIDADOS:
 *
 * - Custo de memória: O sufixo s cria um std::string, que aloca memória e copia os dados,
 * enquanto sv (de std::string_view) não copia, sendo mais eficiente.
 *
 * - Namespace explícito: Você deve incluir using namespace std::literals::string_literals; ou using
 * namespace std::literals; para usar o sufixo s. Usar apenas using namespace std; não é suficiente.
 *
 * - Compatibilidade: O sufixo u8"s" requer C++20. Os outros (u"s", U"s", L"s") estão disponíveis desde C++11.
 */

using namespace std::literals::string_literals;

int main(int argc, char **argv)
{
    auto u8str = u8"Olá, mundo!"s; // std::u8string (UTF-8, C++20)
    auto u16str = u"Olá, mundo!"s; // std::u16string (UTF-16)
    auto u32str = U"Olá, mundo!"s; // std::u32string (UTF-32)
    auto wstr = L"Olá, mundo!"s;   // std::wstring (caracteres largos)

    std::cout << u8str.size() << '\n'; // Tamanho em bytes (UTF-8)
    /// NOTA: Imprimir u16str, u32str ou wstr pode exigir conversão dependendo da plataforma
    return 0;
}

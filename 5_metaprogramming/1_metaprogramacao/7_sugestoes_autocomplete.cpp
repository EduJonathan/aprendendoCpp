#include <iostream>
#include <array>
#include <string_view>

// Keywords do C++
constexpr std::array keywords = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof",
    "static", "struct", "switch", "typedef", "union", "unsigned", "void",
    "volatile", "while"};

// Fixed string para template
template <std::size_t N>
struct FixedString
{
    char data[N]{};
    constexpr FixedString(const char (&str)[N])
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            data[i] = str[i];
        }
    }

    constexpr std::string_view sv() const
    {
        return std::string_view(data, N - 1); // N-1 para excluir o '\0'
    }
};

// Template com dedução automática
template <FixedString Prefix>
consteval auto filtrar_palavras()
{
    constexpr std::string_view prefix = Prefix.sv();

    // Contar quantas começam com o prefixo
    constexpr std::size_t count = []() constexpr
    {
        std::size_t n = 0;
        for (const char *k : keywords)
        {
            std::string_view sv(k);
            if (sv.starts_with(prefix))
            {
                ++n;
            }
        }
        return n;
    }();

    // Array com tamanho exato
    std::array<std::string_view, count> resultado{};

    // Preencher o array
    std::size_t i = 0ull;
    for (const char *k : keywords)
    {
        std::string_view sv(k);
        if (sv.starts_with(prefix))
        {
            resultado[i++] = sv;
        }
    }
    return resultado;
}

// Macro pra deixar bonito
#define PALAVRAS_COM(prefix) filtrar_palavras<prefix>()

int main(int argc, char **argv)
{
    constexpr auto com_i = PALAVRAS_COM("i");   // if, int
    constexpr auto com_un = PALAVRAS_COM("un"); // union, unsigned
    constexpr auto com_s = PALAVRAS_COM("s");   // short, signed, sizeof, static, struct, switch

    // Testes
    static_assert(com_i.size() == 2);
    static_assert(com_un.size() == 2);
    static_assert(com_s.size() == 6);

    // Verificar conteúdos
    static_assert(com_i[0] == "if");
    static_assert(com_i[1] == "int");
    static_assert(com_un[0] == "union");
    static_assert(com_un[1] == "unsigned");

    std::cout << "Palavras com 'i': ";
    for (auto w : com_i)
    {
        std::cout << w << ' ';
    }
    std::cout << '\n';

    std::cout << "Palavras com 'un': ";
    for (auto w : com_un)
    {
        std::cout << w << ' ';
    }
    std::cout << '\n';

    std::cout << "Palavras com 's': ";
    for (auto w : com_s)
    {
        std::cout << w << ' ';
    }
    std::cout << '\n';

    std::cout << "Total com 's': " << com_s.size() << '\n';

    /**
     * Por conta de consteval que foi introduzida no C++20, Compile com
     *
     * g++ -std=c++20 -Wall -Wextra -pedantic -O2 7_sugestoes_autocomplete.cpp -o autocomplete
     * ./autocomplete
     */

    return 0;
}

#include <iostream>
#include <iomanip>
#include <clocale>
#include <string_view>
#include <uchar.h>

using namespace std::literals::string_view_literals;

int main(int argc, char **argv)
{
    // Configura a localidade para suportar UTF-8
    std::setlocale(LC_ALL, "en_US.UTF-8");

    // Cria uma string_view UTF-8
    std::u8string_view u8sv = u8"Olá, mundo!"sv;

    // Converte cada caractere UTF-8 para UTF-32 usando funções de <uchar>
    mbstate_t state = {};
    char32_t c32;
    const char8_t *ptr = u8sv.data();
    std::size_t len = u8sv.size();
    std::size_t i = 0;

    while (i < len)
    {
        std::size_t converted = mbrtoc32(
            &c32,
            reinterpret_cast<const char *>(ptr + i),
            len - i,
            &state);

        if (converted == 0 || converted == static_cast<std::size_t>(-1) || converted == static_cast<std::size_t>(-2))
        {
            break; // Erro ou fim da string
        }

        std::cout << "Caractere UTF-32: U+"
                  << std::hex << std::uppercase << static_cast<u_int32_t>(c32)
                  << '\n';

        i += converted;
    }

    /**
     * Compile e execute com:
     * g++ -std=c++20 .\2_string_UTF_8.cpp
     * .\a.exe
     */

    return 0;
}

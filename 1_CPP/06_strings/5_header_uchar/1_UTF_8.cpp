#include <iostream>
#include <string_view>

/**
 * A header <uchar> (abreviação de "Unicode character") define tipos de dados e funções
 * para manipular caracteres Unicode e suas codificações. Ela foi projetada para suportar
 * a interoperabilidade com texto codificado em UTF-8, UTF-16 e UTF-32, que são padrões
 * amplamente utilizados para representar caracteres Unicode.
 *
 * Tipos de caracteres Unicode:
 * - char8_t (C++20): Um tipo para representar caracteres em UTF-8. É um tipo distinto (geralmente
 * um alias para unsigned char ou similar, dependendo da implementação).
 *
 * - char16_t: Um tipo para representar caracteres em UTF-16 (16 bits por unidade de código).
 * - char32_t: Um tipo para representar caracteres em UTF-32 (32 bits por unidade de código).
 *
 * Funções de conversão:
 *
 * Funções para converter entre diferentes codificações Unicode, como `mbrtoc16`, `c16rtomb`,
 * `mbrtoc32`, e `c32rtomb`. Essas funções ajudam a converter entre sequências de caracteres
 * multibyte (por exemplo, UTF-8) e caracteres largos (UTF-16 ou UTF-32).
 *
 * Constantes:
 * - MB_CUR_MAX: Uma macro que indica o tamanho máximo (em bytes) de um caractere multibyte
 * na localidade atual.
 *
 * OBJETIVO DE USO:
 *
 * - Trabalhar com texto Unicode em diferentes codificações de forma portátil.
 *
 * - Suportar internacionalização em aplicações, especialmente ao manipular texto
 * em línguas que usam caracteres fora do conjunto ASCII.
 *
 * - Integrar com outras partes da biblioteca padrão, como std::string_view, para
 * manipular strings codificadas em UTF-8, UTF-16 ou UTF-32.
 */

using namespace std::literals::string_view_literals;

int main(int argc, char **argv)
{
    std::u8string_view u8sv = u8"Olá, mundo!";    // UTF-8 string view
    std::u16string_view u16sv = u"Hello, world!"; // UTF-16 string view
    std::u32string_view u32sv = U"Hello, world!"; // UTF-32 string view

    std::cout << u8sv.size() << '\n';  // Tamanho em bytes (UTF-8)
    std::cout << u16sv.size() << '\n'; // Número de char16_t
    std::cout << u32sv.size() << '\n'; // Número de char32_t

    /**
     * Compile e execute com:
     * g++ -std=c++20 .\1_UTF_8.cpp
     * .\a.exe
     */
    return 0;
}

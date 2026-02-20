#include "../include/roman_converter.hpp"
#include "../include/roman_any_converter.hpp"
#include <iostream>
#include <array>

int main(int argc, char **argv)
{
    using Standard = RomanConverter<StandardRomanPolicy>;
    using Additive = RomanConverter<AdditiveRomanPolicy>;

    Standard std;
    Additive add;

    // Array heterogêneo! Agora permitido graças ao type-erasure
    std::array<RomanAnyConverter, 2> converters = {
        RomanAnyConverter(std),
        RomanAnyConverter(add)};

    std::array<const char *, 2> names = {
        "Padrão (IV, IX, CM…)",
        "Aditivo (IIII, XXXX…)"};

    std::array<int, 7> values = {4, 9, 40, 90, 1990, 3999, 2025};

    for (std::size_t i = 0; i < converters.size(); ++i)
    {
        std::cout << "=== " << names[i] << " ===\n";

        for (int n : values)
        {
            std::string roman = converters[i].toRoman(n);
            int back = converters[i].fromRoman(roman);

            std::cout << n << " → " << roman
                      << " → " << back
                      << " (ok: " << (n == back ? "sim" : "não") << ")\n";
        }

        std::cout << '\n';
    }

    /**
     * Para Compilar:
     * g++ -std=c++17 ./main.cpp ./policies.cpp -o nome_executavel
     * ./nome_do_executavel
     */

    return 0;
}

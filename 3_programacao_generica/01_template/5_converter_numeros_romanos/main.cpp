#include "StandardRomanConverter.hpp"
#include "AdditiveRomanConverter.hpp"
#include <iostream>
#include <new>

int main(int argc, char **argv)
{
    const RomanConverter *converters[] = {
        new StandardRomanConverter(),
        new AdditiveRomanConverter()};

    const char *names[] = {"Padrão (IV, IX...)", "Aditivo (IIII, XXXX)"};

    int numbers[] = {4, 9, 1990, 3999, 2025};

    for (std::size_t c = 0; c < 2; ++c)
    {
        std::cout << "\n=== " << names[c] << " ===\n";
        for (int n : numbers)
        {
            std::string roman = converters[c]->toRoman(n);
            int back = converters[c]->fromRoman(roman);
            std::cout << n << " → " << roman
                      << " → " << back << " (volta correta: "
                      << (back == n ? "sim" : "não") << ")\n";
        }
    }

    // Teste com string literals
    const StandardRomanConverter standard;
    std::cout << "\n\"MMXXV\" = " << standard("MMXXV") << '\n';
    std::cout << "2025 em romano = " << standard(2025) << '\n';

    // Limpeza
    delete converters[0];
    delete converters[1];

    /**
     * Para Compilar com C++17:
     * g++ -std=c++17 StandardRomanConverter.cpp AdditiveRomanConverter.cpp main.cpp -o converter_numeros_romanos
     * ./converter_numeros_romanos
     */
    return 0;
}

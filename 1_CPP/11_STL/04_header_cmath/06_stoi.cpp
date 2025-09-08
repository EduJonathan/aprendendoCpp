#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <stdexcept>

/**
 * std::stoi(param x, param y, param z): Converte uma string para um inteiro.
 *
 * O primeiro parâmetro é a string a ser convertida.
 * O segundo é um ponteiro para um inteiro que receberá o
 * índice do primeiro caractere não convertido.
 * O terceiro é a base numérica (opcional, padrão é 10).
 */

int main(int argc, char **argv)
{
    std::string str = "12345";
    size_t idx = 0ull;
    int base = 10;

    try
    {
        int num = std::stoi(str, &idx, base);
        std::cout << "Número convertido: " << num << '\n';
        std::cout << "Índice do primeiro caractere não convertido: " << idx << '\n';
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Argumento inválido: " << e.what() << '\n';
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Valor fora do intervalo: " << e.what() << '\n';
    }

    return 0;
}

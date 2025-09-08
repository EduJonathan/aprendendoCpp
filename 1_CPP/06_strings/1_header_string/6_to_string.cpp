#include <iostream>
#include <string>

/**
 * std::to_string(): É uma função que converte valores numéricos em suas representações
 * de string. Isso é particularmente útil quando você precisa exibir valores numéricos
 * ou quando deseja combinar números com outras strings.
 *
 * A função to_string é sobrecarregada para diferentes tipos numéricos:
 * como int, float, unsigned, signed double, e long.
 */

int main(int argc, char **argv)
{
    int num = 42;
    std::string str = std::to_string(num);
    std::cout << "Número convertido: \"" << str << '\"' << '\n';

    return 0;
}

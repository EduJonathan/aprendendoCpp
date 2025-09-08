#include <iostream>
#include <cstdlib>

// std::div_t(): Retorna o quociente e resto de uma divisão.

int main(int argc, char **argv)
{
    int x = 4;
    int y = 4;

    // Usando std::div para obter o quociente e o resto com int
    std::div_t div_result = std::div(x, y);

    std::cout << "Com int:" << '\n';
    std::cout << "Quociente: " << div_result.quot << '\n';
    std::cout << "Resto: " << div_result.rem << '\n';

    std::cout << "-----------------------------------------" << '\n';

    long lx = 100000L;
    long ly = 3000L;

    // Usando std::ldiv para obter o quociente e o resto com long
    std::ldiv_t ldiv_result = std::ldiv(lx, ly);

    std::cout << "\nCom long:" << '\n';
    std::cout << "Quociente: " << ldiv_result.quot << '\n';
    std::cout << "Resto: " << ldiv_result.rem << '\n';

    std::cout << "-----------------------------------------" << '\n';

    long long llx = 15000ll;
    long long lly = 3000ll;

    // Usando std::lldiv para obter o quociente e o resto com long long
    std::lldiv_t lldiv_result = std::lldiv(llx, lly);

    std::cout << "\nCom long long:" << '\n';
    std::cout << "Quociente: " << lldiv_result.quot << '\n';
    std::cout << "Resto: " << lldiv_result.rem << '\n';

    return 0;
}

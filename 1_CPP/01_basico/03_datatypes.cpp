#include <iostream>
#include <string>  // Incluindo a biblioteca string, necessária para declarar std::string
#include <limits>  // Para acessar constantes definidas para tipos númericos em C++
#include <climits> // Para constantes relacionadas a valores inteiros (Relacionado ao limits.h de C)
#include <cfloat>  // Para constantes relacionadas a valores flutuantes (Relacionado ao float.h de C)

/**
 * DATATYPES: São declarações que definem os tipos de dados, como inteiros, reais, caracteres,
 * strings, etc. Todos com seus respectivos tamanhos em bytes de memória e limites de
 * precisão. Praticamente sendo os mesmo da linguagem C.
 */

int main(int argc, char **argv)
{
    std::cout << "\n\t>> EXIBINDO TAMANHO DE BYTES DE CADA TIPO DE DADO <<\n";

    std::cout << "\n========= TIPOS INTEIROS =========\n";

    std::cout << "int: " << sizeof(int) << " bytes\n";
    std::cout << "signed: " << sizeof(signed) << " bytes\n";
    std::cout << "short: " << sizeof(short) << " bytes\n";
    std::cout << "signed short: " << sizeof(signed short) << " bytes\n";
    std::cout << "long: " << sizeof(long) << " bytes\n";
    std::cout << "signed long: " << sizeof(signed long) << " bytes\n";
    std::cout << "long long: " << sizeof(long long) << " bytes\n";
    std::cout << "signed long long: " << sizeof(signed long long) << " bytes\n";
    std::cout << "unsigned: " << sizeof(unsigned) << " bytes\n";
    std::cout << "unsigned short: " << sizeof(unsigned short) << " bytes\n";
    std::cout << "unsigned long: " << sizeof(unsigned long) << " bytes\n";
    std::cout << "unsigned long long: " << sizeof(unsigned long long) << " bytes\n";

    std::cout << "\n========= PONTO FLUTUANTE =========\n";

    std::cout << "float: " << sizeof(float) << " bytes\n";
    std::cout << "double: " << sizeof(double) << " bytes\n";
    std::cout << "long double: " << sizeof(long double) << " bytes\n";

    std::cout << "\n========= CARACTERES E OUTROS =========\n";

    std::cout << "char: " << sizeof(char) << " byte\n";
    std::cout << "signed char: " << sizeof(signed char) << " byte\n";
    std::cout << "unsigned char: " << sizeof(unsigned char) << " byte\n";
    std::cout << "bool: " << sizeof(bool) << " byte\n";
    std::cout << "std::string: " << sizeof(std::string) << " bytes\n";
    std::cout << "std::size_t: " << sizeof(std::size_t) << " bytes\n";

    std::cout << "\n----------------------------------------------";
    std::cout << "\n========= LIMITES INTEIROS =========\n";
    std::cout << "----------------------------------------------\n";

    std::cout << "int: " << std::numeric_limits<int>::min() << " a " << std::numeric_limits<int>::max() << '\n';

    std::cout << "signed short: " << std::numeric_limits<signed short>::min() << " a " << std::numeric_limits<signed short>::max() << '\n';
    std::cout << "signed long long: " << std::numeric_limits<signed long long>::min() << " a " << std::numeric_limits<signed long long>::max() << '\n';

    std::cout << "unsigned: 0 a " << std::numeric_limits<unsigned>::max() << '\n';
    std::cout << "unsigned short: 0 a " << std::numeric_limits<unsigned short>::max() << '\n';

    std::cout << "unsigned long: 0 a " << std::numeric_limits<unsigned long>::max() << '\n';
    std::cout << "unsigned long long: 0 a " << std::numeric_limits<unsigned long long>::max() << '\n';

    std::cout << "long: " << std::numeric_limits<long>::min() << " a " << std::numeric_limits<long>::max() << '\n';
    std::cout << "long long: " << std::numeric_limits<long long>::min() << " a " << std::numeric_limits<long long>::max() << '\n';

    std::cout << "\n----------------------------------------------";
    std::cout << "\n========= LIMITES PONTOS FLUTUANTES =========\n";
    std::cout << "----------------------------------------------\n";

    std::cout << "float: " << std::numeric_limits<float>::lowest() << " a " << std::numeric_limits<float>::max() << '\n';

    std::cout << "double: " << std::numeric_limits<double>::lowest() << " a " << std::numeric_limits<double>::max() << '\n';

    std::cout << "long double: " << std::numeric_limits<long double>::lowest() << " a " << std::numeric_limits<long double>::max() << '\n';

    std::cout << "float (precisão decimal): " << std::numeric_limits<float>::digits10 << " dígitos\n";
    std::cout << "float_max_digits (precisão decimal): " << std::numeric_limits<float>::max_digits10 << " dígitos\n";

    std::cout << "double (precisão decimal): " << std::numeric_limits<double>::digits10 << " dígitos\n";
    std::cout << "double_max_digits (precisão decimal): " << std::numeric_limits<double>::max_digits10 << " dígitos\n";

    std::cout << "\n----------------------------------------------";
    std::cout << "\n========= LIMITES DE CARACTERES =========\n";
    std::cout << "----------------------------------------------\n";

    // std::cout << "Limite mínimo de CHAR: " << std::numeric_limits<char>::min() << '\n';
    // std::cout << "Limite máximo de CHAR: " << std::numeric_limits<char>::max() << '\n';
    std::cout << "CHAR_MAX : " << CHAR_MAX << " E CHAR_MIN : " << CHAR_MIN << '\n';

    // std::cout << "Limite mínimo de SIGNED CHAR: " << std::numeric_limits<signed char>::min() << '\n';
    // std::cout << "Limite máximo de SIGNED CHAR: " << std::numeric_limits<signed char>::max() << '\n';
    std::cout << "SIGNED CHAR_MAX : " << SCHAR_MAX << " E SIGNED CHAR_MIN : " << SCHAR_MIN << '\n';

    // std::cout << "Limite mínimo de UNSIGNED CHAR: " << std::numeric_limits<unsigned char>::min() << '\n';
    // std::cout << "Limite máximo de UNSIGNED CHAR: " << std::numeric_limits<unsigned char>::max() << '\n';
    std::cout << "UNSIGNED CHAR_MAX : " << UCHAR_MAX << '\n';

    std::cout << "\n----------------------------------------------";
    std::cout << "\n========= LIMITES DE BOOL =========\n";
    std::cout << "----------------------------------------------\n";

    std::cout << "bool: " << std::numeric_limits<bool>::min() << " a " << std::numeric_limits<bool>::max() << '\n';
    std::cout << "std::size_t: 0 a " << std::numeric_limits<std::size_t>::max() << '\n';
    return 0;
}

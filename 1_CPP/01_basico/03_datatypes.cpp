#include <iostream>
#include <string>  // Incluindo a biblioteca string, necessária para declarar std::string
#include <limits>  // Para acessar constantes definidas para tipos númericos em C++
#include <climits> // Para constantes relacionadas a valores inteiros (Relacionado ao limits.h de C)
#include <cfloat>  // Para constantes relacionadas a valores flutuantes (Relacionado ao float.h de C)

/**
 * DATATYPES: Este código demonstra os tamanhos em bytes e os limites de valores dos tipos de dados fundamentais em C++.
 *
 * Datatypes são categorias de dados que definem o tipo de valor que uma variável pode armazenar e as operaçõesconst
 * que podem ser realizadas sobre esses valores. Em C++, os tipos de dados são divididos em várias categorias,
 * incluindo tipos inteiros, tipos de ponto flutuante, caracteres e outros tipos como bool e std::string(em C++).
 *
 * C++ opera com os mesmo tipos de dados primitivos do C, mas também introduz tipos adicionais e classes como std::string
 * para manipulação de texto, dentre outros.
 *
 * @note Os tamanhos dos tipos (como int, long) podem variar dependendo da arquitetura
 * e do compilador, mas os limites são sempre consistentes para um dado tamanho (ex: int de 4 bytes).
 */

int main(int argc, char **argv)
{
    std::cout << "\n\t>> EXIBINDO TAMANHO DE BYTES DE CADA TIPO DE DADO <<\n";

    std::cout << "\n========= TIPOS INTEIROS =========\n";

    std::cout << "Tamanho de int: " << sizeof(int) << " em bytes\n";
    std::cout << "Tamanho de signed: " << sizeof(signed) << " em bytes\n";
    std::cout << "Tamanho de short: " << sizeof(short) << " em bytes\n";
    std::cout << "Tamanho de signed short: " << sizeof(signed short) << " em bytes\n";
    std::cout << "Tamanho de long: " << sizeof(long) << " em bytes\n";
    std::cout << "Tamanho de signed long: " << sizeof(signed long) << " em bytes\n";
    std::cout << "Tamanho de long long: " << sizeof(long long) << " em bytes\n";
    std::cout << "Tamanho de signed long long: " << sizeof(signed long long) << " em bytes\n";
    std::cout << "Tamanho de unsigned: " << sizeof(unsigned) << " em bytes\n";
    std::cout << "Tamanho de unsigned short: " << sizeof(unsigned short) << " em bytes\n";
    std::cout << "Tamanho de unsigned long: " << sizeof(unsigned long) << " em bytes\n";
    std::cout << "Tamanho de unsigned long long: " << sizeof(unsigned long long) << " em bytes\n";

    std::cout << "\n========= PONTO FLUTUANTE =========\n";

    std::cout << "Tamanho de float: " << sizeof(float) << " em bytes\n";
    std::cout << "Tamanho de double: " << sizeof(double) << " em bytes\n";
    std::cout << "Tamanho de long double: " << sizeof(long double) << " em bytes\n";

    std::cout << "\n========= CARACTERES E OUTROS =========\n";

    std::cout << "Tamanho de char: " << sizeof(char) << " em byte\n";
    std::cout << "Tamanho de signed char: " << sizeof(signed char) << " em byte\n";
    std::cout << "Tamanho de unsigned char: " << sizeof(unsigned char) << " em byte\n";
    std::cout << "Tamanho de bool: " << sizeof(bool) << " em byte\n";
    std::cout << "Tamanho de std::string: " << sizeof(std::string) << " em bytes (Tamanho da CLASSE/Estrutura, não do texto)\n";
    std::cout << "Tamanho de std::size_t: " << sizeof(std::size_t) << " em bytes (Geralmente unsigned long ou unsigned long long)\n";

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

    // Casting para (int) é necessário para imprimir o valor numérico em vez do caractere ASCII
    std::cout << "char (valor numérico): " << (int)std::numeric_limits<char>::min() << " a " << (int)std::numeric_limits<char>::max() << '\n';
    std::cout << "signed char: " << (int)std::numeric_limits<signed char>::min() << " a " << (int)std::numeric_limits<signed char>::max() << '\n';
    std::cout << "unsigned char: 0 a " << (int)std::numeric_limits<unsigned char>::max() << '\n';

    std::cout << "\n----------------------------------------------";
    std::cout << "\n========= LIMITES DE BOOL E STD::SIZE_T =========\n";
    std::cout << "----------------------------------------------\n";

    // std::boolalpha para exibir como true/false
    std::cout << "bool: " << std::boolalpha << std::numeric_limits<bool>::min() << " a " << std::numeric_limits<bool>::max() << std::noboolalpha << '\n';
    std::cout << "std::size_t: 0 a " << std::numeric_limits<std::size_t>::max() << '\n';

    return 0;
}

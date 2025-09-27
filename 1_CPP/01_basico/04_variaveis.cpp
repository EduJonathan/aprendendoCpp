#include <iostream>
#include <string>

/**
 * Em muitos aspectos, C++ mantém semelhanças com a linguagem C, especialmente nos:
 * - Tipos de dados básicos (int, float, char, etc.);
 * - Escopos de variáveis (global, local, em blocos, parâmetros);
 * - Modificadores de armazenamento: const, static, extern, auto, register, volatile.
 *
 * No entanto, C++ introduz novos recursos, como:
 * - constexpr: Avalia expressões em tempo de compilação.
 * - mutable: Permite modificar membros de uma classe mesmo quando o objeto é const.
 *
 * Algumas facilidades adicionadas em C++ incluem:
 * - std::string: Classe que facilita o uso de strings, evitando o uso de arrays de char (char[] ou char*).
 * - std::size_t: Tipo seguro e recomendado para representar tamanhos e índices, usado no lugar de size_t (C).
 * - Operador de inserção (<<) com std::cout: Elimina a necessidade de formatadores (%d, %f, etc.) usados com printf em C.
 *
 * VARIÁVEIS:
 * São nomes abstratos associados a áreas de memória usadas para armazenar dados de tipos específicos (int, float, char, etc.).
 * Representam valores que podem ser utilizados e manipulados ao longo da execução do programa.
 */

int main(int argc, char **argv)
{
    std::cout << "\tTIPOS INTEIROS" << "\n\n";

    // Declarando variáveis do tipo inteiro
    int numeroInteiroPositivo = 5;
    unsigned int numero = 40544u;
    signed int numeroInteiroNegativo = -5;
    long int numeroLongo = 78891246l;
    long long int numeroLongLong = 7889124647840ll;
    short int numeroCurto = 12;

    // Imprimindo os valores das variáveis do tipo inteiro
    std::cout << "numeroInteiroPositivo : " << numeroInteiroPositivo << '\n';
    std::cout << "numero : " << numero << '\n';
    std::cout << "numeroInteiroNegativo : " << numeroInteiroNegativo << '\n';
    std::cout << "numeroLongo : " << numeroLongo << '\n';
    std::cout << "numeroLongLong : " << numeroLongLong << '\n';
    std::cout << "numeroCurto : " << numeroCurto << '\n';

    std::cout << "\n==========================================\n";

    std::cout << "\tTIPOS REAIS" << "\n\n";

    // Declarando variáveis do tipo ponto flutuante
    float numeroReal = 3.1415f;           // prefixo 'F' ou 'f' para float
    double numeroRealLongo = 3.1415e5;    // 3.1415 * 10^5 = 314150
    long double numeroRealLong = 3.1415l; // prefixo 'L' ou 'l' para long double

    // Imprimindo os valores das variáveis de pontos flutuantes
    std::cout << "numeroReal : " << numeroReal << '\n';
    std::cout << "numeroRealLongo : " << numeroRealLongo << '\n';
    std::cout << "numeroRealLong : " << numeroRealLong << '\n';

    std::cout << "\n==========================================\n";

    std::cout << "\tTIPOS BOOLEANOS" << "\n\n";

    // Declarando variáveis e valores do tipo booleano, não necessita mais de <stdbool.h>
    bool verdadeiro = false;
    bool falso = true;

    // Imprimindo os valores das variáveis booleanos
    std::cout << "verdadeiro : " << verdadeiro << '\n';
    std::cout << "falso : " << falso << '\n';

    std::cout << "\n==========================================\n";

    std::cout << "\tTIPOS CARACTERES" << "\n\n";

    // Como sabemos tipos de caracteres podem ser representados por números
    // (decimais ou hexadecimais) vindo da tabela ASCII. Como dito C++ não
    // se diferencia de C. Onde ele utiliza a tabela ASCII para representar
    // caracteres também, seja `char` ou `std::string`.

    // Declarando variáveis do tipo caractere
    char letra = 'a';
    char caracterEspecial = 0x0A; // Representa em binário o caractere nova linha (newline) '\n'

    // Imprimindo os valores das variáveis do tipo caractere
    std::cout << "letra : " << letra << '\n';
    std::cout << "caracterEspecial :" << caracterEspecial << '\n';

    std::cout << "==========================================\n";

    std::cout << "\tTIPOS STRING" << "\n\n";

    // Declarando variáveis do tipo string
    unsigned char stringChar[] = "Programar em C++ é muito bom!";
    const char *string = "Programando em C++";
    std::string palavra = "Hello World";

    // Imprimindo os valores das variáveis strings
    std::cout << "stringChar : " << stringChar << '\n';
    std::cout << "string : " << string << '\n';
    std::cout << "palavra : " << palavra << '\n';
    return 0;
}

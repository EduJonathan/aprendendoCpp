#include <iostream>
#include <iomanip>

/**
 * Diferenças entre a inicialização de uma variável e a atribuição de um valor para ela.
 *
 * int var = 4; // Inicialização por cópia
 * int var{4}; // Inicialização Uniforme ou chaves (Uniform Initialization or Brace Initialization)
 */

int main(int argc, char **argv)
{
    std::cout << "----------------------------------";
    std::cout << "\n\t>>INICIALIZAÇÃO TRADICIONAL<<\n";
    std::cout << "----------------------------------\n";

    int variavel = 4;
    /**
     * Inicialização por cópia (C++98).
     * Usa o operador '=' para copiar o valor para a variável.
     * Pode levar a conversões implícitas inesperadas.
     */

    float real = 3.14f; // Inicializa 'real' com o valor 3.14

    // Exemplo de narrowing conversion com inicialização tradicional
    int converter = real; // 'real' (float) será convertido para 'converter' (int), valor se torna 3

    std::cout << "variavel: " << variavel << '\n';                               // Exibe 4
    std::cout << "real: " << std::fixed << std::setprecision(2) << real << '\n'; // Exibe 3.14
    std::cout << "converter: " << converter << '\n';                             // Exibe 3 (valor convertido de b)

    std::cout << "\n----------------------------------";
    std::cout << "\n\t>>INICIALIZAÇÃO UNIFORME<<\n";
    std::cout << "----------------------------------\n";

    int a{4}; // Inicializa 'a' com o valor 4
    /**
     * Inicialização uniforme (C++11).
     * Impede conversões implícitas que possam causar perda de dados (narrowing conversions).
     * Exemplo: int x{5.7}; // Erro: conversão de 'double' para 'int' com perda de dados.
     */

    float b{5.7}; // Inicializa 'b' com o valor 5.7

    // A tentativa de conversão implícita gerará erro:
    // int c{b}; // Erro: conversão implícita de 'float' para 'int' não permitida com chaves

    // Tentar fazer uma conversão com perda de dados também gera erro:
    // int d{5.7}; // Erro: conversão de tipo com perda de dados (narrowing conversion)

    std::cout << "a : " << a << '\n';                                       // Exibe 4
    std::cout << "b : " << std::fixed << std::setprecision(2) << b << '\n'; // Exibe 5.7

    /**
     * BOAS PRÁTICAS:
     * - Prefira a inicialização uniforme ({}) para evitar conversões implícitas e
     * narrowing conversions(narrowing conversions ou perda de dados).
     *
     * - Use a inicialização por cópia (=) apenas quando necessário para compatibilidade
     * ou legibilidade.
     *
     * +--------------------------------------------------------------------------------+
     * | Forma                         | Aceita Narrowing | Segurança  | Introduzida em |
     * +--------------------------------------------------------------------------------+
     * | int x = 1.0;                  | Sim              | Baixa      | C++98          |
     * +--------------------------------------------------------------------------------+
     * | int x{1.0};                   | Não              | Alta       | C++11          |
     * +--------------------------------------------------------------------------------+
     * | int x(static_cast<int>(1.0)); | Sim (explícita)  | Média-Alta | C++98          |
     * +--------------------------------------------------------------------------------+
     */

    std::cout << "\n----------------------------------------";
    std::cout << "\n>> EXEMPLO DE NARROWING CONVERSION <<\n";
    std::cout << "----------------------------------------\n";

    float pi = 3.14f;
    double e = 2.71828;

    int copia_pi = pi; // OK: inicialização por cópia (conversão implícita permitida)
    int direta_pi(pi); // OK: inicialização direta

    // Inicialização uniforme — TENTATIVAS INVÁLIDAS
    // int c{pi};       // Erro: narrowing conversion
    // int d{e};        // Erro: narrowing conversion
    // char letra{300}; // Erro: narrowing

    std::cout << "copia_pi (de float pi) : " << copia_pi << '\n';
    std::cout << "direta_pi (de float pi) : " << direta_pi << '\n';

    // Correto: conversão explícita com static_cast
    int cast_pi{static_cast<int>(pi)};
    int cast_e{static_cast<int>(e)};

    std::cout << "cast_pi (cast de pi) : " << cast_pi << '\n';
    std::cout << "cast_e (cast de e) : " << cast_e << '\n';

    /**
     * Compile e execute com
     * > g++ -std=c++11 -Wall -Wextra -pedantic nome_arquivo.cpp -o programa
     * .\programa.exe
     */
    return 0;
}

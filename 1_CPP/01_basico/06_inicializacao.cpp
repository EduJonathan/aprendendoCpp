#include <iostream>
#include <iomanip>

/**
 * Diferenças entre as formas de inicialização de variáveis em C++.
 *
 * 1. Inicialização por Cópia: int var = 4; (C++98)
 * 2. Inicialização Direta: int var(4); (C++98)
 * 3. Inicialização Uniforme (Brace/Chaves): int var{4}; (C++11)
 */

int main(int argc, char **argv)
{
    // Usando setw para um alinhamento mais limpo
    std::cout << "==================================\n";
    std::cout << ">> INICIALIZAÇÃO TRADICIONAL (C++98) <<\n";
    std::cout << "==================================\n";

    /**
     * Inicialização por cópia (C++98). Usa o operador '='.
     * Permite conversões implícitas, inclusive narrowing conversions.
     */
    int variavel_copia = 4;

    /**
     * Inicialização direta (C++98). Usa parênteses '()'.
     * Também permite conversões implícitas, inclusive narrowing conversions.
     */
    int variavel_direta(5);
    float real = 3.14f;

    // Exemplo de narrowing conversion com inicialização tradicional
    // O valor 'real' (3.14) é convertido para 'converter_copia' (int), valor se torna 3.
    int converter_copia = real;

    std::cout << std::left << std::setw(20) << "variavel_copia (=): " << variavel_copia << '\n';
    std::cout << std::left << std::setw(20) << "variavel_direta (()): " << variavel_direta << '\n';
    std::cout << std::left << std::setw(20) << "real (float): " << std::fixed << std::setprecision(2) << real << '\n';

    // Exibe 3 (narrowing permitido)
    std::cout << std::left << std::setw(20) << "converter_copia: " << converter_copia << '\n';

    std::cout << "\n==================================\n";
    std::cout << ">> INICIALIZAÇÃO UNIFORME (C++11) <<\n";
    std::cout << "==================================\n";

    /**
     * Inicialização uniforme (C++11). Usa chaves '{}'.
     * IMPEDE conversões implícitas que possam causar perda de dados (narrowing conversions).
     */
    int a{4};
    float b{5.7f}; // Inicializa 'b' com o valor 5.7 (melhor usar f para float)

    std::cout << std::left << std::setw(20) << "a (int):" << a << '\n';
    std::cout << std::left << std::setw(20) << "b (float):" << std::fixed << std::setprecision(2) << b << '\n';

    // A tentativa de narrowing conversion com chaves resultaria em ERRO DE COMPILAÇÃO:
    /* int c{b}; */        // ERRO: Conversão implícita de 'float' para 'int' não permitida
    /* int d{5.7}; */      // ERRO: Narrowing conversion de 'double' para 'int'
    /* char letra{300}; */ // ERRO: 300 excede o limite de um 'char'

    std::cout << "\n========================================\n";
    std::cout << ">> SOLUÇÃO PARA NARROWING CONVERSION <<\n";
    std::cout << "========================================\n";

    double e = 2.71828;

    // Para usar a Inicialização Uniforme com um tipo que requer narrowing,
    // é necessário realizar a conversão explicitamente (ex: static_cast).
    int cast_b{static_cast<int>(b)}; // Conversão explícita de float para int
    int cast_e{static_cast<int>(e)}; // Conversão explícita de double para int

    std::cout << std::left << std::setw(20) << "cast_b (de float):" << cast_b << '\n';  // Exibe 5
    std::cout << std::left << std::setw(20) << "cast_e (de double):" << cast_e << '\n'; // Exibe 2

    /*
     * BOAS PRÁTICAS:
     * - Prefira a Inicialização Uniforme ({}) para maior segurança, pois ela previne
     * narrowing conversions (perda de dados) em tempo de compilação.
     *
     * - Use 'static_cast' para conversões que podem gerar narrowing, tornando
     * a intenção de perda de dados explícita.
     *
     * Tabela Resumo das Formas de Inicialização
     * +---------------------------------------------------------------------------------------+
     * | Forma                  | Exemplo           | Aceita Narrowing | Segurança  | Versão   |
     * +---------------------------------------------------------------------------------------+
     * | Cópia (=)              | int x = 1.0;      | Sim              | Baixa      | C++98    |
     * +---------------------------------------------------------------------------------------+
     * | Direta (())            | int x(1.0);       | Sim              | Baixa      | C++98    |
     * +---------------------------------------------------------------------------------------+
     * | Uniforme ({})          | int x{1.0};       | NÃO (Erro)       | Alta       | C++11    |
     * +---------------------------------------------------------------------------------------+
     * | Explícita (Cast)       | int x{static_...  | Sim (Explícita)  | Média-Alta | C++98/11 |
     * +---------------------------------------------------------------------------------------+
     */
    return 0;
}

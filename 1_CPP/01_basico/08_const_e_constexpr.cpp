#include <iostream>
#include <array>
#include <cstdlib>

// Constantes definidas com diferentes abordagens
const int STANDARD_SIZE = 20;         // Constante tradicional
constexpr int MAX_BUFFER_SIZE = 1024; // Constante em tempo de compilação

// Funções constantes
const double calculateCircleArea(double radius)
{
    return 3.14159 * radius * radius;
}

// Função constexpr (calculável em tempo de compilação)
constexpr int factorial(int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

// Variável const inicializada com função const
const double unitCircleArea = calculateCircleArea(1.0);

// Variável constexpr inicializada com função constexpr
constexpr int fact5 = factorial(5);

/// ERROR: não pode ser constexpr porque calculateCircleArea não é constexpr
// constexpr double anotherArea = calculateCircleArea(2.0);

int main(int argc, char **argv)
{
    // Demonstração de const (tempo de execução)
    std::cout << "=== USO DE CONST (TEMPO DE EXECUÇÃO) ===\n";

    const int dynamicValue = std::rand() % 100; // Só conhecido em runtime
    const double area = calculateCircleArea(dynamicValue);

    std::cout << "Raio aleatorio: " << dynamicValue << '\n';
    std::cout << "Area calculada: " << area << '\n';
    std::cout << "Area do circulo unitario: " << unitCircleArea << "\n\n";

    std::cout << "-----------------------------------------------------\n";

    // Demonstração de constexpr (tempo de compilação)
    std::cout << "=== USO DE CONSTEXPR (TEMPO DE COMPILACAO) ===\n";

    constexpr int compileTimeValue = 7; // Conhecido em compile-time
    constexpr int fact7 = factorial(compileTimeValue);

    std::cout << "Fatorial de 5 (pre-calculado): " << fact5 << '\n';
    std::cout << "Fatorial de 7: " << fact7 << '\n';

    // Array de tamanho fixo usando constexpr
    std::array<int, MAX_BUFFER_SIZE> buffer;
    std::cout << "Tamanho do buffer: " << buffer.size() << "\n\n";

    /// ERRO: std::rand() só pode ser avaliado em **TEMPO DE EXECUÇÃO**.
    // constexpr int valorAleatorio = std::rand(); // ERRO de compilação
    // std::cout << "Valor aleatório constexpr: " << valorAleatorio << '\n';

    /**
     * +--------------------------------+---------------------------+------------------------------+
     * | Característica                 | const                     | constexpr                    |
     * +--------------------------------+---------------------------+------------------------------+
     * | Avaliação                      | Tempo de execução         | Tempo de compilação          |
     * | Pode chamar qualquer função    | Sim                       | Não (só constexpr)           |
     * | Pode depender de entrada extra | Sim                       | Não                          |
     * | Exemplo válido                 | const int x = rand();     | constexpr int y = 2 + 3;     |
     * | Usado para std::array          | Não (exceto global const) | Sim (exigido por std::array) |
     * +--------------------------------+---------------------------+------------------------------+
     */

    /**
     * RESSALTANDO:
     * => TEMPO DE EXECUÇÃO: É o processo de execução do programa,
     * onde as variáveis, funções são avaliadas ENQUANTO o programa roda.
     *
     * => TEMPO DE COMPILAÇÃO: É o processo de compilação do código,
     * onde as constantes são avaliadas ANTES do programa rodar.
     *
     * DICA: Quando estiver pensando em usar o constexpr, pense assim:
     * "Isso poderia ser resolvido completamente antes do programa começar a rodar?"
     *
     * @note Veremos depois que este é um dos conceitos mais importantes e praticamente
     * um dos maiores trunfos em C++ moderno, especialmente em templates e metaprogramação.
     */
    return 0;
}

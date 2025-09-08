#include <iostream>
#include <map>
#include <utility>

/**
 * std::make_pair<>: Estrutura que armazena dois elementos, geralmente de tipos diferentes.
 * Essa função é útil para inicializar pares de valores sem precisar especificar explicitamente
 * os tipos, deduz automaticamente os tipos dos valores fornecidos, mesmo em situações em que
 * os tipos não são óbvios(funcionando com quase todos os tipos de dados, incluindo ponteiros,
 * objetos de classes personalizadas, referências, etc).
 */

/**
 * @brief Algoritmo de Euclides Estendido para encontrar o GCD e os coeficientes de Bézout.
 *
 * Este algoritmo retorna o maior divisor comum (GCD) de dois números `a` e `b`
 * e os coeficientes `x` e `y` que satisfazem a equação: `a * x + b * y = gcd(a, b)`.
 *
 * @param a Primeiro número.
 * @param b Segundo número.
 * @return Um par onde o primeiro valor é o GCD de `a` e `b`, e o segundo valor é um par
 *         contendo os coeficientes `x` e `y` que satisfazem a equação de Bézout.
 */
std::pair<int, std::pair<int, int>> extendedEuclid(int a, int b)
{
    int x_current = 1, y_current = 0;   // Coeficientes atuais de `a`
    int x_previous = 0, y_previous = 1; // Coeficientes anteriores de `b`

    int quotient = 0,  // Quociente da divisão
        remainder = 0, // Resto da divisão
        temp_x = 0,    // Variável temporária para x
        temp_y = 0;    // Variável temporária para y

    while (a != 0)
    {
        quotient = b / a;  // Cálculo da quociente da divisão
        remainder = b % a; // Resto da divisão

        // Atualização dos coeficientes
        temp_x = x_previous - quotient * x_current;
        temp_y = y_previous - quotient * y_current;

        x_previous = x_current;
        y_previous = y_current;
        x_current = temp_x;
        y_current = temp_y;

        b = a;
        a = remainder;
    }

    // Retorna o GCD e os coeficientes `x_previous` e `y_previous`
    return std::make_pair(b, std::make_pair(x_previous, y_previous));
}

/**
 * @brief Calcula o inverso modular de `a` módulo `m`.
 *
 * O inverso modular de `a` é o número `x` tal que `a * x ≡ 1 (mod m)`. Esse valor pode ser
 * encontrado utilizando o Algoritmo de Euclides Estendido.
 *
 * @param a Número para o qual se deseja encontrar o inverso modular.
 * @param m Modulo para o qual o inverso será calculado.
 * @return O inverso modular de `a` módulo `m`.
 */
int modularInverse(int a, int m)
{
    // Usando o Algoritmo de Euclides Estendido para obter o coeficiente x (inverso modular)
    int x = extendedEuclid(a, m).second.first;

    // Garantir que o resultado seja positivo
    return (x + m) % m;
}

int main(int argc, char **argv)
{
    std::map<int, std::string> myMap;

    // Insere pares no mapa usando std::make_pair
    myMap.insert(std::make_pair(1, "Um"));
    myMap.insert(std::make_pair(2, "Dois"));

    // Itera sobre o mapa e exibe os pares
    for (const auto &entry : myMap)
    {
        std::cout << entry.first << ": " << entry.second << '\n';
    }

    std::cout << "==========================================" << '\n';

    int a = 3, m = 11;

    // Exemplo do uso do std::make_pair no retorno da função
    std::pair<int, std::pair<int, int>> result = extendedEuclid(a, m);

    // Exibindo o GCD e os coeficientes
    std::cout << "GCD: " << result.first << '\n';
    std::cout << "Coeficientes: x = " << result.second.first
              << ", y = " << result.second.second << '\n';

    // Exibindo o inverso modular
    int inv = modularInverse(a, m);
    std::cout << "O inverso modular de " << a << " módulo " << m << " é: " << inv << '\n';

    return 0;
}

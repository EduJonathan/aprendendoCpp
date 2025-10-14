#include <iostream>
#include <cmath>
#include <limits>

// Implementações de funções úteis em C++ para verificação de valores especiais em ponto flutuante,
// como NaN (Not a Number) e infinitos positivos/negativos.
// Utilizamos funções da biblioteca <cmath>, como std::isnan, std::isinf, std::isgreater e std::isunordered,
// que permitem realizar comparações seguras e detectar condições numéricas anormais durante cálculos,
// evitando comportamentos indefinidos ou resultados incorretos.

struct valores_flutuantes
{
    float valor_float;
    double valor_double;
    long double valor_long_double;
};

valores_flutuantes get_value_floating(valores_flutuantes &valores)
{
    if (std::isnan(valores.valor_float))
        std::cout << "valor_float é NaN\n";
    if (std::isnan(valores.valor_double))
        std::cout << "valor_double é NaN\n";
    if (std::isnan(valores.valor_long_double))
        std::cout << "valor_long_double é NaN\n";

    return valores;
}

void comparar_valores(const valores_flutuantes &valores)
{
    float comparador = 1.0f;
    std::cout << "\nComparações com std::isgreater:\n";

    if (std::isgreater(valores.valor_float, comparador))
        std::cout << "valor_float > " << comparador << '\n';
    else
        std::cout << "valor_float NÃO é > " << comparador << '\n';

    if (std::isgreater(valores.valor_double, comparador))
        std::cout << "valor_double > " << comparador << '\n';
    else
        std::cout << "valor_double NÃO é > " << comparador << '\n';

    if (std::isgreater((double)valores.valor_long_double, comparador))
        std::cout << "valor_long_double > " << comparador << '\n';
    else
        std::cout << "valor_long_double NÃO é > " << comparador << '\n';
}

void verificar_desordenados(const valores_flutuantes &valores)
{
    float comparador = 1.0f;
    std::cout << "\nVerificando com std::isunordered:\n";

    if (std::isunordered(valores.valor_float, comparador))
        std::cout << "valor_float está desordenado (possivelmente NaN)\n";
    else
        std::cout << "valor_float pode ser ordenadamente comparado com " << comparador << '\n';

    if (std::isunordered(valores.valor_double, comparador))
        std::cout << "valor_double está desordenado\n";
    else
        std::cout << "valor_double pode ser ordenadamente comparado com " << comparador << '\n';

    if (std::isunordered((double)valores.valor_long_double, comparador))
        std::cout << "valor_long_double está desordenado\n";
    else
        std::cout << "valor_long_double pode ser ordenadamente comparado com " << comparador << '\n';
}

void verificar_infinitos(const valores_flutuantes &valores)
{
    std::cout << "\nVerificando com std::isinf:\n";

    if (std::isinf(valores.valor_float))
        std::cout << "valor_float é infinito (" << (valores.valor_float > 0 ? "+inf" : "-inf") << ")\n";
    else
        std::cout << "valor_float não é infinito\n";

    if (std::isinf(valores.valor_double))
        std::cout << "valor_double é infinito (" << (valores.valor_double > 0 ? "+inf" : "-inf") << ")\n";
    else
        std::cout << "valor_double não é infinito\n";

    if (std::isinf(valores.valor_long_double))
        std::cout << "valor_long_double é infinito (" << (valores.valor_long_double > 0 ? "+inf" : "-inf") << ")\n";
    else
        std::cout << "valor_long_double não é infinito\n";
}

int main(int argc, char **argv)
{
    std::cout << "nan() (double): " << std::nan("") << '\n';
    std::cout << "nanf() (float): " << std::nanf("") << '\n';
    std::cout << "nanl() (long double): " << std::nanl("") << '\n';

    double nan_value = std::nan("");
    if (std::isnan(nan_value))
    {
        std::cout << "nan_value é NaN!\n";
    }

    // Valores NaN
    valores_flutuantes valores_nan{
        std::nanf(""),
        std::nan(""),
        std::nanl("")};

    std::cout << "\n--- Testando valores NaN ---\n";
    get_value_floating(valores_nan);
    comparar_valores(valores_nan);
    verificar_desordenados(valores_nan);
    verificar_infinitos(valores_nan);

    // Valores infinitos
    valores_flutuantes valores_inf{
        std::numeric_limits<float>::infinity(),
        -std::numeric_limits<double>::infinity(),
        std::numeric_limits<long double>::infinity()};

    std::cout << "\n--- Testando valores Infinitos ---\n";
    get_value_floating(valores_inf); // Não imprime nada porque não são NaN
    comparar_valores(valores_inf);
    verificar_desordenados(valores_inf);
    verificar_infinitos(valores_inf);

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> // std::unary_function está aqui (pré-C++17)

/**
 * std::unary_function:
 * -------------------
 *
 * Apesar de estar obsoleto a partir do C++11 e removido no C++17,
 * `std::unary_function` era uma classe base fornecida na biblioteca
 * padrão do C++ para facilitar a criação de functors unários (funções
 * que aceitam um único argumento).
 *
 * Além do mais esta classe e outras similares, como
 * std::unary_function -> Só fornecia typedefs
 * std::binary_function -> Só fornecia typedefs
 * std::bind1st / std::bind2nd -> Muito verbosos e propensos a erros (Substituídos por std::bind e expressões lambda)
 * std::ptr_fun -> Necessário para ponteiros de função antigos
 * std::mem_fun / std::mem_fun_ref -> Adaptadores para funções-membro (depreciados em favor de std::mem_fn ou expressões lambda)
 * std::random_shuffle -> Utilizava rand() internamente
 * std::auto_ptr -> Semântica problemática de cópia implicita
 *
 * @note Existe várias outras funcionalidades obsoletas na STL.
 */

std::function<int(int)> exemploUnaryFunction; // Exemplo de uso moderno com std::functional

// ----------------------------------------
// Functor que herda (obtém) os atributos de std::unary_function
// ----------------------------------------
struct Quadrado : std::unary_function<int, int>
{
    // std::unary_function<int, int> fornece:
    //   typedef int argument_type;
    //   typedef int result_type;

    result_type operator()(const argument_type &x) const
    {
        return x * x;
    }
};

// Functor que verifica se um número é par
struct EhPar : std::unary_function<int, bool>
{
    bool operator()(const int &x) const
    {
        return x % 2 == 0;
    }
};

int main(int argc, char **argv)
{
    // Exemplo de uso moderno com std::functional, Functor que calcula o quadrado
    exemploUnaryFunction = [](int x)
    {
        return x * x;
    };

    int valor = 5;
    std::cout << "O quadrado de " << valor << " é " << exemploUnaryFunction(valor) << '\n';

    std::cout << "----------------------------------------\n";

    std::vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Números originais: ";
    for (int n : numeros)
        std::cout << n << ' ';
    std::cout << '\n';

    // Usando o functor Quadrado com std::transform
    std::vector<int> quadrados(numeros.size());
    std::transform(numeros.begin(), numeros.end(), quadrados.begin(), Quadrado()); // instancia o functor

    std::cout << "Quadrados: ";
    for (int q : quadrados)
        std::cout << q << ' ';
    std::cout << '\n';

    // Usando EhPar com std::count_if
    int pares = std::count_if(numeros.begin(), numeros.end(), EhPar());

    std::cout << "----------------------------------------\n";

    std::cout << "Quantidade de números pares: " << pares << '\n';

    // Exemplo de uso dos typedefs (útil em templates antigos)
    Quadrado q;
    Quadrado::argument_type value = 7;
    Quadrado::result_type resultado = q(value);

    std::cout << "Quadrado de " << value << " = " << resultado << '\n';

    return 0;
}

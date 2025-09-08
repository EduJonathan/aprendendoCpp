#include <iostream>
#include <vector>

/**
 * Templates em C++ são uma ferramenta poderosa para criar código genérico que funciona
 * com diferentes tipos de dados ou valores em tempo de compilação, evitando duplicação
 * de código e aumentando a reutilização.
 *
 * Os argumentos em templates podem ser **variados** e incluem:
 *
 * 1. Tipos (typename/class):
 *
 * - Permitem criar código genérico que funciona com diferentes tipos de dados.
 * - `typename` e `class` são intercambiáveis, mas `typename` é mais genérico e preferido em contextos modernos.
 * - T (ou qualquer nomenclatura) pode ser int, float, double, std::string, ou até uma classe personalizada.
 *
 * --------------
 *
 * 2. Argumentos não-tipo (non-type):
 *
 * - São valores constantes conhecidos em tempo de compilação (ex.: inteiros, enums, ponteiros, referências, ou `auto` em C++17+).
 * - Útil para fixar valores como tamanhos de arrays ou constantes em tempo de compilação.
 * - Restrição: Apenas tipos integrais, enums, ponteiros, referências ou `auto` são permitidos.
 *
 * --------------
 *
 * 3. Templates de template:
 *
 * - Permitem passar outro template como parâmetro, como std::vector ou std::list.
 * - Útil para generalizar a estrutura de dados usada (vector, list, map...).
 *
 * --------------
 *
 * 4. Ponteiros e referências:
 *
 * - Um template pode receber ponteiros ou referências para funções, membros estáticos ou membros de classes.
 * - Muito usado em programação genérica e metaprogramação.
 *
 * --------------
 *
 * 5. `auto` como argumento (C++17 ou posterior):
 *
 * - Permite deduzir automaticamente o tipo de um valor constante em tempo de compilação.
 * - Útil para generalizar constantes sem especificar o tipo exato.
 *
 * --------------
 *
 * RESUMINDO:
 * - Use `typename`/`class` para generalizar **tipos**.
 * - Use argumentos não-tipo (int, char, enum, ponteiro, auto) para fixar **valores constantes**.
 * - Use templates de template para generalizar **containers ou estruturas**.
 * - Use ponteiros/referências para passar **funções ou membros estáticos**.
 * - Templates são fundamentais em metaprogramação, permitindo cálculos e lógica em tempo de compilação.
 *
 * CUIDADOS:
 * - Templates só são verificados quando instanciados, o que pode gerar erros complexos.
 * - Use conceitos (C++20) ou `static_assert` para impor restrições aos tipos ou valores.
 * - Templates podem aumentar o tamanho do binário devido à geração de código para cada tipo.
 */

template <typename T>
T maior(T a, T b) { return (a > b) ? a : b; }

template <typename T, int N>
struct Array
{
    T dados[N];

    void print()
    {
        for (int i = 0; i < N; ++i)
            std::cout << dados[i] << ' ';
        std::cout << '\n';
    }
};

template <template <typename, typename> class Container, typename T>
struct Wrapper
{
    Container<T, std::allocator<T>> dados;

    void add(T x) { dados.push_back(x); }

    void print()
    {
        for (const auto &x : dados)
            std::cout << x << " ";
        std::cout << '\n';
    }
};

struct Example
{
    static void sayHello() { std::cout << "Hello!\n"; }
};

template <void (*Func)()>
struct Call
{
    void operator()() { Func(); }
};

template <auto N>
struct Const
{
    static constexpr auto valor = N;
    void print() { std::cout << valor << '\n'; }
};

// T = tipo, N = valor constante, Container = template
template <typename T, int N, template <typename...> class Container>
struct Estrutura
{
    Container<T> dados;

    void print()
    {
        std::cout << "Capacidade fixa = " << N << '\n';
    }
};

int main(int argc, char **argv)
{
    std::cout << maior(5, 10) << '\n';                              // T = int
    std::cout << maior(3.14, 2.71) << '\n';                         // T = double
    std::cout << maior(std::string("A"), std::string("B")) << '\n'; // T = std::string

    std::cout << "-----------------------------" << '\n';

    Array<int, 3> arr = {{1, 2, 3}};
    arr.print();

    std::cout << "-----------------------------" << '\n';

    Wrapper<std::vector, int> w;
    w.add(42);
    w.add(100);
    w.print();

    std::cout << "-----------------------------" << '\n';

    Call<Example::sayHello> c;
    c();

    std::cout << "-----------------------------" << '\n';

    Const<42> c1;  // N = int
    Const<'A'> c2; // N = char
    c1.print();
    c2.print();

    std::cout << "-----------------------------" << '\n';

    Estrutura<int, 5, std::vector> e;
    e.print(); // Capacidade fixa = 5
    return 0;
}

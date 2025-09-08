#include <iostream>
#include <vector>
#include <utility>

/**
 * Tanto o 'using' quanto o 'typedef' em C++ é usado para criar **aliases de tipo**,
 * ou seja, "apelidos" para tipos, tornando o código mais legível e fácil de manter,
 * especialmente com tipos complexos como os gerados por templates. Ele também pode
 * ser usado para simplificar acesso a namespaces.
 *
 * **Por que usar?**
 * - Simplifica tipos longos e complexos, como os de templates (ex.: std::vector<std::pair<int, double>>).
 * - Melhora a legibilidade e reduz erros de digitação.
 * - Útil em templates para criar aliases dependentes ou para generalizar tipos.
 *
 * **Exemplo com Templates**:
 * - Sem o 'using': Você precisa escrever o tipo completo (ex.: std::vector<int>) repetidamente.
 * - Com o 'using': Você cria um alias mais curto, como 'VetorInteiros', e usa esse nome.
 *
 * **USING VS TYPEDEF**:
 *
 * - **typedef**: Usado em C e C++ para criar aliases simples. Limita-se a tipos fixos e não suporta templates diretamente.
 *   - Sintaxe: `typedef tipo alias;`
 *   - Exemplo: `typedef int* PtrInt;`
 *
 * - **using**: Introduzido no C++11, é mais flexível e legível, especialmente para templates.
 *   - Sintaxe: `using alias = tipo;`
 *   - Suporta aliases de templates (template aliases), que o `typedef` não permite.
 *   - Exemplo: `template<typename T> using Vetor = std::vector<T>;`
 *
 * **Vantagens do 'using' sobre 'typedef'**:
 * - Mais legível (parece uma atribuição: `alias = tipo`).
 * - Suporta templates de tipo (ex.: alias para `std::vector<T>`).
 * - Pode ser usado em contextos dependentes (ex.: dentro de classes com templates).
 *
 * Quando Usar using
 *
 * Com templates: Simplificar tipos complexos, como std::vector<std::pair<int, double>>.
 * Em classes templates: Criar aliases dependentes para tipos internos (ex.: using TipoDado = T;).
 * Para legibilidade: Dar nomes semânticos a tipos (ex.: using Idade = int;).
 * Em metaprogramação: Combinar com templates para criar abstrações genéricas.
 *
 * Cuidados
 * - Escopo: Aliases criados com using têm o escopo onde são definidos (ex.: global, dentro de uma classe).
 * - Conflitos: Evite nomes de aliases que colidam com outros identificadores.
 * - Compatibilidade: using é C++11+, então não é compatível com compiladores mais antigos.
 */

// Exemplo 1: Alias para tipo simples
using Numero = int;

// Exemplo 2: Alias para tipo complexo (template)
template <typename T>
using Vetor = std::vector<T>; // Alias para std::vector<T>

// Exemplo 3: Alias para template dentro de uma classe
template <typename T>
struct Container
{
    using TipoDado = T;                          // Alias dependente para o tipo T
    T valor;                                     // Membro do tipo T
    Container(T v) : valor(v) {}                 // Construtor
    void print() { std::cout << valor << '\n'; } // Método para imprimir o valor
};

// Exemplo 4: Comparação com typedef
typedef std::vector<int> VetorInteiros;  // Funciona, mas não é genérico
using VetorInteiros2 = std::vector<int>; // Equivalente, mais legível

// Exemplo 5: Alias para template genérico
template <typename T>
using Par = std::pair<T, T>; // Alias para std::pair<T, T>

// Válido com using
// template <typename T>
// using Vetor = std::vector<T>;

// Inválido com typedef
// typedef std::vector<T> Vetor; // Erro: T não está definido

int main(int argc, char **argv)
{
    // Usando alias simples
    Numero x = 42;
    std::cout << "Numero: " << x << '\n';

    // Usando alias para template
    Vetor<int> v = {1, 2, 3};
    for (const auto &item : v)
        std::cout << item << ' ';
    std::cout << '\n';

    // Usando alias dependente
    Container<double> c(3.14);
    c.print();

    // Usando alias para par
    Par<int> p = {10, 20};
    std::cout << "Par: (" << p.first << ", " << p.second << ")\n";

    // Usando alias com typedef e using
    VetorInteiros v1 = {4, 5, 6};
    VetorInteiros2 v2 = {7, 8, 9};

    std::cout << "VetorInteiros: ";

    for (const auto &item : v1)
        std::cout << item << ' ';

    std::cout << "\nVetorInteiros2: ";
    for (const auto &item : v2)
        std::cout << item << ' ';
    std::cout << '\n';

    return 0;
}

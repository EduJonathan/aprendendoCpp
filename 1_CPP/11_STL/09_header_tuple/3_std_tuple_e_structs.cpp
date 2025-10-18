#include <iostream>
#include <string>
#include <tuple>

/**
 * Em C++, std::tuple e struct são usadas para agrupar dados, mas possuem diferenças
 * fundamentais em termos de propósito, uso e características.
 *
 * --------------------------
 *
 * 1. Definição e Propósito
 *
 * TUPLE:
 * - É uma classe de modelo (template) fornecida pela biblioteca padrão C++ (em <tuple>).
 * - Projetada para armazenar uma coleção de valores heterogêneos (de tipos diferentes) em uma única estrutura.
 * - É uma solução genérica e flexível, usada quando você precisa de uma estrutura temporária ou
 * não quer definir uma struct específica.
 * - Exemplo: std::tuple<int, std::string, double> pode armazenar um inteiro, uma string e um double.
 *
 * STRUCT:
 * - É uma construção da linguagem para definir um tipo de dados composto personalizado.
 * - Permite agrupar dados (geralmente relacionados) com nomes de membros significativos, facilitando a legibilidade e manutenção.
 * - Usada quando você quer criar um tipo com semântica clara e reutilizável.
 * - Exemplo: struct Pessoa { int idade; std::string nome; double altura; };.
 *
 * --------------------------
 *
 * DESEMPENHO:
 *
 * TUPLE:
 * - Pode ter uma pequena sobrecarga devido à sua natureza genérica (template) e alocação de memória para tipos heterogêneos.
 * - Geralmente otimizado pelo compilador, mas pode ser menos eficiente em casos complexos.
 *
 * STRUCT:
 * - Geralmente mais eficiente, pois é uma estrutura de dados simples e direta, com layout de memória previsível.
 * - Ideal quando o desempenho é crítico.
 *
 * --------------------------
 *
 * USO:
 *
 * TUPLE:
 * - Quando você precisa de uma solução genérica e temporária para agrupar dados.
 * - Para funções que retornam múltiplos valores de tipos diferentes (e.g., return std::make_tuple(a, b, c);).
 * - Em metaprogramação ou contextos onde a flexibilidade de templates é necessária.
 *
 * STRUCT:
 *
 * - Quando você precisa de um tipo com semântica clara e nomes de membros significativos.
 * - Para modelar entidades do domínio do problema (e.g., struct Cliente, struct Ponto3D).
 * - Quando você planeja adicionar métodos ou lógica associada ao tipo.
 */

// Usando tuple
std::tuple<int, std::string, double> getPessoaTuple()
{
    return std::make_tuple(42, "Alice", 1.75);
}

// Usando struct
struct Pessoa
{
    int idade;
    std::string nome;
    double altura;
};

Pessoa getPessoaStruct()
{
    return {42, "Alice", 1.75};
}

int main(int argc, char **argv)
{
    // Tuple
    auto t = getPessoaTuple();
    std::cout << "Tuple: " << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << '\n';

    // Struct
    Pessoa p = getPessoaStruct();
    std::cout << "Struct: " << p.idade << ", " << p.nome << ", " << p.altura << '\n';

    return 0;
}

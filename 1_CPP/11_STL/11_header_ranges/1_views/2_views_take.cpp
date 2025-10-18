#include <iostream>
#include <ranges>

/**
 * std::views::take(): É um *range adaptor* que cria uma visualização dos primeiros 'n' elementos
 * de um range. Se o range tiver menos que 'n' elementos, todos os elementos disponíveis serão
 * retornados. Útil quando você não sabe o tamanho exato de uma sequência, mas quer pegar apenas
 * uma parte dela.
 *
 * std::views::take_while(): É um *range adaptor* que gera elementos de um range até que uma
 * condição (predicado) retorne falso. A iteração para no primeiro elemento que não satisfaz a
 * condição. Muito bom para quando você precisa iterar sobre um range até que uma condição seja
 * atendida.
 */

int main(int argc, char **argv)
{
    std::cout << '\n';

    // Exemplo de sequência infinita (1'000'000 até 1'000'009)
    for (int i : std::views::iota(1'000'000, 1'000'010))
    {
        std::cout << i << ' ';
    }
    std::cout << "\n";

    std::cout << "-------------------------------------------\n";

    // Exemplo de take(10): Pega os primeiros 10 elementos de uma sequência
    for (int i : std::views::iota(1'000'000) | std::views::take(10))
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    std::cout << "-------------------------------------------\n";

    // Exemplo de take_while: Pega elementos enquanto o predicado for verdadeiro
    for (int i : std::views::iota(1'000'000) | std::views::take_while([](auto i)
    {
        return i < 1'000'010; 
    }))
    {
        std::cout << i << ' ';
    }

    /**
     * @note A notação 1'000'000 em C++ é uma forma legível de escrever números grandes.
     * Esse apóstrofo (') é chamado de separador de dígitos e foi introduzido no C++14.
     * 1'000'000 é o mesmo que 1000000. Pode-se se usar em flutuantes também 3.141'592'653.
     *
     * Importante:
     * - É apenas sintaxe: 1'000'000 == 1000000 é verdadeiro.
     * - O compilador ignora os apóstrofos, mas eles ajudam a evitar erros de leitura e digitação.
     * - O separador ' não afeta o valor numérico, apenas melhora a legibilidade do código para
     * humanos, assim como usamos vírgulas ou pontos em números grandes na escrita comum
     * (por exemplo, "1.000.000").
     *
     * Quando usar?
     *
     * Grandes constantes: 60'000 milissegundos
     * Tamanhos de memória: 1'048'576 bytes (1 MB)
     * ID's grandes, dados financeiros, etc.
     */
    return 0;
}

#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * std::out_of_range:
 * ------------------
 * Exceção lançada quando uma operação tenta **acessar um elemento fora dos limites válidos**
 * de um contêiner, como `std::vector`, `std::array` ou `std::string`.
 *
 * Diferente de `std::length_error`, que ocorre na **criação ou redimensionamento** de objetos,
 * `std::out_of_range` está relacionada a **acessos inválidos** em tempo de execução.
 *
 * Exemplos de ocorrência:
 *  - Acessar um índice inexistente em um vetor (`vector.at(10)` quando o vetor tem 5 elementos).
 *  - Obter um caractere além do final de uma string.
 *  - Qualquer tentativa de acessar dados **fora do intervalo permitido** de um contêiner.
 *
 * Em resumo: `std::out_of_range` sinaliza **erros de acesso**, quando um índice ou posição
 * ultrapassa os **limites válidos** definidos pela estrutura de dados.
 */

/**
 * @brief Teste 1: Acesso a um elemento fora do intervalo de um array C-style.
 *
 * @note O acesso a um elemento fora do intervalo de um array C-style não lança uma exceção,
 * mas pode causar comportamento indefinido. O programa pode acessar um valor aleatório ou
 * pode falhar. Isso é diferente do que acontece com std::vector, onde o acesso a um
 * elemento fora do intervalo lança uma exceção std::out_of_range.
 */
void testeArrayCStyle(void)
{
    std::cout << "===== Teste 1: Array C-style =====\n";

    try
    {
        int arr[5] = {10, 20, 30, 40, 50};
        std::cout << "Valor em arr[5]: " << arr[5] << '\n'; // Não lança exceção
    }
    catch (...)
    {
        std::cerr << "[Array] Exceção capturada (isso normalmente não acontece aqui)\n";
    }
}

/**
 * @brief Teste 2: Acesso a um elemento fora do intervalo de um std::vector usando o operador [].
 *
 * @note O operador [] não lança uma exceção, mas pode causar comportamento indefinido.
 * O programa pode acessar um valor aleatório ou pode falhar. Isso é diferente do que acontece
 * com std::vector::at(), onde o acesso a um elemento fora do intervalo lança uma exceção
 * std::out_of_range.
 */
void testeVectorComColchetes(void)
{
    std::cout << "\n===== Teste 2: std::vector com operador [] =====\n";

    try
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        std::cout << "Valor em v[5]: " << v[5] << '\n'; // Acesso inválido, sem exceção
    }
    catch (...)
    {
        std::cerr << "[vector[]] Exceção capturada (isso normalmente não acontece aqui)\n";
    }
}

/**
 * @brief Teste 3: Acesso a um elemento fora do intervalo de um std::vector usando at().
 *
 * @note O método at() lança uma exceção std::out_of_range se o índice estiver
 * fora do intervalo. Isso é útil para evitar acessos inválidos e comportamentos indefinidos.
 * O uso de at() é recomendado quando se deseja garantir a segurança do acesso aos elementos
 * de um vetor.
 */
void testeVectorComAt(void)
{
    std::cout << "\n===== Teste 3: std::vector com .at() =====\n";

    try
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        std::cout << "Valor em v.at(2): " << v.at(2) << '\n'; // Válido
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Erro inesperado: " << e.what() << '\n';
    }
}

int main(int argc, char **argv)
{
    std::cout << "\n===== Exceções Lógicas: std::out_of_range =====\n";
    testeArrayCStyle();
    testeVectorComColchetes();
    testeVectorComAt();
    return 0;
}

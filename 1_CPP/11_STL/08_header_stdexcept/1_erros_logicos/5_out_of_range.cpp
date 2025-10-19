#include <iostream>
#include <vector>
#include <stdexcept>

/**
 * std::out_of_range(): Essa exceção é lançada quando um valor está fora do intervalo esperado.
 * Exemplo: Acessar um elemento fora dos limites de um vetor.
 * Acesso a índice inválido em array/vector/etc.
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

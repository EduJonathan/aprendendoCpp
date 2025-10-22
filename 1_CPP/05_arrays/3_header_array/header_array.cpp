#include <iostream>
#include <iomanip>
#include <array>

/**
 * A partir do C++11, a linguagem oferece o std::array como uma alternativa mais segura,
 * moderna e com melhor interoperabilidade com a STL (Standard Template Library) em relação
 * aos arrays tradicionais estilo C.
 *
 * Arrays Tradicionais (C-style) [int arr[5]]:
 * - Blocos de memória contíguos e fixos
 * - Não conhecem seu tamanho (Calculado com sizeof(arr)/sizeof(arr[0]))
 * - Sem verificação de limites
 * - Decaem facilmente para ponteiro (int*)
 *
 * std::array [std::array<int, 5> arr]:
 * - Container estático da STL de tamanho fixo, porém (conhecido em tempo de compilação)
 * - Reconhece seu próprio tamanho (.size())
 * - Verificação de limites (.at())
 * - Não decai para ponteiro automaticamente
 * - Interface rica com iteradores e algoritmos STL
 * - Sem overhead de performance quando otimizado
 * - Mesma performance que array C-style
 *
 * std::array é uma classe de array que oferece funcionalidades adicionais
 * como verificação de limites e tamanho fixo já em tempo de compilação,
 * chame-a através do header <array>.
 */

int main(int argc, char **argv)
{
    // Declaração e inicialização de um std::array com 5 elementos
    std::array<int, 5> cpp_array = {10, 20, 30, 40, 50};

    std::cout << "[std::array]\n";

    // Tamanho do array, .size() e .max_size() retornam o mesmo valor
    std::cout << "Tamanho (.size()): " << cpp_array.size() << " elementos\n";
    std::cout << "Tamanho (.max_size()): " << cpp_array.max_size() << " elementos\n\n";

    std::cout << "Valores e endereços:\n";
    for (std::size_t i = 0; i < cpp_array.size(); ++i)
    {
        std::cout << "  cpp_array[" << i << "] = "
                  << std::setw(2) << cpp_array[i]
                  << " | Endereço: " << &cpp_array[i] << '\n';
    }
    std::cout << "Endereço base do container: " << cpp_array.data() << '\n';

    std::cout << "\n[Iteração com range-based for]\n  ";
    for (auto valor : cpp_array)
        std::cout << valor << ' ';
    std::cout << '\n';

    std::cout << "--------------------------------\n";

    // Declaração de um std::array com 5 elementos
    std::array<int, 5> array2 = {1, 2, 3, 4, 5}; // É igual a declaração: int array2[5];
    std::size_t size2 = array2.size();           // Obtendo o tamanho do std::array
    std::size_t index2 = 4ull;

    if (index2 < size2)
    {
        // Usando o método .at() para acessar elementos com verificação de limites
        std::cout << "Valor no índice " << index2 << ": " << array2.at(index2) << '\n';
    }
    else
    {
        std::cout << "Erro: Índice fora dos limites do array!" << '\n';
    }
    return 0;
}

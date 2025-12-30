#include <iostream>
#include <array>

int main(int argc, char const **argv)
{
    std::array<int, 10> valores{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int valor_selecionado = 0;
    int valor_buscado = 5;

    int indice_selecionado = -1;
    int indice_buscado = -1;

    // procura os índices manualmente
    for (std::size_t i = 0; i < valores.size(); ++i)
    {
        if (valores[i] == valor_selecionado)
        {
            indice_selecionado = static_cast<int>(i);
        }
        if (valores[i] == valor_buscado)
        {
            indice_buscado = static_cast<int>(i);
        }
    }

    if (indice_selecionado == -1 || indice_buscado == -1)
    {
        std::cout << "Valor não encontrado.\n";
        return 1;
    }

    int distancia = indice_buscado - indice_selecionado;

    std::cout << "O valor " << valor_buscado
              << " está a " << distancia
              << " casas/passos de " << valor_selecionado << ".\n";

    std::cout << "-------------------------------------------" << '\n';

    std::array<int, 8> arr{10, 3, 2, 10, 2, 8, 8, 7};

    // CalcularXOR de todos os elementos
    int xor_all = arr[0];
    for (std::size_t i = 1; i < arr.size(); ++i)
    {
        xor_all ^= arr[i];
    }

    // Encontrar o bit mais à direita que está ligado(1)
    // Isolando o bit menos significativo diferente entre os dois números ímpares
    int rightmost_set_bit = xor_all & -xor_all; // Ou usando: xor_all & (~xor_all - 1);

    // Dividir os números em dois grupos com base nesse bit e fazer XOR em cada grupo
    int num1 = 0, num2 = 0;

    for (int num : arr)
    {
        if (num & rightmost_set_bit)
        {
            num1 ^= num; // Grupo1 com o bit definido
        }
        else
        {
            num2 ^= num; // Grupo2 sem o bit definido
        }
    }

    std::cout << "Os dois números ímpares são: " << num1 << " e " << num2 << '\n';

    return 0;
}

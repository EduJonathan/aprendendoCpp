#include "class_array.hpp"
#include <iostream>

bool Array::isValid(const std::unique_ptr<int[]> &arr, std::size_t size)
{
    if (!arr)
    {
        std::cerr << "Array não foi alocado corretamente!" << '\n';
        return false;
    }
    return true;
}

std::unique_ptr<int[]> Array::criarArray(std::size_t size)
{
    if (size <= 0)
    {
        std::cout << "Tamanho inválido para o array!" << '\n';
        return nullptr; // Se o tamanho for inválido, retornamos nullptr
    }

    // Cria o array usando unique_ptr
    auto arr = std::make_unique<int[]>(size);

    // Inicializa o array com 0
    std::fill(arr.get(), arr.get() + size, 0);
    return arr;
}

bool Array::insertValue(std::unique_ptr<int[]> &arr, std::size_t size, std::size_t index, double value)
{
    // Verifica se o índice está dentro do intervalo válido
    if (index < 0 || index >= size)
    {
        std::cerr << "Erro: Índice " << index << " fora dos limites do array!" << '\n';
        return false;
    }

    // Simula um erro, pois 'value' não é um inteiro
    if (static_cast<int>(value) != value)
    {
        std::cerr << "Erro: O valor " << value << " não é um inteiro!" << '\n';
        return false;
    }

    arr[index] = static_cast<int>(value); // Armazena como inteiro (cast)
    return true;
}

void Array::printArray(const std::unique_ptr<int[]> &arr, std::size_t size)
{
    if (!arr)
    {
        std::cerr << "Array não alocado!" << '\n';
        return;
    }

    std::cout << "Conteúdo do array: ";
    std::cout << "[";
    for (std::size_t i = 0ull; i < size; ++i)
    {
        std::cout << arr[i]; // Exibe o valor de cada elemento

        if (i < size - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << ']' << '\n';
}

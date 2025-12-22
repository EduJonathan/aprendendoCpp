#include "class_array.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Array array;

    // Cria o array com 5 elementos
    std::size_t size = 5ull;
    auto criar_array = array.criarArray(size);

    if (!array.isValid(criar_array, size))
    {
        return 1; // Se não conseguiu alocar, termina o programa
    }

    // Exibindo o conteúdo do array que será criado inicialmente.
    array.printArray(criar_array, size);

    // Inserindo alguns valores no array
    if (array.insertValue(criar_array, size, 0, 1))
    {
        std::cout << "Valor 1 inserido com sucesso!" << '\n';
    }

    if (array.insertValue(criar_array, size, 1, 2.0))
    {
        std::cout << "Valor 2 inserido com sucesso!" << '\n';
    }

    if (array.insertValue(criar_array, size, 2, 3))
    {
        std::cout << "Valor 3 inserido com sucesso!" << '\n';
    }

    if (array.insertValue(criar_array, size, 3, 4))
    {
        std::cout << "Valor 4 inserido com sucesso!" << '\n';
    }

    if (array.insertValue(criar_array, size, 4, 5.5))
    {
        std::cout << "Valor 5 inserido com sucesso!" << '\n';
    }

    // Exibindo o conteúdo do array
    array.printArray(criar_array, size);

    // O unique_ptr já vai liberar a memória automaticamente

    /**
     * Compile e execute o programa com:
     * > g++ -std=c++17 .\main_array.cpp .\criar_array.cpp -o nome_do_executavel
     * > .\nome_do_executavel.exe
     */
    return 0;
}

#include <iostream>
#include <type_traits>

// Estruturas para representar os tipos
struct is_pointer {};
struct is_int {};

// Template para determinar se um tipo é um ponteiro
template <typename T>
struct is_Pointer
{
    using type = typename std::conditional<std::is_pointer<T>::value, is_pointer, is_int>::type;
};

// Alias para facilitar o uso do tipo resultante
template <typename T>
using is_Pointer_tag = typename is_Pointer<T>::type;

// Função para imprimir o tipo
template <typename T>
void processar_tipo(T value, is_pointer)
{
    std::cout << "É do tipo ponteiro" << '\n';
}

// Sobrecarga para o caso de ser um tipo inteiro
template <typename T>
void processar_tipo(T value, is_int)
{
    std::cout << "É do tipo inteiro" << '\n';
}

// Função principal que determina o tipo e chama a função apropriada
template <typename T>
void processar_tipo(T value)
{
    processar_tipo(value, is_Pointer_tag<T>{});
}

int main(int argc, char **argv)
{
    int inteiro = 10;
    int *ponteiro = &inteiro;
    processar_tipo(inteiro);
    processar_tipo(ponteiro);
    return 0;
}

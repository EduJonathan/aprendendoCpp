#include <iostream>
#include <cstring>
#include "destrutor_string.hpp"

String::String(const char *str)
{
    std::size_t length = strnlen(str, SIZE); // Determina o comprimento da string.
    string = new char[length + 1];           // Aloca memória para a string.
    std::strncpy(string, str, length + 1);   // Copia a string para o buffer alocado.
}

void String::getString(const std::string &str)
{
    std::size_t length = str.size();               // Obtém o tamanho da nova string.
    delete[] string;                               // Libera a memória da string antiga.
    string = new char[length + 1];                 // Aloca nova memória para a string.
    std::strncpy(string, str.c_str(), length + 1); // Copia a nova string.
}

void String::printString(void) const
{
    std::cout << string << '\n'; // Imprime a string armazenada.
}

String::~String()
{
    delete[] string; // Libera a memória alocada para a string.
}

int main(int argc, char **argv)
{
    String myString("Olá, Mundo!"); // Cria o objeto com a string inicial.
    myString.printString();         // Imprime "Olá, Mundo!"

    // Alterando o conteúdo da string com getString
    std::string newStr = "Adeus, Mundo!";
    myString.getString(newStr); // Atualiza a string interna para "Adeus, Mundo!"
    myString.printString();     // Imprime "Adeus, Mundo!"

    // Quando 'minhaString' sai de escopo, o destruidor é chamado automaticamente
    return 0;
}

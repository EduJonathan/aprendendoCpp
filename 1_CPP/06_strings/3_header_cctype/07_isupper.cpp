#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é uma letra maiúscula
void isUpper(char caractere)
{
    if (std::isupper(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é uma letra maiúscula." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é uma letra maiúscula." << '\n';
    }
}

// Função para verificar se a string contém apenas letras maiúsculas
void isUpperString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isupper(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas letras maiúsculas." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas letras maiúsculas." << '\n';
}

int main(int argc, char **argv)
{
    isUpper('a');
    isUpper('A');
    isUpper('#');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "1234A";
    std::string testStr4 = "123_4A";

    isUpperString(testStr);
    isUpperString(testStr2);
    isUpperString(testStr3);
    isUpperString(testStr4);
    return 0;
}

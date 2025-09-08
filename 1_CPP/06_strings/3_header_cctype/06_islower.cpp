#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é uma letra minúscula
void isLower(char caractere)
{
    if (std::islower(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é uma letra minúscula." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é uma letra minúscula." << '\n';
    }
}

// Função para verificar se a string contém apenas letras minúsculas
void isLowerString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::islower(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas letras minúsculas." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas letras minúsculas." << '\n';
}

int main(int argc, char **argv)
{
    isLower('a');
    isLower('A');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "1234a";
    std::string testStr4 = "abcde";

    isLowerString(testStr);
    isLowerString(testStr2);
    isLowerString(testStr3);
    isLowerString(testStr4);
    return 0;
}

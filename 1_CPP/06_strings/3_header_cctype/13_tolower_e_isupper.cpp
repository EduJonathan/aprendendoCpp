#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é minúsculo
void isLower(char caractere)
{
    if (std::islower(static_cast<unsigned char>(caractere)))
    {
        std::cout << "O caractere '" << caractere << "' é minúsculo.\n";
    }
    else if (std::isupper(static_cast<unsigned char>(caractere)))
    {
        std::cout << "O caractere '" << caractere << "' é maiúsculo.\n";
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' não é uma letra.\n";
    }
}

// Função para verificar se a string contém apenas letras minúsculas
void isLowerString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::islower(static_cast<unsigned char>(c)))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas caracteres minúsculos.\n";
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas caracteres minúsculos.\n";
}

int main(int argc, char **argv)
{
    isLower('a');
    isLower('B');
    isLower('\t');
    isLower('\n');

    std::string testStr = "aCv";
    std::string testStr2 = "abcde";
    std::string testStr3 = "1234\tA";
    std::string testStr4 = "abcd";

    isLowerString(testStr);
    isLowerString(testStr2);
    isLowerString(testStr3);
    isLowerString(testStr4);

    return 0;
}

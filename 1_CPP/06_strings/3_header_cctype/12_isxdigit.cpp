#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é um dígito hexadecimal
void isXDigit(char caractere)
{
    if (std::isxdigit(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é um dígito hexadecimal." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é um dígito hexadecimal." << '\n';
    }
}

// Função para verificar se a string contém apenas dígitos hexadecimais
void isXDigitString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isxdigit(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas dígitos hexadecimais." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas dígitos hexadecimais." << '\n';
}

int main(int argc, char **argv)
{
    isXDigit('1');
    isXDigit('f');
    isXDigit('#');

    std::string testStr = "12345";
    std::string testStr2 = "abcdef";
    std::string testStr3 = "0x0800";

    isXDigitString(testStr);
    isXDigitString(testStr2);
    isXDigitString(testStr3);
    return 0;
}

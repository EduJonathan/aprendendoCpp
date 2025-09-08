#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é uma letra (alfabético)
void isAlpha(char caractere)
{
    if (std::isalpha(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é uma letra." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é uma letra." << '\n';
    }
}

// Função para verificar se a string é composta apenas por letras (alfabéticas)
void isAlphaString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isalpha(c))
        {
            std::cout << "A string \"" << str << "\" NÃO é composta apenas por letras." << '\n';
            return;
        }
    }    
    std::cout << "A string \"" << str << "\" é composta apenas por letras." << '\n';
}

int main(int argc, char **argv)
{
    isAlpha('a');
    isAlpha('1');
    isAlpha('#');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "1234A";
    std::string testStr4 = "123_4A";

    isAlphaString(testStr);
    isAlphaString(testStr2);
    isAlphaString(testStr3);
    isAlphaString(testStr4);
    return 0;
}

#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é um espaço (qualquer tipo de espaço em branco)
void isSpace(char caractere)
{
    if (std::isspace(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é um espaço em branco." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é um espaço em branco." << '\n';
    }
}

// Função para verificar se a string contém apenas espaços (ou caracteres em branco)
void isSpaceString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isspace(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas espaços em branco." << '\n';
            return;
        }
    }    
    std::cout << "A string \"" << str << "\" contém apenas espaços em branco." << '\n';
}

int main(int argc, char **argv)
{
    isSpace('a');
    isSpace('1');
    isSpace('\t');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "1234A";
    std::string testStr4 = " ";

    isSpaceString(testStr);
    isSpaceString(testStr2);
    isSpaceString(testStr3);
    isSpaceString(testStr4);
    return 0;
}

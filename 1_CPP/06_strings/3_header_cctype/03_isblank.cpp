#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é um espaço em branco ou tabulação
void isBlank(char caractere)
{
    if (std::isblank(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é um espaço em branco ou tabulação." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é um espaço em branco ou tabulação." << '\n';
    }
}

// Função para verificar se a string contém espaços ou tabulação
void isBlankString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::isblank(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas espaços ou tabulação." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas espaços ou tabulação." << '\n';
}

int main(int argc, char **argv)
{
    isBlank('a');
    isBlank('1');
    isBlank('#');
    isBlank(' ');

    std::string testStr = "12345";
    std::string testStr2 = "ABCDE";
    std::string testStr3 = "1234A";
    std::string testStr4 = " \t";

    isBlankString(testStr);
    isBlankString(testStr2);
    isBlankString(testStr3);
    isBlankString(testStr4);
    return 0;
}

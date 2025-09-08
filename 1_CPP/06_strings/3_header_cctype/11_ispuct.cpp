#include <iostream>
#include <string>
#include <cctype>

// Função para verificar se o caractere é um caractere de pontuação
void isPunct(char caractere)
{
    if (std::ispunct(caractere))
    {
        std::cout << "O caractere '" << caractere << "' é um caractere de pontuação." << '\n';
    }
    else
    {
        std::cout << "O caractere '" << caractere << "' NÃO é um caractere de pontuação." << '\n';
    }
}

// Função para verificar se a string contém apenas caracteres de pontuação
void isPunctString(const std::string &str)
{
    for (char c : str)
    {
        if (!std::ispunct(c))
        {
            std::cout << "A string \"" << str << "\" NÃO contém apenas caracteres de pontuação." << '\n';
            return;
        }
    }
    std::cout << "A string \"" << str << "\" contém apenas caracteres de pontuação." << '\n';
}

int main(int argc, char **argv)
{
    isPunct('a');
    isPunct('1');
    isPunct('!');
    isPunct('\"');

    std::string testStr = "12345?";
    std::string testStr2 = "ABCDE.";
    std::string testStr3 = "1234A;";
    std::string testStr4 = "\'\'!";

    isPunctString(testStr);
    isPunctString(testStr2);
    isPunctString(testStr3);
    isPunctString(testStr4);
    return 0;
}
